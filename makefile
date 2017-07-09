test : test.o adt.o 
	gcc -o test test.o adt.o
test.o : test.c adt.h
	gcc -c test.c
adt.o : adt.c adt.h
	gcc -c adt.c

clean :
	rm test test.o adt.o