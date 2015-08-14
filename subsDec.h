/* FILE:          SUBSDEC.H
 * WRITTEN BY:    MICHAEL GIANCOLA
 * CREATED ON:    08/06/2015
 * LAST MODIFIED: 08/13/2015
 * DESCRIPTION:   HEADER FILE FOR SUBSDEC.C
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> //For tolower(c) macro

#ifndef SUBSDEC_H
#define SUBSDEC_H

//Function Prototypes
void freqAnalysis(FILE* in, FILE* out);
void caesar(FILE* in, FILE* out, int rotate);
char getCharacter();
void flushInput();
int indexOf(char* arr, int size, char val);
void sortAlpha(int* hist, char* alphaArr, int size);
void printTable(char* encoded, char* decoded);
void swap(char* arr, int i1, int i2);

#endif
