#DEFINES   += -D_DEBUG_
CPPFLAGS  = -Wall -O2 $(DEFINES)
CPP	  = g++

all: calc timetest

timetest: Time.o timetest.o
	$(CPP) -o timetest $(CPPFLAGS) timetest.o Time.o 

#os x uses libl.a for flex
# cd /usr/lib and then ln -s libl.a libfl.a
calc: parser.o lexer.o main.o Time.o
	$(CPP) -o calc $(CPPFLAGS) main.o parser.o lexer.o Time.o

lexer.cpp: lexer.l
	flex++ -olexer.cpp lexer.l

parser.cpp: parser.y
	bison++ -d -o parser.cpp parser.y


install:
	cp calc /home/wschrep/bin/

clean:
	rm -f *~ *.o lexer.cpp parser.cpp calc timetest
