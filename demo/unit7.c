#include<stdio.h>
#include<stdbool.h>
// #include<stdlib.h>
#define BASE_SALARY 1000

char get_choice(void);
int main() {
	// int oddSum,i, oddCount,evenCount,evenSum;
	// oddCount = oddSum = evenCount = evenSum = 0;
	// while(scanf("%d", &i) == 1 && i) {
	// 	if(i % 2 == 0) {
	// 		evenCount++;
	// 		evenSum+=i;
	// 	}
	// 	else {
	// 		oddCount++;
	// 		oddSum+=i;
	// 	}
	// }
	// printf("evenCount : %d, oddCount: %d, and even average : %d, odd average: %d", evenCount, oddCount, evenSum/evenCount, oddSum/oddCount);

	// char ch;
	// int exchangeCount = 0;
	// while( (ch = getchar()) != '#' ) {
	// 	if(ch == '.' || ch == '!') 
	// 		exchangeCount++;
	// }
	// printf("%d", exchangeCount);

	// char ch;
	// int exchangeCount = 0;
	// while( (ch = getchar()) != '#' ) {
	// 	switch(ch) {
	// 		case '.':
	// 		case '!':
	// 		exchangeCount++;
	// 		break;
	// 	}
	// }
	// printf("%d", exchangeCount);

	// char ch,ex;
	// int count = 0;
	// while( (ch = getchar()) != '#' ) {
	// 	if(ex == 'e' && ch == 'i') {
	// 		count++;
	// 	}
	// 	ex = ch;
	// }
	// printf("%d", count);

	// float tax,real,sum, hours;
	// tax = real = sum = hours = .0;
	// int select;
	// printf("Enter thre number to select one:\n %-20s%-20s\n %-20s%-20s\n", "1) $8.75/hr", "2) 9.33/hr","3) 10.00/hr","4) 11.20/hr");
	// if(scanf("%d", &select) == 1 && select >= 1 && select <= 4) {
	// 	printf("input your hours:\n");
	// 	if(scanf("%f", &hours) == 1) {
	// 		if(hours > 40) {
	// 			hours = 40 + (hours - 40) * 1.5;
	// 		}
	// 		sum = hours * 1000;
	// 		if(sum <= 300) {
	// 			tax = sum * 0.15;
	// 		} else if(sum > 300 && sum <= 450) {
	// 			tax = 300 * 0.15 + (sum - 300) * 0.2;
	// 		} else {
	// 			tax = 300 * 0.15 + 150 * 0.2 + (sum - 450) * 0.25;
	// 		}
	// 		real = sum - tax;
	// 	}
	// 	printf("Sum Salary is %f and Tax is %f and Real Salary is %f", sum, tax ,real);
	// }

	// unsigned int i,j = 2,k;
	// bool f = true;
	// if(scanf("%u", &i) == 1) {
	// 	while(j <= i) {
	// 		k = 2 ;
	// 		while(k*k <= j) {
	// 			if(j % k == 0){
	// 				f = false;
	// 				break;
	// 			} 
	// 			k++;
	// 		}
	// 		if(f) {
	// 			printf("%d\n", j);
	// 		}
	// 		f  = true;
	// 		j++;
	// 	}
	// }

	// int ch;
	// while((ch = getchar()) != EOF) {
	// 	if(ch == '\n') {
	// 		printf("here");
	// 	}
	// 	putchar(ch);
	// } 

	// return type of getchar() is int

	// int ch;
	// char name[50];
	// FILE *fp;

	// scanf("%s", name);
	// fp = fopen(name, "r");
	// if(fp == NULL) {
	// 	printf("open file faild");
	// 	//exit(1);
	// }

	// while((ch = getc(fp)) != EOF) {
	// 	putchar(ch);
	// }

	// fclose(fp);


	// int ch;
	// int row,cols;
	// int i,j;

	// while((ch = getchar()) != '\n') {
	// 	if(scanf("%d %d", &row, &cols) == 2 ) {
	// 		for(i = 0;i < row;i++) {
	// 			for(j = 0;j < cols;j++) {
	// 				printf("%c", ch);
	// 			}
	// 			printf("\n");
	// 		}
	// 	}
	// 	printf("keep input");
	// }

	// int ch;
	// long input;

	// while(scanf("%ld", &input) != 1) {
	// 	while((ch = getchar()) != '\n') 
	// 		putchar(ch);
	// 	printf(" is not a long integer, input again\n");
	// }

	char ch;
	ch = get_choice();
	putchar(ch);

	return 0;
}

char get_choice(void) {
	char ch;

	ch = getchar();
	while( (ch = getchar()) && (ch < 'a' || ch > 'd') && ch != 'q') {
		printf("wrong input!\n");
	}

	return ch;
}
