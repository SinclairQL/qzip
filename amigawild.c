/*
 * Public Domain Amiga Wild Card Expansion
 * © Jonathan Hudson March '94
 */

#include <exec/exec.h>
#include <dos/dosextens.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/alib_protos.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define MAXARGS 2048

extern struct DosLibrary *DOSBase;

extern int WildCards (int *pac, char ***pav);

static int ParseWild(char *pattern, int ac, char **av)
{
    long error;
    struct AnchorPath *ap;
    char * tmp ;


/*
 * Commodore get 5/10 for _almost_ getting * wildcards right this time
 */
 
    if(strchr(pattern, '*'))
    {
        char *p;
        
        tmp = alloca(512);

        for (p = tmp; *pattern; pattern++)
        {
            if(*pattern == '*')
            {
                *p++ = '#';
                *p++ = '?';
            }
            else
            {
                *p++ = *pattern;
            }
        }
        *p = 0;
        pattern = tmp;
    }
    ap =  AllocMem (sizeof (struct AnchorPath) + 512, MEMF_CLEAR);
    if (ap)
    {
        ap->ap_Strlen = 512;
        ap->ap_BreakBits = SIGBREAKF_CTRL_C;

        if ((error = MatchFirst (pattern, ap)) == 0)
        {
            do
	    {
		av[ac++] = strdup (ap->ap_Buf);
	    }
	    while ((error = MatchNext (ap)) == 0);
	}
	else
	{
            av[ac++] = strdup (pattern);
	}

	MatchEnd (ap);
        FreeMem (ap, sizeof (struct AnchorPath) + 512);
    }
    return ac;
}
int WildCards (int *pac, char ***pav)
{
    char **av;
    int ac;

    if (DOSBase->dl_lib.lib_Version < 37)
    {
	fprintf (stderr, "You must have Kickstart 2.04 (V37) or higher!\n");
	exit (20);
    }

    ac = 0;
    av = malloc (MAXARGS * sizeof (char *));

    if (av == NULL)
	return 0;

    av[0] = *(*pav)++;
    ac = 1;
    for (; --(*pac); (*pav)++)
    {
	if (***pav == '-' || ***pav == '+')
	{
            av[ac++] = **pav;
	}
	else
	{
	    ac = ParseWild (**pav, ac, av);
	}
    }

    av[ac] = NULL;
    realloc (av, ac * sizeof (char *));

    *pac = ac;
    *pav = av;

    return ac;
}


#ifdef TEST
int main (int ac, char **av)
{
    int n;

    printf("Orignal No Args %d\n", ac);

    n = WildCards(&ac, &av);
    printf("Expanded Args %d\n", ac);

    while(ac--)
    {
        puts(*av++);
    }
    return 0;
}
#endif

