#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define SIZE 1000

 

char* encodebase64(char input_string[], int string_length)

{

        char character_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        char *resulting_string = (char *) malloc(SIZE * sizeof(char));

        int index, number_of_bits = 0, append_zeros = 0, value = 0, count = 0, temporary;

        int i, j;

        int k = 0;
       
        // function takes 3bits at a time
        for (i = 0; i < string_length; i = i + 3)

        {
               
                value = 0, count = 0, number_of_bits = 0;

                for (j = i; j < string_length && j <= i + 2; j++)

                {       // value shifts by 8 to open space for the new string
               
                        value = value << 8;
                       
                        value = value | input_string[j];
                       
                       
                        //count saves the newly formed bits, that consist of 3bits
                        count++;

                }

                number_of_bits = count * 8;
               
                // append_zeros identifies how many zerros it should append from the end of the string, by dividing it to 3
                append_zeros = number_of_bits % 3;
                 
                 //as we dont have fully empty string, it eneters to the while loop with the following statement
                while (number_of_bits != 0)

                {
                        //the function checkes if number of bits is more then six or not
                        if (number_of_bits >= 6)

                        {

                                temporary = number_of_bits - 6;

                                index = (value >> temporary ) & 63;

                                number_of_bits = number_of_bits - 6;

                        } // it runs in the loop until the number of bits is less than six

                        else

                        {

                                temporary = 6 - number_of_bits;

                                index = (value << temporary) & 63;

                                number_of_bits = 0;

                        } // in result we have resulting_string with the respected character_set

                        resulting_string[k++] = character_set[index];

                }

        }
                        // this function appends zeros when nedeed from the right side                          
                        for (i = 1; i <= append_zeros; i++)

                        {

                        resulting_string[k++] = '=';

                        }

                        resulting_string[k] = '\0';

                        return resulting_string;

}

int main()

{

        int string_length;

        char input_string [SIZE];

        printf("Please enter your text\n");
       
        //this appends strings and makes a single union string
        scanf ("%[^\n]%*c", input_string);
         
         //strlen checkes the legth of the string of the input string
        int length = strlen(input_string);
 
        // you need to create a copy of the input_string since we initially did not know the size of it  
        char input_copy [length];

        for(int i =0; i < strlen(input_string); i++){

                input_copy[i] = input_string[i];

        }
       
        // this removes the rubbish from the end of the string
        string_length = sizeof(input_copy) / sizeof(input_copy[0]);
       
        printf("Input string is : %s\n", input_copy);
        // goes into the function written above

        printf("Encoded string is : %s\n", encodebase64(input_copy, string_length));

        return 0;

}

