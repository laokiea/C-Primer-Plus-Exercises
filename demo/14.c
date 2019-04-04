#ifndef NORMAL_INCLUDE_UNIT
#define NORMAL_INCLUDE_UNIT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void show_bytes(char * string, size_t len) {
    for(size_t i = len - 1;i >= 0;i--) {
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
struct namect {
    char * lname;
    char * fname;
    int letters;
};

void getinfo(struct namect * nct)
{
    nct->lname = (char *) malloc(10);
    nct->fname = (char *) malloc(10);
    puts("Enter your first name");
    s_gets(nct->fname, 10);
    puts("Enter your last name");
    s_gets(nct->lname, 10);
}

void makeinfo(struct namect * nct) 
{
    nct->letters = strlen(nct->lname) + strlen(nct->fname);
}

void showinfo(struct namect * nct)
{
    printf("%s %s %d\n", nct->fname, nct->lname, nct->letters);
}

void cleanup(struct namect * nct)
{
    free(nct->fname);
    free(nct->lname);
}

void __test_write_to_file__(void)
{
    struct test {
        char name[20];
        int len;
    };

    FILE * fp = fopen("test.dat", "a+b");
    struct test test_arr[2] = {{
        "sason sam",
        9
    },{
        "lily",
        4
    }};

    fwrite(test_arr, sizeof(struct test), 2, fp);
}

void __test_read_to_struct__(void)
{
    struct test {
        char name[20];
        int len;
    };
    FILE * fp = fopen("test.dat", "a+b");
    rewind(fp);
    struct test test_arr[2];
    struct test * p_te = test_arr;
    fread(&test_arr[0], sizeof(struct test), 2, fp);

    printf("%s %d\n", p_te->name, p_te->len);
    p_te++;
    printf("%s %d\n", p_te->name, p_te->len);
}

void __union_first_known__(void)
{
    union test_union {
        char letter;
        int len;
        double score;
    };

    union test_union a = {.letter = 'c'};
    union test_union b = a;
    union test_union * p_t_u = &b;
    putchar(p_t_u->letter);
}

void __test_anonymous_union__(void)
{
    union test_union {
        char letter;
        int len;
        double score;
    };

    union test_union * p_t_u = &(union test_union) {'d'};
    putchar(p_t_u->letter);
}

void __test_struct_anonymous_struct_member__(void)
{
    struct test {
        // char letter;
        struct {
            char letter;
        };
    } test_s = {
        // 'o',
        {'h'}
    };

    putchar(test_s.letter);
}

void __test_union_anonymous_union_member__(void)
{
    union test {
        union {char letter; int len;};
    } test_u = {
        {.len = 10}
    };
    putchar(test_u.letter);
}

void __enum_first_known__(void)
{
    enum colors {read = 9, blue, green, yellow, orange};
    enum colors color;
    color = orange;
    short c;
    c = yellow;
    printf("%hd\n", c); 
}

void __union_struct_enum_namespace__(void)
{
    int struct_test;
    struct struct_test {
        int len;
    };
}

void __typedef_first_known__(void)
{
    // unsigned int a = 10;
    // typedef unsigned char BYTE;
    // BYTE a = 'c';
    // BYTE * b = "hello";
    // BYTE c[10] = "world";
    // putchar(a);
    // puts(b);
    // puts(c);
    // printf("%d\n", *b);
}

void __test_unsigned_char__(void)
{
    char c = 0X80;
    unsigned uc = 0X80;
    // unsigned int a = c;
    // unsigned int b = uc;
    // int a = c;
    // int b = uc;
    // printf("%d\n", a);
}

void __test_complex_declaration__(void)
{
    // int d[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // int (*pt_1)[4] = &d[0];
    // int (*pt_2)[3][4] = &d;
    // printf("%p %p %p\n", d, &d, &d[0]);
    // printf("%d\n", (*d)[0]);
}

void toUpper(char *);
void toLower(char *);
int pow_(int);

void toLower(char * a) {
    while(*a) {
        *a = tolower(*a);
        a++;
    }
}
// 函数的地址就是函数名，代表函数对应的第一条指令的地址

void __func_pointer_usage__(void)
{
    void (*pf)(char *);

    // pf = toLower;
    // char string[10] = "HELLO";
    // pf(string);
    // puts(string);

    char string[10] = "hello";
    pf = toUpper;
    (*pf)(string);
    puts(string);
}

typedef void (* FP_VR_CP) (char *);
// f_p/*f_p/Tolower
void __func_pointer_as_arg__(FP_VR_CP f_p, char * string) {
    (*f_p)(string);
    puts(string);
}

// typedef void (* FP_VR_CP)(char *);

int main(int argc, char * argv[]) 
{
    // FP_VR_CP p_f = toUpper;
    // char string[10] = "hello";
    // p_f(string);
    // puts(string);
    // void (*p_f)(char *) = toLower;
    // __func_pointer_as_arg__(p_f, string); 
    // __func_pointer_usage__();
    // void (*p)(char *);
    // p = toUpper;
    // p = toLower;
    // typedef int[5] arr5;
    // typedef int[5] * p_arr5;
    // typedef int[5] * [10] arrp10;
    // int (* p)[5];
    // char * char_return_func_p (int)
    // __test_complex_declaration__();
    // __test_unsigned_char__();
    // __typedef_first_known__();
    // __union_struct_enum_namespace__();
    // __enum_first_known__();
    // __test_union_anonymous_union_member__();
    // __test_struct_anonymous_struct_member__();
    // __test_anonymous_union__();
    // __union_first_known__();
    // __test_read_to_struct__();
    // __test_write_to_file__();

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

    // printf("%d\n", '8');

    // unsigned short usi = 65535;
    // short si = usi;
    // printf("%hd\n", si);

    // printf("%d\n", 13 ^ 11 ^ 7 ^ 1);

    // int a = 8911;
    // show_bytes((char *)&a, sizeof(a));

    // struct namect namect_1;
    // getinfo(&namect_1);
    // makeinfo(&namect_1);
    // showinfo(&namect_1);
    // cleanup(&namect_1);

    // struct namect * p_name = &((struct namect) {"sason", "sam", 8});
    // printf("%s\n", p_name->lname);

    //flexiable array member
    // 伸缩性数组成员必须是结构的最后一个成员
    // 结构中必须至少有一个普通成员
    // 与普通数组声明类似，只不过方括号是空的。

    struct flex {
        double average;
        int count;
        double scores[];
    };

    // sizeof flex => 16 存在内存对齐

    // printf("%zd\n", sizeof(struct flex));

    // struct flex flex_1;
    // printf("%p %p\n", &flex_1, &flex_1.average);  

    struct flex * p_flex, *p_flex_cpy;
    p_flex_cpy = &(struct flex){};
    p_flex = malloc(sizeof(struct flex) + sizeof(double) * 5); 
    p_flex->count = 5;
    // p_flex++;
    // printf("%d\n", p_flex->count); 
    for(int i = 0;i < p_flex->count;i++) {
        p_flex->scores[i] = i * 2.0;
    }

    // struct {char name[20];};

    // *p_flex_cpy = *p_flex;
    // printf("%.2f\n", p_flex_cpy->scores[10]);

    // FILE * fp = fopen("test", "a+b");
    // char buf[1204] = "evil";
    // rewind(fp);
    // fgets(buf, 1024, fp);
    // fputs(buf, fp);

    // struct test test_array[2];
    // struct test * test_pp = &test_array[0];


    // struct test * t1, * t2;
    // t1 = malloc(sizeof(struct test));
    // t1->a[0] = 10;
    // t1->a[1] = 11;

    // t2 = &((struct test) {});
    // *t2 = *t1;
    // printf("%d\n", t2->a[1]);

    // typedef struct{
//      short s; 
//      char  c1;
//      int   i;
//      char  c2; 
//  }T_FOO;


//     T_FOO a; 
//     printf("s -> %d,c1 -> %d, i -> %d, c2 -> %d\n",
//     (unsigned int)&a.s  - (unsigned int)&a,  
//           (unsigned int)&a.c1 - (unsigned int)&a,
//           (unsigned int)&a.i  - (unsigned int)&a,
//           (unsigned int)&a.c2 - (unsigned int)&a);

    return 0;
}

// 传递结构可以在结构体积比较小的情况下，传递指针更常用