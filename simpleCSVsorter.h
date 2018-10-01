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
char* trim(char *token);
int validColumn(const char * col);
int findMovieIndex(char* headers[],int num_columns);
int searchForField(char* headers[],int num_columns, const char* fieldName);
void printTable(Row **table,char* headers[], int num_columns, int num_rows,int movieIndex);
int getDataType(const char * col);
void Merge(Row** table,int low,int mid,int high, int header,int dataType);
void Mergesort(Row** table,int low,int high, int header, int dataType);

//Suggestion: prototype a mergesort function
#endif