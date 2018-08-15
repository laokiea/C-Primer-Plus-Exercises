#include<stdio.h>
#include<math.h>
#define SCALE 10

void _test(void);
void _1(void);
void _exec5_1(void);
void _exec5_2(void);
void _exec5_3(void);
void _exec5_4(void);
void _exec5_5(void);
void _exec5_6(void);
void _exec5_7(void);
int main(void)
{
	// _1();	
	// _test();
	_exec5_7();
	return 0;
}

void _1(void){
	int i = 1;
	while(i < SCALE) {
		int j = 1;
		while(j <= i) {
			printf("%d*%d=%d ", j, i, i*j);
			j++;
		}
		i++;
		printf("\n");
	}
}

void _test(void){
	// printf("%-5.2f", pow(3.3, 2.2));
	// float f_a = 32.111111111111123;
	int sec;
	while (sec > 0) {
		printf("ss");
	}
}


void _exec5_1(void){
	int i = 1;
	float n;
	printf("Watch out! Here come a bunch of fractions!\n");

	while(i++ < 30){
		n = 1/i;
		printf("  %f\n", n);
	}

	printf("That's all , folks!\n");
}

void _exec5_2(void){
	#define FORMAT "%s! C is cool!\n"
	int num = 10;

	printf(FORMAT, FORMAT);
	printf("%d\n", ++num);
	printf("%d\n", num++);
	printf("%d\n", num--);
	printf("%d\n", num);
}

void _exec5_3(void) {
	char c1,c2;
	int diff;
	float num;

	c1 = 'S';
	c2 = 'O';
	diff = c1 - c2;
	num = diff;

	printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num);
}

void _exec5_4(void) {
	#define TEN 10
	int n = 0;
	while(n++ < TEN) 
		printf("%5d", n);
	printf("\n");
}

void _exec5_5(void){
	#define SEVEN 7
	int i = 0;
	char c_a = 'a';
	while (i++ < SEVEN) {
		printf("%2c", c_a++);
	}
	printf("\n");
}

void _exec5_6(void){
	// int c = 0;
	// while(++c < 3)
	// 	printf("%4d", c);
	// int x = 100;
	// while (x++ < 103) 
	// 	printf("%4d\n", x);
	// printf("%4d\n", x);

	char ch = 's';
	while (ch < 'w') {
		printf("%c", ch);
		ch++;
	}
	printf("%c\n", ch);
}

void _exec5_7(void){
	int n = 0;
	while(n < 5)
		printf("%s\n", "COMPUTER BYTES DOG");
		n++;
	printf("That's all\n");
}