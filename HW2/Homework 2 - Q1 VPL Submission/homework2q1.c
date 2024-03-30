#include <stdio.h>
#include <stdlib.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.
    float result = 0.0;
    int i = 0;
    int decimal = 0;
    int sign = 1;
    float fraction = 1.0;

    if (string[i] == '-') {
        sign = -1;
        i++;
    }

    while (string[i] != '\0') {
        if (string[i] == '.') {
            decimal = 1;
            i++;
            continue;
        }

        if (string[i] < '0' || string[i] > '9') {
            *error = 1;
            return 0.0;
        }

        if (decimal) {
            fraction *= 0.1;
            result += (string[i] - '0') * fraction;
        } else {
            result *= 10.0;
            result += string[i] - '0';
        }

        i++;
    }

    return sign * result;
}
