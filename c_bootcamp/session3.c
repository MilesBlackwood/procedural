#include <stdio.h>
/*
int main() {
	int option;
	printf("Please choose an option from 1-5\n");
	scanf("%d", &option);
	
	switch (option) {
		case 1:
		    printf("You have selected option %d.", option);
		    break;
		
		case 2: 
		    printf("You have selected option %d.", option);
            break;

		case 3: 
		    printf("You have selected option %d.", option);
		    break;

		case 4: 
		    printf("You have selected option %d.", option);
		    break;

		case 5: 
		    printf("You have selected option %d.", option);
		    break;

		default: 
		    printf("You have selected an invalid option.");
	}
	return 0;
}
*/


int main() {
    int termValue = -1, value = 0;
    while (value != termValue){
        printf("Please enter a value between 0 and 100.\n");
        scanf("%d", &value);
        if ((value < 0 || value > 100) && value != -1){
            printf("Out of range\n");
        }
    }
    printf("You have entered the termination value of -1");
    return 0;
}

