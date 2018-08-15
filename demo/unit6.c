#include<stdio.h>
void exec1(void);

int main(void) 
{
	exec1();
	return 1;
}

void exec1(void) {
	int sum;
	int input;
	int status;
	char c_a;

	sum = 0;
	status = scanf("%d", &input);
	while(status == 1) {
		sum += input;
		status = scanf("%d", &input);
	}
	printf("%d", sum);
}