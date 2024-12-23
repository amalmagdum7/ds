#include <stdio.h>
void TOH(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("Move Disk %d from %c to %c\n", n, s, d);
        return;
    }
    TOH(n - 1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    TOH(n - 1, t, s, d);
}

void main()
{
    int n = 3;
    TOH(n, 'S', 'T', 'D');
}
