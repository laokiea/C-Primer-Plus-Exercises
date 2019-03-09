#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdatomic.h>

#include "function.h"

double _global = 1;

int ___a = 1;

static int _static = 10;
// extern int var = 0;

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

void __test_11__(void) 
{
    // extern int a = 1;
    // double * ptd;
    // ptd = (double *) malloc(30 * sizeof(double));

    // char * string = "hello";
    // free(string);

    extern int ___a;
    ___a = 1101;
    printf("%d\n", ___a);
}

void __test_13__(void) {
    extern int _static;
    _static = 113;
    printf("%d\n", _static);
}

void __test_12__(void) 
{
    double * ptd;
    int max_size;
    puts("What is the maximun number of type double entries?");

    if(scanf("%d", &max_size) != 1) {
        puts("Wrong input, Goodbye");
        exit(EXIT_FAILURE);
    }

    ptd = (double *) calloc(max_size, sizeof(double));
    if(!ptd) {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    puts("Ok, Let's get some example:");
    while(i < max_size && scanf("%lf", &ptd[i]) == 1) {
        i++;
    }

    for(int j = 0;j < i;j++) {
        printf("%7.2f\n", ptd[j]);
        if(j % 5 == 4) {
            putchar('\n');
        }
    }

    puts("done");
    free(ptd);
}

void * __test_14__(void)
{
    int * pti;
    pti = (int *) malloc(10 * sizeof(int));
    if(NULL != pti) {
        return (void *)pti;
    } else {
        return (void *)NULL;
    }
    // int n = 2;
    // int _a[n] = {1, 2};
    
    // return _a;
}

void __test_15__(void)
{
    int n = 5;
    int m = 6;
    int (* pt2i_1)[6];
    int (* pt2i_2)[m];
    int ar2[n][m];

    pt2i_1 = (int (*)[6]) malloc(n * 6 * sizeof(int));
    pt2i_2 = (int (*)[m]) malloc(n * m * sizeof(int));

    ar2[1][1] = *(*(pt2i_1 + 1) + 2) = 12;

    printf("%d %d\n", ar2[1][1], pt2i_1[1][2]);
}

int _where_static_int = 1;
char * _where_static_string = "Static String Literal";
void __where_memory_at__(void) 
{
    int _auto_int = 1;
    char _auto_string[] = "Auto String";

    int * pti;
    pti = (int *) malloc(sizeof(int) * 10);
    *pti = 10;

    char * ptc = (char *) malloc(strlen("Dynamic String") + 1);
    strcpy(ptc, "Dynamic String");

    puts("Static Variables:");
    printf("static int %d at %p\n", _where_static_int, &_where_static_int);

    printf("static string \"%s\" at %p\n", _where_static_string, _where_static_string);

    printf("String Literal \"%s\" at %p\n", "Hello World", "Hello World");
    putchar('\n');

    puts("Auto Variables:");
    printf("auto int %d at %p\n", _auto_int, &_auto_int);

    printf("auto string \"%s\" at %p\n", _auto_string, _auto_string);
    putchar('\n');

    puts("Dynamic Variables:");
    printf("dynamic int %d at %p\n", *pti, pti);
    printf("dynamic string \"%s\" at %p\n", ptc, ptc);
}

void __const_qualified_type__(void)
{
    int i = 0;
    int * const pti = &i;
    *pti = 10;

    int j = 1;
    // pti = &j;
}

void __volatile_qualified_type__(void)
{
    // long int time = (long)time(NULL);
    // int i = 10,s,k;
    // s = i;
    // puts("hello");
    // puts("world");
    // k = i;

    // printf("%p\n", &i);

    // volatile vaiables
    volatile int a;
    int volatile b;

    // a pointer to a volatile variable
    volatile int * pti_vol;

    // a volatile pointer to a non-volatile variable
    int * volatile pti_vol_;

    // a volatile pointer to a volatile variable
    volatile int * volatile _pti_vol_;
}

void __restrict_qualified_type__(void)
{
    int ar[5] = {1,2,3,4,5};
    // int * restrict pti_a = ar;
    int * pti_b = ar;

    // int * restrict pti = (int *) malloc(sizeof(int) * 10);
    for(int n = 0;n < 5;n++) 
    {
        pti_b[n] += 8;
        ar[n] *= 2;
        // pti_b[n] += 3;
        printf("%d\n", pti_b[n]);
        printf("%d\n", ar[n]);
    }
}

void __Atomic_qulified__(void)
{
    int hong = 10;
    _Atomic int a;
    atomic_store(&a, 1);
}

int main(int argc, char * argv[]) {
    // printf("%d\n", *(__test__()));

    // __test_1__();

    // __test_2__();

    // __test_3__();

    // __test_5__();

    // __test_6__();

    // __test_7__();

    // __test_8__();

    // __test_9__();
    // printf("%f\n", _global);

    // __test_10__();

    // __test_11__();

    // __test_12__();

    // __test_13__();

    // var = 1;

    // int * pti;
    // pti = (int *)__test_14__();
    // free(pti);

    // __test_15__();

    // __where_memory_at__();

    // __const_qualified_type__();

    // __volatile_qualified_type__();

    // __restrict_qualified_type__();

    __Atomic_qulified__();

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
// 5. 静态变量和外部变量是程序载入内存时就被声明（编译时）
// 6. extern和static关键字和上下文有关，extern的声明如果处于文件作用域，那么引用的变量必须是具有外部链接，如果声明处于块作用域，那么引用的变量可能具有外/内部链接

// 7. c中不是必须使用强制类型转换来使void指针符合其他类型的指针，但是c++中必须

// 8. 变长数组不可以初始化，且变长数组是自动存储类别，（块作用域，自动存储期，无链接），块的结束处自动回收。
// 9. 而malloc分配的内存是属于heap，类似于静态变量（静态存储期， 文件作用域，外/内部链接 ），通过指针去访问

// 10. 静态存储类别的变量保存在内存的数据段，动态创建的内存属于堆，自动存储类别的变量保存在栈

// 12. volatile作用是告诉编译器这个变量是易变的，不用caching这个值，主要用于嵌入式开发中外围设备的值改变影响代码的执行。

// 11. restrict作用是告诉编译器，这个地址只有某一个指针可以访问，代码里如果有两次指针访问的情况，那么编译器不会做最坏假设，即有另外一个指针也可以访问改地址并且改变了地址上的值。