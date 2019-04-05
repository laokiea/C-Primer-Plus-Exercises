#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#define INT_BITS 33
char * i2b(int num)
{
    static char bits[INT_BITS];

    int f = 0x1;
    for(int i = INT_BITS - 2;i >= 0;i--,f <<= 1) {
        bits[i] = num & f ? '1' : '0';
    }

    return bits;
}

int _exec_1_(char * bits)
{
    int f = 0x1;
    int num = 0;
    for(int c = strlen(bits) - 1;c >= 0;c--) {
        num += (bits[c] - '0') * f;
        f <<= 1;
    }
    return num;
}

void _exec_2_(char ** argv) 
{
    int size = strlen(argv[1]);
    char bits_and[size + 1];
    char bits_or[size + 1];
    char bits_neg_or[size + 1];
    for(int i = 0;i < size;i++) {
        bits_and[i] = (argv[1][i] + argv[2][i]) == '1' * 2 ? '1' : '0';
        bits_or[i] = (argv[1][i] + argv[2][i]) >= '1' + '0' ? '1' : '0';
        bits_neg_or[i] = (argv[1][i] + argv[2][i]) == '1' + '0' ? '1' : '0';
    }

    printf("& : %s, | : %s, ^ : %s\n", bits_and, bits_or, bits_neg_or);
}

int _exec_3_(int num)
{
    int f = 0x1;
    int open_bit_count = 0;
    int size = CHAR_BIT * sizeof(num);
    while(size--) {
        (num & f) && (open_bit_count++);
        f <<= 1;
    }
    return open_bit_count;
}

int _exec_4_(int num, int pos) {
    int f = 0x1 << (pos - 1);
    return num & f ? 1 : 0;
} 

char * _exec_5_(int num, int x) 
{
    int msb_bit_count = CHAR_BIT * sizeof(num) - 1;
    for(int i = 0;i < x;i++) {
        int ls = num >> msb_bit_count;
        num <<= 1;
        num += ls;
    }
    char * bits = i2b(num);
    return bits;
}

#define ALIGN_LEFT 0x0
#define ALIGN_CENTER 0X1
#define ALIGN_RIGHT 0X2
char *aligns[3] = {"left", "center", "right"};

typedef struct {
    unsigned int font_id : 8;
    unsigned int font_size : 7;
    bool bold : 1;
    unsigned int : 4;
    unsigned int align : 2;
    bool italic : 1;
    bool underline : 1;
} FONT, * FONT_BIT_P;
typedef void (*FONT_P_FUNCS[6])(FONT_BIT_P);

void _exec_6_print_(FONT_BIT_P fp) {
    printf("ID SIZE ALIGNMENT   B   I   U\n%2d %4d %9s   %s %s %s\n\n", fp->font_id, fp->font_size, aligns[fp->align], fp->bold ? "ON" : "OFF", fp->italic ? "ON" : "OFF", fp->underline ? "ON" : "OFF");

    printf("Enter choice\n%-20s%-20s%-20s\n%-20s%-20s%-20s\nq)quit\n\n", "f)change font", "s)change size", "a)change alignment", "b)toggle bold", "i)toggle italic", "u)toggle underline");
}

void _exec_6_a_(FONT_BIT_P fp) 
{
    
}

void _exec_6_b_(FONT_BIT_P fp) 
{

}

void _exec_6_i_(FONT_BIT_P fp) 
{

}

void _exec_6_u_(FONT_BIT_P fp) 
{

}

void _exec_6_f_(FONT_BIT_P fp) 
{
    puts("Input font id");
    unsigned int id;
    if(scanf("%u", &id) == 1) {
        fp->font_id = id;
    }
}

void _exec_6_s_(FONT_BIT_P fp) 
{
    puts("Input font id");
    unsigned int size;
    if(scanf("%u", &size) == 1 && size >=0 && size <= 127) {
        fp->font_size = size;
    }
}

void _exec_6_(void)
{
    FONT_P_FUNCS funcs[6] = {_exec_6_f_, _exec_6_s_, _exec_6_a_, _exec_6_b_, _exec_6_i_, _exec_6_u_};

    FONT font;
    font.font_id = 1;
    font.font_size = 12;
    font.align = ALIGN_LEFT; 
    font.bold = 0; 
    font.italic = 0; 
    font.underline = 0;  

    _exec_6_print_(&font);  

    char choice;
    while(scanf("%c", &choice) == 1 && choice != 'q') {
        while(getchar() != '\n');
        switch(choice) {
            case 'f':
            funcs[0](&font);
            break;

            case 's':
            funcs[1](&font);
            break;

            case 'a':
            funcs[2](&font);
            break;

            case 'b':
            funcs[3](&font);
            break;

            case 'i':
            funcs[4](&font);
            break;

            case 'u':
            funcs[5](&font);
            break;
        }
        _exec_6_print_(&font);
    }    
}

int main(int argc, char ** argv)
{
    _exec_6_();
    // struct u {int a;} f;
    // struct u * p = &f;
    // scanf("%d", &p->a);

    // puts(_exec_5_(8, 2));

    // printf("%d\n", _exec_4_(7, 2));
    // printf("%d\n", _exec_3_(8));

    // _exec_2_(argv);

    // char bits[] = "01001001";
    // printf("%d\n", _exec_1_(bits));

    // unsigned a = 0;
    // unsigned b = 1;
    // unsigned c = a - b;
    // char * d = (char *)&c;
    // // printf("%u\n", c);
    // for(int i = 0;i < sizeof(c);i++) {
    //     printf("%x ", d[i]);
    // }

    return 0;
}