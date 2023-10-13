#include <stdio.h>
/*
int main() {

    int a = 5, i = 0;

    for(i = 1; i<=a; i++){
        printf("%d", i);
    }
    return 0;
}
*/

/*
int main() {
    int a = 5, i = 0;
    while(i <=5){
        printf("%d", i);
        i = i+1;
    }
    return 0;
}
*/

/*
int main() {

    int a = 1, i = 1;
    for (a = 1; a<=10; a++){
        printf("%d\n", i);
        i = i + 2;
    }
    return 0;
}
*/

/*
int main(){
    int i =20;
    while (i >= 0){
        printf("%d\n", i);
        i = i - 2;
    }
    return 0;
}
*/

/*
int main(){
    int a = 1, i = 0;
    while (a <=10){
        i = a * a;
        printf("%d\n", i);
        a = a +1;
    }
    return 0;
}
*/
/*
int main() {
    int array[10], count; // Creates an integer array of size 10
    for (count =0; count < 10; count++){
        array[count] = (count + 1) * 10;
    }
    for (count =0; count < 10; count++){
        printf("%d\n", array[count]);
    }
    return 0;
}
*/

/*
int main(){
    char string[6] = "Hello";
    int count;
    for (count = 5; count >=0; count--){
        printf("%c\n", *(string + count));

    }
    return 0;
}
*/

/*
int main() {
    int array[5], count, total = 0;
    for(count =0; count <5; count++){ // Populate the array
        array[count] = (count +1) * 10;
    }
    for (count = 0; count <5; count++){
        printf("%d\n", array[count]);
        total = total + array[count];
    }
    printf("The total sum of the array is %d", total);
    return 0;
}
*/
/*
int main(){
    int array[5], reversedarray[5], count;
    for(count = 0; count <5; count++){ // populate array
        array[count] = (count+5) * 12;
    }
    for (count=0; count<5; count++){
        reversedarray[count] = array[4-count];
    }
    for(count=0; count<5; count ++){
        printf("Array: %d, Reversed Array: %d\n", array[count], reversedarray[count]);
    }
    return 0;
}
*/
int main(){
    int array[5], count, max = 0;
    array[0] = 5;
    array[1] = 12;
    array[2] = 44;
    array[3] = 2;
    array[4] = 10;
    for(count = 0; count <5; count++){
        if (array[count] > max){
            max = array[count];
        }
    }
    printf("The max value of the array is %d", max);
}