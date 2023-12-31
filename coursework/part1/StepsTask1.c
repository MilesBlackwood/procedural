#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct csvdata{
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
FITNESS_DATA data;


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FILE *file;
    file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL){
        perror("");
        return 1;
    }

    int fileLines = 0;
    int buffer_size = 100;
    char line_buffer[buffer_size];
    char date[11];
    char time[6];
    char steps[100];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        fileLines ++;
    }
    printf("Number of records in file: %d\n", fileLines);
    int i;
    rewind(file);
    for (i = 0; i < 3; i++){
        fgets(line_buffer, buffer_size, file);
        tokeniseRecord(line_buffer, ",", date, time, steps);
        strcpy(data.date, date);
        strcpy(data.time, time);
        data.steps = atoi(steps);
        printf("%s/%s/%d\n",data.date, data.time, data.steps);
    }

}
