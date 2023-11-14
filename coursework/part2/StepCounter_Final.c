#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "FitnessDataStruct.h"



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

char display_menu(char option){

    printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
    scanf("%s", &option);
    option = toupper(option);
    if (option != 'A' && option != 'B' && option != 'C' && option != 'D' && option != 'E' && option != 'F' && option != 'Q'){
        printf("Invalid choice. Try again.\n");
        option = '0';    
    }
    return option;
}
FILE* openFile(FILE *file){
    char fileName[100];
    printf("Input Filename: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL){
        printf("Error: Could not find or open the file.");
    }
    return file;
    }

int numberOfLines(FILE *file){
    int fileLines = 0;
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        fileLines ++;
    }
    return fileLines;
}

void fewestSteps(FILE *file){
    int fewest = 10000000; // setting an unrealistic number of steps so first one fill alwayas be lower
    int buffer_size = 100;
    char line_buffer[buffer_size];
    char timeslotdate[100];
    char timeslottime[100];
    char date[11];
    char time[6];
    char steps[100];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer, ",", date, time ,steps);
        if (atoi(steps) < fewest){
            fewest = atoi(steps);
            strcpy(timeslotdate, date);
            strcpy(timeslottime, time);
        }
        }
    printf("%s %s\n", timeslotdate, timeslottime);
    }


void mostSteps(FILE *file){
    int most = 0;
    char timeslotdate[100];
    char timeslottime[100];
    int buffer_size = 100;
    char line_buffer[buffer_size];
    char date[11];
    char time[6];
    char steps[100];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer, ",", date, time ,steps);
        if (atoi(steps) > most){
            most = atoi(steps);
            strcpy(timeslotdate, date);
            strcpy(timeslottime, time);
        }
    }
    printf("%s %s\n", timeslotdate, timeslottime);
}

float averageSteps(FILE *file){
    int fileLines = 0;
    int totalSteps = 0;
    char date[11];
    char time[6];
    char steps[100];
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        fileLines ++;
        tokeniseRecord(line_buffer, ",", date, time ,steps);
        totalSteps += atoi(steps);
    }
    return round(totalSteps / fileLines);
}

void peroidAbove500(FILE *file){
    char startPeriodTime[100];
    char startPeriodDate[100];
    char endPeriodTime[100];
    char endPeriodDate[100];
    char newStartPeriodTime[100];
    char newStartPeriodDate[100];
    char newEndPeriodTime[100];
    char newEndPeriodDate[100];
    int len = 0;
    int newLen = 0;
    int previous = 0; // if the data before was over 500 steps
    char period[8] = "current";
    char date[11];
    char time[6];
    char steps[100];
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer, ",", date, time ,steps);
        if (atoi(steps) > 500){
                if (previous == 1){
                    if (period == "current"){
                        len += 1;
                        strcpy(endPeriodDate, date);
                        strcpy(endPeriodTime, time);
                    }
                    else if (period == "new"){
                        newLen += 1;
                        strcpy(newEndPeriodDate, date);
                        strcpy(newEndPeriodTime, time);
                    }
                }
                else if (previous == 0){
                    if (period == "current"){
                        len = 1;
                        strcpy(startPeriodDate, date);
                        strcpy(startPeriodTime, time);
                        previous = 1;
                    }
                    else if (period == "new"){
                        newLen = 1;
                        strcpy(newStartPeriodDate, date);
                        strcpy(newStartPeriodTime, time);
                        previous = 1;
                    }
                }
                
                if (newLen > len){
                    strcpy(startPeriodTime ,newStartPeriodTime);
                    strcpy(startPeriodDate ,newStartPeriodDate);
                    strcpy(endPeriodTime, newEndPeriodTime);
                    strcpy(endPeriodDate, newEndPeriodDate);
                    len =  newLen;
                    strcpy(period, "current");
                }
        }
        else{
            previous = 0;
            strcpy(period, "new");
        }
    }
    printf("Longest period start: %s %s\nLongest period end: %s %s", startPeriodDate, startPeriodTime, endPeriodDate, endPeriodTime);
}
// Complete the main function
int main() {
    char menuOption = '0';
    char *filename = "";
    FILE *file = NULL;
    while (menuOption != 'Q'){
        if (menuOption == '0'){
            menuOption = display_menu(menuOption);
        if (menuOption == 'Q'){
            break;
        }
        }
        if (menuOption == 'A'){
            file = openFile(file);
            if (file == NULL){
                return 1;
            }
        }
        if ((menuOption != 'A' && menuOption != 'Q') && file != NULL){
            if (menuOption == 'B'){
                printf("Total records: %d\n", numberOfLines(file));
            }

            else if (menuOption == 'C'){
                fewestSteps(file);
            }

            else if (menuOption == 'D'){
                mostSteps(file);
            }

            else if (menuOption == 'E'){
                printf("Mean Step Count: %f\n", averageSteps(file));
            }

            else {
                peroidAbove500(file);
            }

        }
        if (file == NULL){
            printf("Please select option A and specify a valid file");
        }
        menuOption = '0';
        rewind(file);

    }
    return 0;
}
