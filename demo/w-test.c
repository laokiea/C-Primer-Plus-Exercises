#include <stdio.h>

int div32(int x) 
{
    int b = (x >> 31) & 0X1F;printf("%d\n", b);
    return (b + x) >> 5;
}

int main(void)
{
    // int a = -9;
    // unsigned int b = 1;
    // unsigned int c = a * b;
    // printf("%u\n", c);

    // int a = 0X80000000;
    // int b = -1;
    // int c = a / b;
    // printf("%d\n", div32(-64));

    float a = 0.1;
    printf("%.10f\n", a);

    return 0;
}