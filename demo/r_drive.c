#include <stdio.h>
#include "_rand.h"

int main(void) 
{
    for(int i = 0;i < 5;i++) {
        printf("%ld\n", _rand());
        printf("%ld\n\n", seed);
    }
    printf("\n");

    return 0;
}