# qzip

![qzip](ZIP-v1.9.png?raw=true "InfoZIP ZIP v1.9 1992")

# How to build
You need `qdos-gcc' compiler installed on your system.

To make QL binary:  
$ make clean  
$ make qdos

To make Linux binary:  
$ make clean  
$ make linux

# How to install on QL  
You need to set dataspace and file type '1' for the binary.  
Dataspace is reported by the compiler.

# QL usage

To compress whole mdv2_ and create foo_zip in ram1_  
ex zip;'-rb ram1_ ram1_foo mdv2_'  
 `r' = recursive  
 `b' = temporary dir ram1_   

To compress all BASIC files in mdv2_, and create foo_zip in ram2_  
ex zip;'-jb ram1_ ram2_foo mdv2_*bas'  
 `j' = junk path names, mdv2_...  

