#include <stdio.h>
// Hello world

/*
int main() {
    printf("Hello World!");
    return 0;

}
*/

/*
int main() {

    int number_1;
    int number_2;
    printf("Please input the first number.");
    scanf("%d", &number_1);
    printf("Please input the second number.");
    scanf("%d", &number_2);
    int sum = number_1 + number_2;
    printf("The sum of %d and %d is %d", number_1, number_2, sum);
    return 0;
}
*/

/*
int main() {
    int int_max = sizeof(int);
    int char_max = sizeof(char);
    int double_max = sizeof(double);
    int float_max = sizeof(float);
    printf("The max size of Integer, Characters, Doubles and Floats are: %d, %d, %d and %d", int_max, char_max, double_max, float_max);
    return 0;

}

*/

int main() {
    long int number;
    printf("Please enter the number:");
    scanf("%ld", &number);
    long int number_factorial = number;
    long int num_store = number;
    while (num_store > 1){
        long int num_store = num_store-1;
        long int number_factorial = number_factorial*num_store;
        printf("%ld",num_store);
    }
    printf("The factorial of %ld is %ld", number, number_factorial);
    return 0;
}