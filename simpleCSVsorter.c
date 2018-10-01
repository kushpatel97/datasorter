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

/*
Params: A string or a character array;
Removes trailing an leading whitespaces
*/
char *trim(char *token){
    char *end;

    while(isspace((unsigned char)*token)) {
        token++;
    }

    if(*token == 0){
        return token;
    }

    end = token + strlen(token) - 1;
    while(end > token && isspace((unsigned char)*end)){
      end--;
    }
    end[1] = '\0';

  return token;
}

/*
Params: Headers - An array of strings: stores a list of column headers
        num_colums - the number of colums in the csv file
Returns: Integer - An interger pointing to the index of movie titles
*/
int findMovieIndex(char* headers[],int num_columns){
    int i;
    for(i=0; i < num_columns; i++){
        if(strcmp(headers[i],"movie_title") == 0){
            return i;
        }
    }
    return -1;
}

/*
Params: Headers - An array of strings: stores a list of column headers
        num_colums - the number of colums in the csv file
        fieldName - the name of the field you are searching for
Returns: Integer - An interger pointing to the index of the field you are looking for
*/
int searchForField(char* headers[],int num_columns, const char* fieldName){
    int i=0;
    while(i < num_columns){
        if(strcmp(trim(headers[i]),fieldName) == 0){
            // printf("[SORTING %d]: %s\n",i,headers[i]);
            return i;
        }
        i++;
    }
    return -1;
}

/*
Params: table - An array of string arrays that stores the csv file in the form of multiple 1d arrays
        Headers - An array of strings: stores a list of column headers
        num_colums - the number of colums in the csv file
        num_rows - the max number of rows in the the table
        movieIndex - the index of the movie_title field to look out for quotes
Returns: VOID - prints out the table row by row, including the quotes for the movie_title fields because they may contain commas in the titles
*/
void printTable(Row **table,char* headers[], int num_columns, int num_rows,int movieIndex){
    //************ "i" indicates number of rows ************    
    //************ "j" indicates number of columns ************

    int k;
    for(k=0; k<num_columns;k++){
        if(k == (num_columns-1)){
            printf("%s",trim(headers[k]));
            printf("\n");
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
Params: col - A constant string paramater
Returns: Integer - returns the following depending on the type of the string
           |__ 0 = String
           |__ 1 = Int
           |__ 2 = Double
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

    if(stdin == NULL){
        fprintf(stderr,"Invalid format:\ncat input.file | ./sorter -c  \"movie_title\"\n");
        exit(0);
        return -1;
    }

    // Make sure there are a correct number of arguments
    if ( argc != 3 || strcmp(argv[1],"-c") != 0) {
        fprintf(stderr,"Invalid format:\ncat input.file | ./sorter -c  \"movie_title\"\n");
        exit(0);
        return -1;
    }

    if (validColumn(argv[2]) == -1) {
        fprintf(stderr,"%s is not a valid column type. Please try again.\n",argv[2]);
        exit(0);
        return -1;
    }
    

    FILE *filepath = stdin;
    char line[BUFFER_SIZE];


    fgets(line, BUFFER_SIZE, filepath);

    char *headerLine = strdup(line);
    char *headerToken;
    int number_of_columns = 0;
    
    /*
    Find the number of columns in the csv file by splitting the csv headers by commas
    and store them in the number_of_columns variable
    */
    headerToken = strtok(line, ",");
    while(headerToken != NULL ) {
        // printf("%s\n", headerToken );
        
        headerToken = strtok(NULL, ",");
        number_of_columns++;
    }
    
    /*
        Create an array of strings and store the csv file headers in there
    */
    char* headerarr[number_of_columns];
    int i=0;
    while(i< number_of_columns){
        headerarr[i] = strsep(&headerLine,",");
        // printf("[%d]: %s\n",i,headerarr[i]);
        i++;
    }

    /*
        current_column - an int variable used to keep track of the current column
        row_number - an int variable to keep track of the current row in the table array
    */
    int current_column=0;
    int row_number=0;
    
    //************ Find movie index so we know what when to keep an eye out for quotes ************
    int movieIndex;
    movieIndex = findMovieIndex(headerarr,number_of_columns);
    // printf("[Movie Index]: %d\n",movieIndex);

    int TABLE_SIZE = 5044;
    Row **table = malloc(TABLE_SIZE * sizeof(Row*));

    for (i = 0; i < TABLE_SIZE; i++) {
		table[i] = malloc(sizeof(Row) + number_of_columns*sizeof(char*));
    }



    /*
        Starting with the first line of the file, read the file line by line
        
    */
    while(fgets(line, BUFFER_SIZE, filepath) != NULL){
        char* temp = strdup(line);
        temp = trim(temp);


        //************ Reset Array Pointer back to 0 every time new row comes ************ 
        current_column = 0;

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
                    // token = trim(token);
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

            // token = trim(token);

            table[row_number] -> columnValues[current_column] = token;

            current_column++;

        }


        row_number++;
        
    }

    // printf("Number of rows: %d\nNumber of columns: %d\n",row_number,number_of_columns);
    const char* column_to_sort = argv[2]; 
    int search_index = searchForField(headerarr,number_of_columns,column_to_sort);
    int data_type = getDataType(argv[2]);

    /*
        Call Mergesort on the struct with the row data
    */
    Mergesort(table,0, row_number-1,search_index,data_type);

    printTable(table,headerarr,number_of_columns,row_number,movieIndex);
}