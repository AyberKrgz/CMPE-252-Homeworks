#include <stdio.h>
#include <math.h>

double f(int x, int c, int d);

int main()
{
    int a,b,n,c,d;
    double T,h,Y;

    printf("Enter value of a: \n");
    scanf("%d",&a);
    printf("Enter value of b: \n");
    scanf("%d",&b);
    printf("Enter value of n: \n");
    scanf("%d",&n);
    printf("Enter value of c: \n");
    scanf("%d",&c);
    printf("Enter value of d: \n");
    scanf("%d",&d);

    h = (b-a)/n;

    Y=0;

    for(int i = a+h; i<b; i = i+h)
    {
        Y = Y + f(i,c,d);
    }

    T = (h/2)*(f(a,c,d)+f(b,c,d)+2*Y);

    printf("T: %.2f", T);

    return 0;
}

double f(int x, int c, int d)
{
    return (pow(x,c)+2*d);
}

