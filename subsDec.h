/* FILE:          SUBSDEC.H
 * WRITTEN BY:    MICHAEL GIANCOLA
 * CREATED ON:    08/06/2015
 * LAST MODIFIED: 08/06/2015
 * DESCRIPTION:   HEADER FILE FOR SUBSDEC.C
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> //For tolower(c) macro

#ifndef SUBSDEC_H
#define SUBSDEC_H

//Function Prototypes
void freqAnalysis(FILE* in, FILE* out, char* table);
void caesar(FILE* in, FILE* out, int rotate);
char getCharacter();
void flushInput();
int indexOf(char* arr, int size, char val);
int findHighest(int* arr, int size);

#endif
