#include "simpleCSVsorter.h"
//#include "simpleCSVsorter.c"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


void Mergesort(Row** table,int low,int high, const char* header){
    if(low < high){
        int mid = (low + high) / 2;
        Mergesort(table, low, mid,header);
        Mergesort(table, mid+1, high,header);
        Merge(table,low, mid,high,header);

        // merge(target, det, rowtable, low, high, mid);
    }
}

void Merge(Row** table,int low,int mid,int high, const char* header){
    int mergedSize = high - low +1;
    Row **temp = (Row **)malloc(mergedSize * sizeof(Row*));
    int mergePos = 0;
    int leftPos = low;
    int rightPos = mid + 1;
    
    while(leftPos <= mid && rightPos <= high){
	if(strcmp(header, "color") == 0) {
            if (strcmp(table[leftPos].color, table[rightPos].color) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "director_name") == 0) {
            if (strcmp(table[leftPos].director_name, table[rightPos].director_name) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "num_critic_for_reviews") == 0) {
            if (table[leftPos].num_critic_for_reviews < table[rightPos].num_critic_for_reviews){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "duration") == 0) {
            if (table[leftPos].duration < table[rightPos].duration){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "director_facebook_likes") == 0) {
            if (table[leftPos].director_facebook_likes < table[rightPos].director_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "actor_3_facebook_likes") == 0) {
            if (table[leftPos].actor_3_facebook_likes < table[rightPos].actor_3_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "actor_2_name") == 0) {
            if (strcmp(table[leftPos].actor_2_name, table[rightPos].actor_2_name) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "actor_1_facebook_likes") == 0) {
            if (table[leftPos].actor_1_facebook_likes < table[rightPos].actor_1_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "gross") == 0) {
              if (table[leftPos].gross < table[rightPos].gross){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "genres") == 0) {
            if (strcmp(table[leftPos].genres, table[rightPos].genres) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "actor_1_name") == 0) {
            if (strcmp(table[leftPos].actor_1_name, table[rightPos].actor_1_name) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "movie_title") == 0) {
            if (strcmp(table[leftPos].movie_title, table[rightPos].movie_title) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "num_voted_users") == 0) {
            if (table[leftPos].num_voted_users < table[rightPos].num_voted_users){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "cast_total_facebook_likes") == 0) {
            if (table[leftPos].cast_total_facebook_likes < table[rightPos].cast_total_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "actor_3_name") == 0) {
            if (strcmp(table[leftPos].actor_3_name, table[rightPos].actor_3_name) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "facenumber_in_poster") == 0) {
            if (table[leftPos].facenumber_in_poster < table[rightPos].facenumber_in_poster){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "plot_keywords") == 0) {
            if (strcmp(table[leftPos].plot_keywords, table[rightPos].plot_keywords) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "movie_imdb_link") == 0) {
            if (strcmp(table[leftPos].movie_imdb_link, table[rightPos].movie_imdb_link) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "num_user_for_reviews") == 0) {     
            if (table[leftPos].num_user_for_reviews < table[rightPos].num_user_for_reviews){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "language") == 0) {
            if (strcmp(table[leftPos].language, table[rightPos].language) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "country") == 0) {
            if (strcmp(table[leftPos].country, table[rightPos].country) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "content_rating") == 0) {
            if (strcmp(table[leftPos].content_rating, table[rightPos].content_rating) < 0){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }
    	}
    	else if(strcmp(header, "budget") == 0) {       
            if (table[leftPos].budget < table[rightPos].budget){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }   
    	}
    	else if(strcmp(header, "title_year") == 0) {       
            if (table[leftPos].title_year < table[rightPos].title_year){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }   
    	}
    	else if(strcmp(header, "actor_2_facebook_likes") == 0) {       
            if (table[leftPos].actor_2_facebook_likes < table[rightPos].actor_2_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }  
    	}
    	else if(strcmp(header, "imdb_score") == 0) {
            if (table[leftPos].imdb_score < table[rightPos].imdb_score){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }  
    	}
    	else if(strcmp(header, "aspect_ratio") == 0) {
            if (table[leftPos].aspect_ratio < table[rightPos].aspect_ratio){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }  
    	}
    	else if(strcmp(header, "movie_facebook_likes") == 0) {     
            if (table[leftPos].movie_facebook_likes < table[rightPos].movie_facebook_likes){
            	temp[mergePos++] = table[leftPos++];
            }else{
            	temp[mergePos++] = table[rightPos++];
            }  
    	}
    	else{
    	    printf("IMPOSSIBLE HEADER ARGUMENT\n");
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