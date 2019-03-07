#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

double _global = 1;

void __test_8__(void);

int * __test__(void) {
    // 块作用域的变量具有自动存储期，static关键字改变的不是作用域而是存储期
    static int a = 10; 
    return &a;
}

void __test_2__(void) {
    {
        int i = 1;
    }
    // printf("%d\n", i);
}

void __test_3__(void) {
    int x = 5;
    while(x++ < 8) {
        int x = 10;
        printf("inner x is : %d, at %p\n", x, &x);
    }
}

void __test_4__(void) {
    for(int a = 1;a < 3;a++) {
        if(a) {
            int i = 1;
        }
        // printf("%d\n", i);
    }
}

void __test_5__(void) {
    int i;
    printf("%d\n", i);
}

 void __test_6__(void) {
     register int a = 1;
    //  printf("%p\n", &a);
 }

void __test_7__(void) {
    extern int _extern; // function.h中声明的外部变量
    printf("%d\n", _extern);
}

void __test_9__(void) {
    scanf("%lf", &_global);
    printf("%f\n", _global);
}

void __test_10__(void) {
    static int __test_10_v__ = 1;
    printf("%d\n", __test_10_v__);
}

void __rand__(void) {
    
}

int main(int argc, char * argv[]) {
    // printf("%d\n", *(__test__()));

    // __test_1__();

    // __test_2__();

    // __test_3__();

    // __test_5__();

    // __test_6__();

    __test_7__();

    // __test_8__();

    // __test_9__();
    // printf("%f\n", _global);

    // __test_10__();

    return 0;
}

int end = 1;

void __test_8__(void) {
    printf("%d\n", end);
}

// 1. 具有块作用域和文件作用域的变量的有效范围是变量定义处开始
// 2. 外部变量只能初始化为常量，且只能在声明处初始化一次，默认为0
// 3. extern int a; 引用式声明，不会为变量开辟内存空间
// 4. register寄存器存储类别不能获取变量的地址
// 5. 静态变量和外部变量是程序载入内存时就被声明
// 6. extern和static关键字和上下文有关，extern的声明如果处于文件作用域，那么引用的变量必须是具有外部链接，如果声明处于块作用域，那么引用的变量可能具有外/内部链接