#include<stdio.h>
#include<string.h>
#define PI 3.14
#define MONTHS 12

void get_binary(int n, int times);
int _pow(int n, int times);
void to_binary(unsigned long n);
void toLowerCase(char* str);
void intchage(int *a, int *b);

int main(void) {
	// get_binary(200, 0);
	// to_binary(200);
	
	// char *str = "Hello";
	// toLowerCase(str);

	// int a = 20;
	// int *ptr;
	// int val;
	// ptr = &a;
	// val = *ptr;
	// printf("%d\n", val);

	float * pi; // pi is a pointer and its value is address and *pi represent a value and type of value is int
	float * pi2;
	float a = 20,b = 2 * PI;
	// pi = &a; // 0x2acb5f6d1e pi zhixiang a de dizhi, *pi jiushi zhege dizhi kongjianshang cunchun de zhi
	// b = *pi;
	// pi2 = &b;
	// pi2 = pi; // *pi2 = *pi , pi = pi2
	// *pi = 2;

	// printf("%f\n", *pi);
	// printf("%f\n", *pi2);
	// printf("%p\n", pi);
	// printf("%p\n", pi2);

	// int x = 5, y = 10;
	// // int * px, * py;
	// // px = &x;
	// // py = &y;
	// intchage(&x, &y);
	// printf("x = %d %p\n", x, &x);
	// printf("y = %d\n %p", y, &y);

	const int month[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};

	return 0;
}

void get_binary(int n, int times) {
	int div, mod;
	div = n / _pow(2, times);

	mod = div % 2;
	if(div >= 2) {
		get_binary(n, times + 1);
	}
	printf("%d", mod);
}

int _pow(int n, int times) {
	int i = 0;
	int count = 1;
	if(times > 0) {
		for(i;i < times;i++) {
			count *= n;
		}
	}

	return count;
}

void to_binary(unsigned long n) {
	int mod;
	mod = n % 2;
	if(n >= 2) {
		to_binary(n / 2);
	}
	putchar(mod == 0 ? '0' : '1');
}

void toLowerCase(char* str) {
    int i,o;
    char newstr[200];
    for(i = 0;i < strlen(str);i ++) {
    		o = str[i];
        if(o > 65 && o < 90) {
        	  o = str[i] + 32;
        }
        newstr[i] = o;
    } 
    printf("%s\n", newstr);
}

void intchage(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}