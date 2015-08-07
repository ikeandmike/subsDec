all: subsDec

subsDec: subsDec.o
	gcc subsDec.o -o subsDec

subsDec.o: subsDec.c subsDec.h
	gcc -c subsDec.c

clean:
	rm -f subsDec.o subsDec frequency.txt caesar.txt
