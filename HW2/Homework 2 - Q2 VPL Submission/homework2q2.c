#include <stdio.h>
#include <stdlib.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter arithmetic operation:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.
    float result = 0.0;
    int i = 0;
    int decimal = 0;
    int sign = 1;
    float fraction = 1.0;

    float result2 = 0.0;

    int plus = 0;
    int minus = 0;
    int multiply = 0;
    int divide = 0;
    int op = 1;


    if (string[0] == '-') {
        sign = -1;
        i++;
    }

    while (string[i] != '\0') {
        if (string[i] == '.') {
            decimal = 1;
            i++;
            continue;
        }

        if(string[i] == '+') {
            plus=1;
            decimal = 0;
            fraction = 1.0;
            op = 0;
            i++;
            continue;
        }

        if(string[i] == '-') {
            minus=1;
            decimal = 0;
            fraction = 1.0;
            op = 0;
            i++;
            continue;
        }

        if(string[i] == '/') {
            divide=1;
            decimal = 0;
            fraction = 1.0;
            op = 0;
            i++;
            continue;
        }

        if(string[i] == '*') {
            multiply=1;
            decimal = 0;
            fraction = 1.0;
            op = 0;
            i++;
            continue;
        }

        if (string[i] < '0' || string[i] > '9') {
            *error = 1;
            printf("Error has been occurred due to inappropriate input!");
            return 0.0;
        }

        if(op==1){
            if (decimal) {
                fraction *= 0.1;
                result += (string[i] - '0') * fraction;
            } else {
                result *= 10.0;
                result += string[i] - '0';
            }

                i++;
        }

        if(op==0){
            if (decimal) {
                fraction *= 0.1;
                result2 += (string[i] - '0') * fraction;
            } else {
                result2 *= 10.0;
                result2 += string[i] - '0';
            }

                i++;
        }


    }
    if(plus){
        printf("%.2f + %.2f = %.2f", (sign*result), result2, (result+result2));
    }
    if(minus){
        printf("%.2f - %.2f = %.2f", (sign*result), result2, (result-result2));
    }
    if(divide){
        if(result2==0){
            printf("Cannot divided into 0.");
            return 0;
        }else{
        printf("%.2f / %.2f = %.2f", (sign*result), result2, (result/result2));
        }
    }
    if(multiply){
        printf("%.2f * %.2f = %.2f", (sign*result), result2, (result*result2));
    }

    return 0;
}
