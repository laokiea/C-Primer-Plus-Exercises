#include <stdio.h>
//  int _main(void);
int _main(void) {

    extern int _extern;
    printf("%d\n", _extern);

    return 0;
}