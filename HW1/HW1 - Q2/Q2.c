#include <stdio.h>
#include <math.h>

float multiply(float a, float b, float c, int index);

int main(void)
{
    float a,b,c,x;
    int xmin,xmax,index;
    printf("Enter value of a:\n");
    scanf("%f",&a);
    printf("Enter value of b:\n");
    scanf("%f",&b);
    printf("Enter value of c:\n");
    scanf("%f",&c);
    printf("Enter minimum value of x_n:\n");
    scanf("%d",&xmin);
    printf("Enter maximum value of x_n:\n");
    scanf("%d",&xmax);

    index = xmin;

    while (index <= xmax)
    {
        x = multiply(a,b,c,index);
        printf("x_%d: %.2f\n", index, x);
        index++;
    }

}

    float multiply(float a, float b, float c, int index)
    {
        float Xn;
        if(index == 0)
        {
            Xn = 10.0;
        }

        else
        {
            Xn = multiply(a,b,c,(index-1))*b + ( sqrt(pow(b,2)-4*a*c) - b )/(2*a);
        }

        return Xn;
    }
