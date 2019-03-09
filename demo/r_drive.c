#include <stdio.h>
#include "_rand.h"

// static int _test = 114;

int main(void) 
{
    printf("%d\n\n", _test);
    for(int i = 0;i < 5;i++) {
        printf("%ld\n", _rand());
        printf("%ld\n\n", seed);
    }
    printf("\n");

    return 0;
}