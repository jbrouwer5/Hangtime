# Makefile for CS152 lab9 Spring 2021

.PHONY : clean

htbl: htbl.[hc] bucket.c main.c
	clang -lm -g -Wall -o htbl bucket.c htbl.c main.c

clean:
	rm -rf htbl *.dSYM
