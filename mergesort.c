#include "simpleCSVsorter.h"
//#include "simpleCSVsorter.c"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/*
Params: table - An array of string arrays that stores the csv file in the form of multiple 1d arrays
        low - The first index in the array
        mid - The middle point of the array
        high - The last index in the array
        header - the index of the column you want to sort
        dataType - an integer that represents the type of data you want to sort
            |__0 = string
            |__1 = integer
            |__2 = double
Returns: VOID -    joins the two arrays together
*/
void Merge(Row** table,int low,int mid,int high, int header,int dataType){
    int mergedSize = high - low +1;
    Row **temp = (Row **)malloc(mergedSize * sizeof(Row*));
    int mergePos = 0;
    int leftPos = low;
    int rightPos = mid + 1;
    
    while(leftPos <= mid && rightPos <= high){
        //IF STRING = 0
	    if(dataType == 0) {
            if (strcmp(trim(table[leftPos] -> columnValues[header]),trim(table[rightPos] -> columnValues[header])) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
        // IF INTEGER = 1
    	else if(dataType == 1) {
            if (atoi(table[leftPos] -> columnValues[header]) < atoi(table[rightPos] -> columnValues[header])){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
        //IF DOUBLE = 2
    	else if(dataType == 2){
            if (atof(table[leftPos] -> columnValues[header]) < atof(table[rightPos] -> columnValues[header])){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
        else{
            printf("SHOULD NEVER REACH HERE");
        }
    }


    while(leftPos <= mid){
        temp[mergePos++] = table[leftPos++];
    }

    while(rightPos <= high){
        temp[mergePos++] = table[rightPos++];
    }

    assert(mergePos == mergedSize);

    for(mergePos = 0; mergePos < mergedSize; ++mergePos){
        table[low + mergePos] = temp[mergePos];
    }

    free(temp); 
}

/*
Params: table - An array of string arrays that stores the csv file in the form of multiple 1d arrays
        low - The first index in the array
        high - The last index in the array
        header - the index of the column you want to sort
        dataType - an integer that represents the type of data you want to sort
            |__0 = string
            |__1 = integer
            |__2 = double
Returns: VOID - sorts the struct row given
*/
void Mergesort(Row** table,int low,int high, int header, int dataType){
    if(low < high){
        int mid = (low + high) / 2;
        Mergesort(table, low, mid,header,dataType);
        Mergesort(table, mid+1, high,header,dataType);
        Merge(table,low, mid,high,header,dataType);

    }
}