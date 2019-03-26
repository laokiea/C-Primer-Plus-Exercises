#ifndef NORMAL_INCLUDE_UNIT
#define NORMAL_INCLUDE_UNIT

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

#endif

#define MAXTITL 41
#define MAXAUTL 31

#define ABS(x) x < 0 ? -x : x
#define DEBUGMSG(msg) puts(msg);printf("Date: %s, %s \nLine: %d \nFile: %s\n", __DATE__, __TIME__, __LINE__, __FILE__)
#define TEST(x) printf(#x);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float price;
} book_struct = {
    "aaa",
    "bbb",
    29.212
};

struct names {
        char firstname[10];
        char lastname[20];
    };

void __test_1__(void) 
{
    struct book library;
    puts("Please enter the book title:");
    s_gets(library.title, MAXTITL);
    puts("Please enter the book author:");
    s_gets(library.author, MAXAUTL);
    puts("Please enter the book price:");
    fscanf(stdin, "%f", &library.price);
    printf("%s of %s: $%.2f\n", library.title, library.author, library.price);
}

void __test_2__(void)
{
    // scanf("%f", &book_struct.price);
    printf("%.2f\n", book_struct.price);
}

void __test_3__(void)
{
    char title[MAXTITL] = "book_1_title";
    float price = 192.19;
    struct book book_1 = {
        "book_1_title",
        "book_1_author",
        price
    };
    struct book * book_pt = &book_1;
    puts(book_pt->author);
}

void __test_4__(void)
{
    struct book book_2 = {
        .price = 18.99,
        .title = "hello",
        // 23.45,
        .author = "world"
    };
    printf("%.2f\n", book_2.price);
}

#define MAXBKS 100
void __test_5__(void)
{
    struct book books[MAXBKS];
    int count = 0;
    int index = 0;

    puts("Please enter the book title:");

    while(count < MAXBKS && s_gets(books[count].title, MAXTITL) && books[count].title[0]) {
        puts("Please enter the book author:");
        s_gets(books[count].author, MAXAUTL);
        puts("Please enter the book price:");
        fscanf(stdin, "%f", &books[count].price);
        while(getchar() != '\n') ;
        count++;
        puts("ok next");
        puts("Please enter the book title:");
    }

    if(count > 0) {
        puts("here is the list of your books:");
        for(;index < count;index++) {
            printf("%s of %s : %.2f\n", books[index].title, books[index].author, books[index].price);
        }
    }
}

void __struct_in_struct__(void)
{
    struct {
        struct names name;
        int age;
    } guy = {
        {"sam", "sason"},
        29
    };

    printf("The guy named %s %s is %d years old\n", guy.name.firstname, guy.name.lastname, guy.age);
}

void __struct_pt_1__(void)
{
    struct guy {
        struct names name;
        float income;
    };

    struct guy guys[2] = {{
        {"sam", "sason"},
        15000,
    },{
        {"lily", "cathy"},
        20000,
    }};

    struct guy * someguy;
    printf("#1: %p #2: %p\n", &guys[0], &guys[1]);
    someguy = &guys[0];
    printf("#1: %p #2: %p\n", someguy, someguy+1);
    printf("The guy named %s %s whose income is %.2f\n", (*someguy).name.firstname, (*someguy).name.lastname, (*someguy).income);
    someguy++;
    printf("The guy named %s %s whose income is %.2f\n", someguy->name.firstname, someguy->name.lastname, someguy->income);
}

// (*him).income = barney->income = him->income

struct fund {
        double loadword;
        double storeword;
    };
extern double __mdr_mar_pc_ir_GPRs__(double, double);
extern double __mdr_mar_pc_ir_GPRs_1__(const struct fund * fund);
extern double __mdr_mar_pc_ir_GPRs_2__(struct fund fund);
void __pass_struct_field_to_func__(void)
{
    struct fund fund_1 = {
        18.92,
        78.88,
    };
    printf("cpu: %.2f\n", __mdr_mar_pc_ir_GPRs__(fund_1.loadword, fund_1.storeword));
}

void __pass_struct_addr_to_func__(void)
{
    const struct fund fund_1 = {
        18.92,
        78.88,
    };
    printf("cpu: %.2f\n", __mdr_mar_pc_ir_GPRs_1__(&fund_1));
}

void __pass_struct_to_func__(void)
{
    struct fund fund_1 = {
        18.92,
        78.88,
    };
    printf("cpu: %.2f\n", __mdr_mar_pc_ir_GPRs_2__(fund_1));
    printf("now: %.2f\n", fund_1.loadword);
}

extern double __mdr_mar_pc_ir_GPRs_2__(struct fund fund) {
    fund.loadword = 2.0;
    return fund.loadword + fund.storeword;
}

double __mdr_mar_pc_ir_GPRs_1__(const struct fund * fund) {
    return fund->loadword + fund->storeword;
}

double __mdr_mar_pc_ir_GPRs__(double x, double y)
{
    return x + y;
}

void __copy_struct_directly__(void)
{
    struct fund fund_1 = {10.2, 19.2};
    struct fund fund_2;
    fund_2 = fund_1;
    printf("%.2f\n", fund_2.loadword);
}

void show_bytes(unsigned char * string, int len) {
    for(int i = len - 1;i >= 0;i--) {
        printf("%x ", string[i]);
    }
    printf("\n");
}

int strlonger(char * s1, char * s2)
{
    return strlen(s1) - strlen(s2) > 0;
}

// void show_float_bytes(float * a)
// {   
//     a = (char *)a;
//     for(int i = 0;i < sizeof(float);i++) {
//         printf("%x ", a[i]);
//     }
// }

int main(int argc, char * argv[]) 
{
    // int a = -2;
    // printf("%d\n", ABS(a));

    // if(__STDC__) 
        // DEBUGMSG("hello debug");

    // TEST('a');

    // __test_1__();

    // __test_2__();

    // __test_3__();

    // __test_4__();

    // __test_5__();

    // __struct_in_struct__();

    // __struct_pt_1__();

    // printf("%x\n", 1000);

    // __pass_struct_field_to_func__();

    // __pass_struct_addr_to_func__();

    // __pass_struct_to_func__();

    // __copy_struct_directly__();

    // printf("%zd\n", sizeof (long));

    // printf("%d\n", -2147483648U < 2147483647);
    // printf("%zd\n", sizeof(-2147483648));
    // int i = -2147483647;

    // printf("%d\n", -2147483648U - 1 < 2147483647);
    // 10000...000 - 1 = 0111111111111...111(63个1)
    // 000000000001111 1111111(31个1);
// 1000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 00000 0000 0000 0000
// 1000 0000 ... 1111 1111(32个1)

    // int a = -1;
    // unsigned int b = 4294967295;
    // show_bytes((unsigned char *)&a, sizeof(a));
    // show_bytes((unsigned char *)&b, sizeof(b));

    // printf("%d\n", strlonger("hi", "hello"));

    // float a = -12.75;
    // float a = -0.0 / 0.0; 
    // float a = 8.9;
    // printf("%.20f\n", a);
    // 00000000 00000000 11100000 11011110 

    // int a = 8;
    // show_bytes((unsigned char *)&a, sizeof(a));

    // int num = 9;
    // float * pfloat = (float *)&num;
    // printf("num : %d\n *pfloat : %f\n", num, *pfloat);
    // *pfloat = 9.0;
    // printf("num : %d\n *pfloat : %f\n", num, *pfloat);

    printf("%d\n", '8');

    return 0;
}