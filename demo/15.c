#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdalign.h>

void _test_neg_overflow_(void)
{
    char a = -128;
    printf("%d\n", ~a);
}

#define MASK_1 3
void _test_set_bit_(void)
{
    // 将掩码中为1的位设置到操作数中，其他位不变
    unsigned char a = 14; // 0000 1110 | 0000 0011
    // a |= MASK_1;
}

void _test_unset_bit_(void)
{
    // 将掩码中为1的位关闭，其他位不变
    unsigned char a = 14; // 0000 1110 & ~0000 0011
                          // 0000 1110 & 1111 1100
    // a & ~MASK_1;
}

void _test_change_bit_(void)
{
     // 将掩码中为1的位切换，其他位不变
     // 1 ^ 0 = 1 1 ^ 1 = 0
     // 1 ^ a = ~a;
    unsigned char a = 14; // 0000 1110 ^ 0000 0011
    // a ^= MASK_1;
}

void _test_check_bit_(int n)
{
    // 检查第2位是否为1 -> 0000 0100 & 0000 1000
    unsigned char a = 14;
    if((a & 8) == 8) {
        puts("work");
    }
}

void _pick_color_(void)
{
    unsigned long color = 0x16f87cd6;
    unsigned char red = color & 0xff;
    unsigned char green = (color >> 8) & 0xff;
    unsigned char blue = (color >> 16) & 0xff;
}

char * decbin(int dec)
{
    static char bits[sizeof(dec) * CHAR_BIT + 1];
    for(int i = sizeof(dec) * CHAR_BIT - 1,mask = 1;i >= 0;i--,mask <<= 1) {
        bits[i] = (dec & mask) ? '1' : '0';
    }

    return bits;
}

// char * _change_low_n_bit_(int dec, int n, char * bits)
// {

// }

void _aligned_alloc_test_(void)
{
    // int * p = (int *)aligned_alloc(1024, 2 * 1024);
    // printf("%p %p\n", &p[0], &p[1]);
    int * p = (int *)malloc(sizeof(int) * 2);
    printf("%p %p\n", &p[0], &p[1]);
}

int main(int argc, char ** argv) 
{
    // unsigned char a = 130;
    // printf("%zd\n", sizeof(a << 1));
    // _aligned_alloc_test_();
    // _Alignas(64) int a;
    // char b;
    // double c;
    // printf("%p\n", &a);
    // printf("%p\n", &b);
    // printf("%p\n", &c);
    // struct {
    //     int a : 1;
    //     // unsigned int : 1;
    //     // int c : 32;
    //     int d : 1;
    // } p;
    // printf("%zd\n", _Alignof(double));
    // char bits[32] = {'0'};
    // puts(_change_low_n_bit_(7, 3, bits));
    // puts(decbin(-2));
    // _test_check_bit_(2);
    // _test_neg_overflow_();
    // 01110010 & ~00000010 = 01110010 & 11111101
    return 1;
}