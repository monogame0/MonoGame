# Makefile
main : src\main.c commandline.o
	gcc commandline.o src\main.c -o bin\main.exe
commandline.o : src\commandline.c include\commandline.h
	gcc -c src\commandline.c 
.PHONY : clean
clean :
	del main.exe commandline.o