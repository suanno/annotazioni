# C Makefile prototype
Copy this folder to start a new project
    
    cp -r makefile\ prototype/ newproject

In /main/Makefile you have to tell what programs (main) to compile and what custom libraries, contained in /modules (and /include for the header/function declaration) to link.

In /include the file "global.h" contains the constants. You have to include it in _any ".c" file_ you want to use the constants, with all the libraries you need to use in that ".c" file.

It does not work to "include only in the main" a function that you need to use in a module.
You need to include it into the module.

In the header files (".h") you only declare your custom functions. Do not include anything (you have to include things only in the ".c" files where you need them).