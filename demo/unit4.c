#include<stdio.h>
#include<string.h>
#include<float.h>
#define BOOK "War and Peace"
void _1(void);
void _2(void);
void _3(void);
void _4(void);
int main(void)
{
	// _1();
	// _2();
	// _3();
	_4();
	return 0;
}

void _1(void)
{
	float cost = 12.99, percent = 80.0;
	printf("This copy of \"War and Peace\" sells for $%.2f\nThat is %%%.f of list.\n", cost, percent);
}

void _2(void)
{
	char name[40];
	scanf("%s", name);
	// printf("%4x", 190);
	printf("%s", name);
}

void _3(void)
{
	char fname[20],lname[20];
	scanf("%s %s", fname, lname);
	printf("%-*d %-*d",strlen(fname), strlen(fname), strlen(lname), strlen(lname));
}

void _4(void)
{
	float f_a = 1.0/3.0;
	double d_a = 1.0/3.0;
	printf("%.6f %.12f %.16f", d_a, d_a, d_a);	
}