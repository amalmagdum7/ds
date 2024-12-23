#include <stdio.h>
int factorial(int n)
{
    if (n<=1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void main()
{
    int num;

    printf("Enter Number to Calculate Factorial: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial Not Possible\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }
}
