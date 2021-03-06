/*

 Copyright (C) 1990-1992 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 Kai Uwe Rommel and Igor Mandrichenko.
 Permission is granted to any individual or institution to use, copy, or
 redistribute this software so long as all of the original files are included
 unmodified, that it is not sold for profit, and that this copyright notice
 is retained.

*/

/*
 *  revision.h by Mark Adler.
 */

#define REVISION 19
#define PATCHLEVEL 1
#define REVDATE "Aug 26th 1992"

/* Copyright notice for binary executables--this notice only applies to
 * those (zip, zipcloak, zipsplit, and zipnote), not to this file
 * (revision.h).
 */

#ifndef NOCPYRT
char *copyright[] = {
#ifdef VMS
"Copyright (C) 1990-1992 Mark Adler, Richard B. Wales, Jean-loup Gailly,",
"Kai Uwe Rommel and Igor Mandrichenko. Type '%s -L' for the software license.",
#else
"Copyright (C) 1990-1992 Mark Adler, Richard B. Wales, Jean-loup Gailly",
"and Kai Uwe Rommel. Type '%s -L' for the software License.",
#endif
};
char *disclaimer[] = {
"",
"Permission is granted to any individual or institution to use, copy, or",
"redistribute this executable so long as it is not modified and that it is",
"not sold for profit.",
"",
"LIKE ANYTHING ELSE THAT'S FREE, ZIP AND ITS ASSOCIATED UTILITIES ARE",
"PROVIDED AS IS AND COME WITH NO WARRANTY OF ANY KIND, EITHER EXPRESSED OR",
"IMPLIED. IN NO EVENT WILL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DAMAGES",
"RESULTING FROM THE USE OF THIS SOFTWARE."
};
#endif /* !NOCPYRT */

