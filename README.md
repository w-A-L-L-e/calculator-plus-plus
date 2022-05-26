# Calculator++
A verry simple calculator made using the tools bison++ and flex++. This allows
to make an efficient compiler or parser using c++.

# Installation
Just clone this and then do a make to build it
```
$ make
bison++ -d -o parser.cpp parser.y
c++  -Wall -O2   -c -o parser.o parser.cpp
flex++ -olexer.cpp lexer.l
c++  -Wall -O2   -c -o lexer.o lexer.cpp
c++  -Wall -O2   -c -o main.o main.cpp
c++  -Wall -O2   -c -o Time.o Time.cpp
g++ -o calc -Wall -O2  main.o parser.o lexer.o Time.o
c++  -Wall -O2   -c -o timetest.o timetest.cpp
g++ -o timetest -Wall -O2  timetest.o Time.o 
```

Then you can run it like so (and enter your own formulas):
```
$ ./calc
.------------------------------------------------------.
|                  Simple calculator                   |
|             Author: Walter Schreppers                |
`------------------------------------------------------'
 Give empty line to exit                                
 [a-zA-Z]* specifies a variable name for storing        
 ANS is special variable which always stores last result
 for float expressions add a decimal point in constants 
 start with option --help to see cmdline usage...       
--------------------------------------------------------
2*3+21
27
2*(3+21)
48
b=2*4+1             
c=b*2
c
18
```

