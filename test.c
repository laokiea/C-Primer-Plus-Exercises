#include<stdio.h>
void func1(int * a);
int main(void){
	// FILE * fp;
	// char a;

	// fp = fopen("http://www.baidu.com", "r");
	// fp == NULL && printf("null fp");

	// a = fgetc(fp);
	// putchar(a);

	int a = 20;
	func1(&a);

	return 0;
}

void func1(int * a){
	printf("%d\n", *a);
}