#include<stdio.h>
#define SIZE 5
#define MONTHS 12
#define YEARS 5

int sum(int pti[], int n);
int sum_pti(int * array_first, int * array_end);

int main(void) {
	
	// int months[MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// // int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30};
	// int i = 0;

	// for(;i < sizeof days / sizeof days[0];i++) {
	// 	printf("Month %d has %d days\n", i, days[i]);
	// }

	//designated initializer
	// int days[MONTH] = {31, 28, [5] = 30, [0] = 30};
	// int days[5] = {1, 2, 3, 4};
	// for(;i < sizeof days / sizeof days[0];i++) {
	// 	printf("Month %d has %d days\n", i, days[i]);
	// }

	// int months[5];
	// months[5] = days[5];
	// printf("%d\n", days[5]);

	// int v1 = 40;
	// int v2 = 80;
	// int days[SIZE];

	// for(;i <= SIZE;i++) {
	// 	days[i] = 2 * i;
	// }

	// printf("v1 : %d , v2 : %d\n", v1, v2);
	// printf("index -1 : %d , index 4 : %d\n", days[-1], days[4]);

	// printf("p1 : %p , p2 : %p\n", &v1, &v2);
	// printf("index -1 : %p , index 4 : %p\n", &days[-1], &days[4]);

	// int m = 7;
	// int days[m];

	// for(;i < m;i++) {
	// 	printf("Month %d has %d days\n", i, days[i]);
	// }

	//const float rain[YEARS][MONTHS] = {
	// 	{4.3, 4.3, 4.5, 4.3, 5.6, 6.7,4.5, 3.4, 3.5, 3.6, 5.1, 6.3},
	// 	{4.2, 4.3, 4.5, 4.3, 3.6, 6.7,4.5, 2.4, 3.5, 3.6, 5.1, 6.3},
	// 	{2.3, 2.3, 4.2, 3.3, 5.61, 3.7,4.6, 3.4, 3.8, 3.6, 5.2, 6.3},
	// 	{4.3, 4.3, 4.5, 4.3, 5.6, 6.7,4.5, 3.5, 3.5, 3.6, 5.1, 6.4},
	// 	{2.3, 1.3, 2.5, 1.3, 2.6, 4.7,4.2, 2.4, 3.5, 3.6, 5.1, 3.3}
	// };

	// float m = 0.0,n;
	// int i,j;
	// for(i = 0;i < YEARS;i++) {
	// 	for(j = 0,n = 0.0;j < MONTHS;j++) {
	// 		n += rain[i][j];
	// 	}
	// 	m += n;
	// }

	// printf("thr total rain in 5 years: %.2f\n", m);
	// printf("Jan   Feb   Mar   Apr   May   Jun   Jul   Agu   Sep   Oct   Nov   Dec \n");

	// for(j = 0;j < MONTHS;j++,n = 0.0) {
	// 	for(i = 0;i < YEARS;i++) {
	// 		n += rain[i][j];
	// 	}
	// 	printf("%.1f  ", n);
	// }
	// printf("\n");

	// int i,j;
	// int sqrt[2][3] = {2,3,4,8,99};
	// for(i = 0;i < 2;i++) {
	// 	for(j = 0;j < 3;j++) {
	// 		printf("%d ", sqrt[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("%p\n", sqrt);

	// printf("%d\n", (sqrt == &sqrt[0][0]));

	// int * pti;
	// int i = i;
	// pti = &i;
	// printf("%p\n", pti);
	// printf("%p\n", &pti);

	// short dates[SIZE];
	// short * pts;

	// double bills[SIZE];
	// double * ptf;

	// ptf = bills;
	// pts = dates;

	// printf("%23s %15s\n", "short", "double");
	// for(i = 0;i < SIZE;i++) {
	// 	printf("pointers + %d: %10p %10p\n", i, pts + i, ptf + i);
	// }

	// int dates[SIZE] = {1,2,3,4};
	// int * pti;
	// pti = dates;
	// printf("%d %d\n", dates[1], pti[1]);

	int sums[SIZE] = {1, 2,4, 8, 16};
	// int *p, *p_e;
	// p = sums;
	// p_e = p + SIZE;
	// // printf("%p %p %p %p %p\n", sums, sums+1, sums+2, sums+3, sums+4);
	// while(p < p_e) {
	// 	printf("%p\n", p++);
	// }

	// printf("%d\n", sum(sums, SIZE));
	// int * pti;
	// pti = sums;
	// printf("%d %d %d %d\n", pti[2], sums[2], *(sums + 2), *(pti + 2));
	// printf("%zd %zd %zd\n", sizeof pti, sizeof *pti, sizeof sums);
	// printf("%d\n", sum_pti(sums, sums+SIZE));


	// float fa = 1234567899.67;
	// printf("%.2f\n", fa);

	int * pt1, * pt2, * pt3;

	pt1 = sums;
	pt2 = &sums[1];

	printf("\npt1 = %p, *pt1 = %d, &pt1 = %p\n", pt1, *pt1, &pt1);

	// pointer add
	pt3 = pt1 + 4;
	printf("\npt1 + 4 = %p, *(pt1 + 4) = %d\n", pt3, *pt3);

	// dizeng zhizhen 
	pt1++;
	printf("\nvalues after pt1++:\n");
	printf("pt1 = %p, *pt1 = %d, &pt1 = %p\n", pt1, *pt1, &pt1);

	// dijian zhizhen
	pt2--;
	printf("\nvalues after pt1--:\n");
	printf("pt2 = %p, *pt2 = %d, &pt1 = %p\n", pt2, *pt2, &pt2);

	--pt1;
	++pt2;
	printf("\n%p %p %p %p\n", pt1, pt2, sums, sums+2);

	// one pointer sub another pti
	printf("\nsubtracting one pointer from another\n");
	printf("pt1 = %p pt2 = %p pt2 - pt1 = %d\n", pt1, pt2, pt2 - pt1);

	//one pti sub a int
	// printf("\npt1 = %p pt1 -- = %p\n", pt1, pt1--);

	return 0;
}

int sum(int * pti, int n) {
	printf("%p\n", pti);
	int i;
	int sum = 0;
	for(i = 0;i< n;i++) {
		sum += pti[i];
	}

	return sum;
}

int sum_pti(int * array_first, int * array_end) {
	int sum = 0;
	while(array_first < array_end) {
		sum += *array_first;
		array_first++;
	}

	return sum;
}

// 数组可以不初始化，但是值会从相同地址上的旧值，或者在不同的存储级别下会设置成0
// 数组元素可以比项数少，其余的会被初始化为0
// 但是不可以比项数多，报错
// 也可以不指定项数初始化，编译器会自动确定大小
// 可以指定初始化器，int days[10] = {[3] = 20};
// 数组的方括号只能是整形常量, C99之后允许变长数组，即int days[m]

// yiyuan * de youxianji dayu + -