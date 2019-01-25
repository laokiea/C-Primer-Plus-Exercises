#include <stdio.h>
#include "function.h"

#define MSG "hello"
#define SLEN 10

void __print_static_string_firstbyte_addr__(void);
void __string_literal_cannot_modified__(void);
void __test_char_array_and_string_ptr__(void);
void __test_char_array_and_string_ptr_2__(void);
void __string_array_defined__(void);
void __string_and_pointer__(void);
void __alloacte_memory__(void);
void __get_put_string__(void);
void __fgets_and_fputs__(void);
void __loop_read_user_input__(void);
void __loop_read_user_input_2__(void);
void __fgets_test__(void);
void __test_scanf__(void);
void __where_puts_function_stop__(void);
void __another_fputs__(const char *);

int main(void) {

    // char c[50] = "hello";
    // printf("%d\n", *((int[5]){1,2,8,6,9} + 2));
    // printf("%c\n", *c);

    // __print_static_string_firstbyte_addr__();

    // __string_literal_cannot_modified__();

    // __test_char_array_and_string_ptr__();

    // __test_char_array_and_string_ptr_2__();

    // __string_array_defined__();

    // __string_and_pointer__();

    // __alloacte_memory__();

    // __get_put_string__();

    // __fgets_and_fputs__();

    // __loop_read_user_input__();

    // __loop_read_user_input_2__();

    // __fgets_test__();

    // __get_s_test__();

    // char string[SLEN];
    // s_gets(string, SLEN);
    // puts(string);

    // __test_scanf__();

    // __where_puts_function_stop__();

    return 0;
}

void __print_static_string_firstbyte_addr__(void) {
    // ervey call will output the same address
    printf("%p\n", "hello world");
} 

void __string_literal_cannot_modified__(void) {
    // char c[40] = "hello world"; 
    // c[1] = 'b';
    // char * c = "hello world";
    // printf("%c\n", c[1]);
    // const char ch[] = "hello";
    // ch[1] = 'd';
}

// 字符串数组，是将静态存储区域内的字符串拷贝到数组中
// ar是该数组首元素的地址
// 而字符串指针是将静态存储区内的字符串的首元素地址赋给指针，指针的值可以随便改
// 字符字面量都是存储在静态存储区，被视为const数据，不可修改，也就是程序的生命周期内只存储一次
// 编译器可能会把MSG和“hello”等同一个字面量放在同一个地址上，也可能放在两个不同的地址上。
void __test_char_array_and_string_ptr__(void) {
    char ar[] = MSG;
    const char * c = MSG;

    printf("pointer of \"hello\" : %p\n", "hello");
    printf("pointer of ar : %p\n", ar);
    printf("value of pointer c : %p\n", c);
    printf("pointer of MSG : %p\n", MSG);
}

void __test_char_array_and_string_ptr_2__(void) {
    char ch[] = "compare";
    // 字符字面量是const的，把指针声明成const，防止指针修改字符串的值
    const char * c = "compard";
    // for(int i = 0;i < 8;i++) {
    //     printf("%c %c\n", *(ch + i), *(c++));
    // }

    // c = ch;
    // printf("%c\n", *(c+6));

    // c[0] = 'd';
    // printf("compard");
}


// 字符串数组的定义
// 可以声明一个包含字符串指针的数组，也可以声明一个char类型数组（字符串）的数组
void __string_array_defined__(void) {
    const char * ch1[SLEN] = {"hello", "hello"}; // 声明一个包含两个char类型指针的数组，声明成const是代表不能用指针修改字符串的值，但是每个指针的值（指向的字符串）可以改变
    char ch2[SLEN][10] = {"hello", "hello"}; //

    // 字符串就是一个字符数组，所以使用方法和数组一样，字符串数组和二维数组使用方法一样
    // %s 接受一个字符指针
    // for(int i = 0;i < SLEN;i++) {
    //     printf("%s %10c %s\n", *(ch1 + i), ' ', *(ch2 + i));
    // }

    // printf("%c\n", *(*(ch1 + 1) + 1));
    // *(ch2[1] + 1) = 'g'; 

    // 二者的不同
    // 第一声明一个字符串指针数组，占用的内存更少，ch1占用2指针的大小，为16字节，而ch2占用了20个字节大小
    // 第二，ch1只是声明了两个指向静态存储区字符串的指针，而ch2是拷贝了两份静态存储区字符串进内存，每个字符串被存储两份

    // int i = 1;
    // int j = 2;
    // int * pi[2] = {&i, &j};
    // printf("%p\n", pi);
    // printf("%p\n", &pi[0]);
    // printf("%d\n", **(pi + 1));
}


void __string_and_pointer__(void) {
    const char * msg = "do not be a fool";
    const char * copy;

    copy = msg;

    // printf("msg = %s   &msg = %p    value = %p\n", msg,
    //  &msg, msg);
    // printf("copy = %s    &copy = %p    value = %p\n", copy, &copy, copy);
}

void __alloacte_memory__(void) {
    char * name;
    // scanf("%s", name);
    printf("value of name : %p", name); // 我的编译器输出：0x0

    // 这样大部分编译器会给出错误，segmentation fault
    // 因为scanf要把输入的值 （从输入缓冲区）拷贝 到指定的地址，但是name是个为初始化的指针，它没有指向任何值，或者说他可能指向任何值，这都不是我们想要的🔝
}


// fgets gets puts fputs都接受一个指针（也就是一个地址），也就是说这些函数只需要知道字符串开始的地址即可，因为通常指针即指向字符串首字符的地址，这就是字符串的开始的地址
void __get_put_string__(void) {
    char string[10];

    // gets是不安全的，数组名string是一个地址常量，是首元素的地址，换句话说，gets并不知道给string分配的内存是多少，如果输入的值过长，可能会造成输入缓冲区溢出
    gets(string);

    puts("the string you enter:");
    puts(string);
}

//fgets 函数会最多读取slen - 1(预留一个字符保存\0)个字符，或者到第一个换行符为止
// 与gets不同的是，fgets会将换行符也保存在字符串数组中,也就是说带上换行符最多读取9个字符
// puts函数会在输出结果最后加上一个换行符，而fputs则不会
void __fgets_and_fputs__(void) {
    int slen = 10;
    char string[slen];
    char * result;
    printf("%p\n", string);

    result = fgets(string, slen, stdin);
    fputs(string, stdout);
    
    printf("%p\n", result);

    // fgets(string, slen, stdin);
    // puts(string);
    // fputs(string, stdout);
}

// 如果刚好输入helloword\n,那么程序会退出，因为第二次从输入缓冲区内读取的第一个字符是换行
// fputs把输出发送至输出缓冲区，如果发送的内容中有换行符，那么会把整个缓冲区的内容输出到stdout
void __loop_read_user_input__(void) {
    char string[SLEN];
    while(fgets(string, SLEN, stdin) != NULL && *string != '\n') {
        fputs(string ,stdout);
    }
}

void __loop_read_user_input_2__(void) {
    char string[SLEN];
    char * result;
    while((result = fgets(string, SLEN, stdin)) != NULL && *result != '\n'){
        int i = 0;
        while(*(result + i) != '\n' && result[i] != '\0') {
            i++;
        }
        if(result[i] == '\0') {
            char ch;
            while((ch = getchar()) != '\n') ;
        }

        puts(string);
    }
}

void __fgets_test__(void) {
    char string[SLEN];
    fgets(string, SLEN, stdin);
    fputs(string, stdout);
    puts("done");
}

// test scanf 
// scanf也可以避免gets读取过长缓冲区内存溢出的问题
// 一般一个程序在内存中主要有一下分布
// 1. 程序段 保存程序的机器码和只读数据（const）
// 2. 数据段 保存静态数据（字符串字面量）和全局变量
// 3. 栈 保存函数栈帧，一个栈帧包括函数的参数，局部变量和返回地址，这些数据在栈中是低地址增长（栈底的地址在高位） 
// 4. 堆 保存一些动态申请的数据
// 缓冲区溢出攻击大部分发生在栈区内，如果溢出的数据覆盖了返回地址，通常需要计算溢出多少个字节才能覆盖eip，大部分攻击程序通过跳板来实现。
void __test_scanf__(void) {
    // char string[SLEN];
    // scanf("%5s", string);
    // puts(string);
    char side_a[10] = "side a";
    char string[5] = "hello";
    char side_b[10] = "side b";
    //  和下例一样，没有为\0预留出空间，通常用字符数组的形式声明字符串，分配的空间要至少比时间字节数大1
    puts(string);
} 

//puts函数会在读取（输出缓冲区）到第一个空字符\0时停止读取
// 如果字符串中没有\0时会怎样呢
// 为什么会先输出side b？
// 猜测可能是局部变量都是保存在栈内，栈是先进后出，所以先定义的变量可能会保存在栈底
void __where_puts_function_stop__(void) {
    // char side_a[10] = "side a";
    // char wow[6] = {'h', 'e','l','l','o'};
    // char side_b[10] = "side b";

    puts("hello");
    puts("world");
}

void __another_fputs__(const char * string) {
    while(*string) {
        putchar(*string++);
    } 
}