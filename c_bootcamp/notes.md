#include -> imports libaries
int main() {

} -> First thing the computer will look at when nnign the code

printf("") -> Prints a string out
every line of code needs a ; to follow it.

we can compile the code with the Bash command : gcc filename.c -o anotherfilename
we can then run that compiled code by doing: ./compiledfilename
we should end our processes with a return 0; to stop it running forever

To declare a variable, you state its type e.g str, int, char, float. Then followed by the variable name as well as what it is then equal to

we can use identifiers in the string to specify where to input certain datatypes.
%d within a string signifies an integer data type and will insert the value of the int variable input into the printf command. If there are multiple %d, it will replace them in hte order that they are specified in the parameters.
Including "\n" in a string moves the next part of the string onto a new line within the terminal

To have user input included, we assign a vairable and its type but dont have it equal to anything. We then t=use the scanf command in the format: 
scanf("%(datatype)", variablename)
This will assign what the user then types into the variable specified as long as it matches the data type for the variable.
Putting an & infront of the variable name will get the absolute value of that variable.

To create a string variable we have to set a limit of characters that the string can hold. To do this we specify it by declaring the variable: char string_name[stringlength];
This can be equal to a set value or can be left blank so the user can assign it one or it gets assinged later. To assign it to a variable using the scanf command, you do not need the & symbol in front of the variable name.