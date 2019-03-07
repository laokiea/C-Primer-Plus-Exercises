#include <stdio.h>

int _extern = 14;

extern int _main(void);

static void _test(void);

int main(void) {

    _main();
    // _test();
    return 0;
}

void _test(void) {
    printf("hello");
}