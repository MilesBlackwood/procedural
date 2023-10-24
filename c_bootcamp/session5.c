#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
/*
int main() {
    char filename[] = "testfile.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("");
        return 1;
    }
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}
*/
void writeToFile(FILE *file){
    int n;
    int i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i<=n; i++){
        fprintf(file, "%d\n", i*i);
    }
}

float averageOfSquares(FILE *file){
    int buffer_limit = 100;
    char line_buffer[buffer_limit];
    float total = 0, maxNumber = 0;
    float average;
    while (fgets(line_buffer, buffer_limit, file) != NULL){
        if (line_buffer != ""){
            total = total + atoi(line_buffer);
            maxNumber += 1;
        }
    }
    average = total / maxNumber;
    
    return average;

}

int main() {
    char filename[] = "squares.dat";
    FILE *file ;
    file = opn_file(filename, "w");
    writeToFile(file);
    fclose(file);
    file = file_open(filename, "r");
    printf("The average of the squares is %f",averageOfSquares(file));
    return 0;

}
