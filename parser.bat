echo off

rem *** Asegurarse de que Bison pueda encontrar los ficheros
move d:\programacion\c\lib\bison\bison.simple . >nul
move d:\programacion\c\lib\bison\bison.hairy  . >nul

rem *** Ejecutar Bison
d:\programacion\c\lib\bison\bison --defines --verbose -o .\Scripting\parse.cpp .\Scripting\string.y

rem *** Restaurar ficheros
move bison.simple d:\programacion\c\lib\bison\ >nul
move bison.hairy d:\programacion\c\lib\bison\ >nul

rem *** Renombrarparse.cpp.h a lexsymb.h
rem  cd Scripting
rem if exist lexsymb.h del lexsymb.h
rem ren parse.cpp.h  lexsymb.h

:End
