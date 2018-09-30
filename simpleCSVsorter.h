#ifndef simpleCSVsorter
#define simpleCSVsorter
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
/*****
*
*	Define structures and function prototypes for your sorter
*
*
*
******/

typedef struct _row{
    int columns;
    char* columnValues[];
} Row;

//Suggestion: define a struct that mirrors a record (row) of the data set


//Suggestion: prototype a mergesort function
#endif