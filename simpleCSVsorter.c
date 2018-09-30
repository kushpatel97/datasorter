#include "simpleCSVsorter.h"
#include "mergesort.c"
#define BUFFER_SIZE 1024
// #define TABLE_SIZE 5045

int validColumn(const char * col){
    if(strcmp(col, "color") == 0) {
        return 0;
    }
    else if(strcmp(col, "director_name") == 0) {
        return 1;
    }
    else if(strcmp(col, "num_critic_for_reviews") == 0) {
        return 2;
    }
    else if(strcmp(col, "duration") == 0) {
        return 3;
    }
    else if(strcmp(col, "director_facebook_likes") == 0) {
        return 4;
    }
    else if(strcmp(col, "actor_3_facebook_likes") == 0) {
        return 5;
    }
    else if(strcmp(col, "actor_2_name") == 0) {
        return 6;
    }
    else if(strcmp(col, "actor_1_facebook_likes") == 0) {
        return 7;
    }
    else if(strcmp(col, "gross") == 0) {
        return 8;
    }
    else if(strcmp(col, "genres") == 0) {
        return 9;
    }
    else if(strcmp(col, "actor_1_name") == 0) {
        return 10;
    }
    else if(strcmp(col, "movie_title") == 0) {
        return 11;
    }
    else if(strcmp(col, "num_voted_users") == 0) {
        return 12;
    }
    else if(strcmp(col, "cast_total_facebook_likes") == 0) {
        return 13;
    }
    else if(strcmp(col, "actor_3_name") == 0) {
        return 14;
    }
    else if(strcmp(col, "facenumber_in_poster") == 0) {
        return 15;
    }
    else if(strcmp(col, "plot_keywords") == 0) {
        return 16;
    }
    else if(strcmp(col, "movie_imdb_link") == 0) {
        return 17;
    }
    else if(strcmp(col, "num_user_for_reviews") == 0) {     
        return 18;
    }
    else if(strcmp(col, "language") == 0) {
        return 19;
    }
    else if(strcmp(col, "country") == 0) {
        return 20;
    }
    else if(strcmp(col, "content_rating") == 0) {
        return 21;
    }
    else if(strcmp(col, "budget") == 0) {       
        return 22;
    }
    else if(strcmp(col, "title_year") == 0) {       
        return 23;
    }
    else if(strcmp(col, "actor_2_facebook_likes") == 0) {       
        return 24;
    }
    else if(strcmp(col, "imdb_score") == 0) {
        return 25;
    }
    else if(strcmp(col, "aspect_ratio") == 0) {
        return 26;
    }
    else if(strcmp(col, "movie_facebook_likes") == 0) {     
        return 27;
    }
    else{
        // printf("Column name does not exist\n");
        return -1;
    }    
}
void trim(char *str) {
	int i;
	int begin = 0;
	int end = strlen(str) - 1;
	while (isspace((unsigned char) str[begin])) {
		begin++;
	}
	while ((end >= begin) && isspace((unsigned char) str[end])) {
		end--;
	}
	// Shift all chars back to the start of the string array
	for (i = begin; i <= end; i++) {
		str[i - begin] = str[i];
	}
	str[i - begin] = '\0'; // Null terminate string
}

int findMovieIndex(char* headers[],int num_columns){
    int i;
    for(i=0; i < num_columns; i++){
        if(strcmp(headers[i],"movie_title") == 0){
            return i;
        }
    }
    return -1;
}

int searchForField(char* headers[],int num_columns, const char* fieldName){
    int i=0;
    while(i < num_columns){
        if(strcmp(headers[i],fieldName) == 0){
            // printf("[SORTING %d]: %s\n",i,headers[i]);
            return i;
        }
        i++;
    }
    return -1;
}

void printTable(Row **table,char* headers[], int num_columns, int num_rows,int movieIndex){
    //************ "i" indicates number of rows ************    
    //************ "j" indicates number of columns ************

    int k;
    for(k=0; k<num_columns;k++){
        if(k == (num_columns-1)){
            printf("%s",headers[k]);
        }
        else{
            printf("%s,",headers[k]);
        }
        
    }
    int i,j;
    for(i=0; i < num_rows;i++){
        for(j=0; j < num_columns; j++){
            if(j == num_columns-1){
                printf("%s",table[i] -> columnValues[j]);
            }
            else if(j==movieIndex){
                printf("\"%s\",",table[i] -> columnValues[j]);
            }
            else{
                printf("%s,",table[i] -> columnValues[j]);
            }
        }
        printf("\n");
    }

}

/*
    0 = String
    1 = Int
    2 = Double
*/
int getDataType(const char * col){
    if(strcmp(col, "color") == 0) {
        return 0;
    }
    else if(strcmp(col, "director_name") == 0) {
        return 0;
    }
    else if(strcmp(col, "num_critic_for_reviews") == 0) {
        return 1;
    }
    else if(strcmp(col, "duration") == 0) {
        return 1;
    }
    else if(strcmp(col, "director_facebook_likes") == 0) {
        return 1;
    }
    else if(strcmp(col, "actor_3_facebook_likes") == 0) {
        return 1;
    }
    else if(strcmp(col, "actor_2_name") == 0) {
        return 0;
    }
    else if(strcmp(col, "actor_1_facebook_likes") == 0) {
        return 1;
    }
    else if(strcmp(col, "gross") == 0) {
        return 2;
    }
    else if(strcmp(col, "genres") == 0) {
        return 0;
    }
    else if(strcmp(col, "actor_1_name") == 0) {
        return 0;
    }
    else if(strcmp(col, "movie_title") == 0) {
        return 0;
    }
    else if(strcmp(col, "num_voted_users") == 0) {
        return 1;
    }
    else if(strcmp(col, "cast_total_facebook_likes") == 0) {
        return 1;
    }
    else if(strcmp(col, "actor_3_name") == 0) {
        return 0;
    }
    else if(strcmp(col, "facenumber_in_poster") == 0) {
        return 1;
    }
    else if(strcmp(col, "plot_keywords") == 0) {
        return 0;
    }
    else if(strcmp(col, "movie_imdb_link") == 0) {
        return 0;
    }
    else if(strcmp(col, "num_user_for_reviews") == 0) {     
        return 1;
    }
    else if(strcmp(col, "language") == 0) {
        return 0;
    }
    else if(strcmp(col, "country") == 0) {
        return 0;
    }
    else if(strcmp(col, "content_rating") == 0) {
        return 0;
    }
    else if(strcmp(col, "budget") == 0) {       
        return 2;
    }
    else if(strcmp(col, "title_year") == 0) {       
        return 1;
    }
    else if(strcmp(col, "actor_2_facebook_likes") == 0) {       
        return 1;
    }
    else if(strcmp(col, "imdb_score") == 0) {
        return 2;
    }
    else if(strcmp(col, "aspect_ratio") == 0) {
        return 2;
    }
    else if(strcmp(col, "movie_facebook_likes") == 0) {     
        return 1;
    }
    else{
        // printf("Column name does not exist\n");
        return -1;
    }    
}


int main(int argc, char const *argv[]){
    int columnIndex;

    if(stdin == NULL){
        printf("Invalid format:\ncat input.file | ./sorter -c  \"movie_title\"\n");
        exit(EXIT_FAILURE);
    }

    // Make sure there are a correct number of arguments
    if ( argc != 3 || strcmp(argv[1],"-c") != 0) {
        printf("Invalid format:\ncat input.file | ./sorter -c  \"movie_title\"\n");
        exit(EXIT_FAILURE);
        return -1;
    }

    if (validColumn(argv[2]) == -1) {
        printf("%s is not a valid column type. Please try again.\n",argv[2]);
        exit(EXIT_FAILURE);
        return -1;
    }
    

    FILE *filepath = stdin;
    char line[BUFFER_SIZE];


    fgets(line, BUFFER_SIZE, filepath);

    char *headerLine = strdup(line);
    char *headerToken;
    int number_of_columns = 0;
    
    //************ Find Number of columns ************
    headerToken = strtok(line, ",");
    while(headerToken != NULL ) {
        // printf("%s\n", headerToken );
        
        headerToken = strtok(NULL, ",");
        number_of_columns++;
    }
    
    //************ Create header array to store column values ************
    char* headerarr[number_of_columns];
    int i=0;
    while(i< number_of_columns){
        headerarr[i] = strsep(&headerLine,",");
        // printf("[%d]: %s\n",i,headerarr[i]);
        i++;
    }

    
    // int p;
    // for(p=0; p<number_of_columns;p++){
    //     printf("[%d]: %s\n",p,headerarr[p]);
    // }

    int current_column=0;
    int row_number=0;
    
    //************ Find movie index so we know what when to keep an eye out for quotes ************
    int movieIndex;
    movieIndex = findMovieIndex(headerarr,number_of_columns);
    // printf("[Movie Index]: %d\n",movieIndex);

    //Initialize table
    int TABLE_SIZE = 5044;
    Row **table = malloc(TABLE_SIZE * sizeof(Row*));

    for (i = 0; i < TABLE_SIZE; i++) {
		//Intiialize struct with dynamic array
		table[i] = malloc(sizeof(Row) + number_of_columns*sizeof(char*));
    }




    while(fgets(line, BUFFER_SIZE, filepath) != NULL){
        char* temp = strdup(line);

        // printf("[R]:%d ==> %s\n",row_number,temp);

        //************ Reset Array Pointer back to 0 every time new row comes ************ 
        current_column = 0;

        // arr = realloc(arr, (numRecords + 1) * sizeof(record));
        while(current_column < number_of_columns){
            char* quote = "\"";
            char* comma = ",";
            char* token;

            if(current_column == movieIndex){
                char * front = &temp[0];
                //************ movie title WITH quotes ************ 
				if(strstr(front, quote) != NULL ) {
					temp++;
					token = strsep(&temp, quote);
					temp++;
				}
				else {
                    //************ movie title WITHOUT commas ************ 
					token = strsep(&temp, comma); //regular movie title without ""				
                } 
            }
            else{
                token = strsep(&temp,comma);
            }

            trim(token);
            // printf("[C]:%d\n",current_column);
            table[row_number] -> columnValues[current_column] = token;

            // table[row_number].columnValues[current_column] = malloc(strlen(token)*sizeof(char*));
            // strcpy(table[row_number].columnValues[current_column],token);


            // printf("[C]:%d ==> %s\n",current_column,table[row_number].columnValues[current_column]);

            current_column++;

        }


        row_number++;
        
    }

    // printf("Number of rows: %d\nNumber of columns: %d\n",row_number,number_of_columns);
    const char* column_to_sort = argv[2]; 
    int search_index = searchForField(headerarr,number_of_columns,column_to_sort);
    int data_type = getDataType(argv[2]);

    Mergesort(table,0, row_number-1,search_index,data_type);

    printTable(table,headerarr,number_of_columns,row_number,movieIndex);

    

    

    
}