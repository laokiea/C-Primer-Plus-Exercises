#include<stdio.h>
#define SIZE 5
#define MONTHS 12
#define YEARS 5

int sum(int pti[], int n);
int sum_pti(int * array_first, int * array_end);
void add_to(double * ar, int n, double v);
void show_array(const int * array);
void show_array_1(int array[]);

#define COLS 4
#define ROWS 3
// int sum2d(int (* pt)[COLS]);
// int sum2d(int pt[][COLS]);
// int sum2d(int rows, int cols, int ar[rows][cols]);
int sum2d(int, int, int ar[*][*]);
void toset(int, int, int ar[*][*]);

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

	// int sums[SIZE] = {1, 2,4, 8, 16};
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

	// int * pt1, * pt2, * pt3;

	// pt1 = sums;
	// pt2 = &sums[1];

	// printf("\npt1 = %p, *pt1 = %d, &pt1 = %p\n", pt1, *pt1, &pt1);

	// // pointer add
	// pt3 = pt1 + 4;
	// printf("\npt1 + 4 = %p, *(pt1 + 4) = %d\n", pt3, *pt3);

	// // dizeng zhizhen 
	// pt1++;
	// printf("\nvalues after pt1++:\n");
	// printf("pt1 = %p, *pt1 = %d, &pt1 = %p\n", pt1, *pt1, &pt1);

	// // dijian zhizhen
	// pt2--;
	// printf("\nvalues after pt1--:\n");
	// printf("pt2 = %p, *pt2 = %d, &pt1 = %p\n", pt2, *pt2, &pt2);

	// --pt1;
	// ++pt2;
	// printf("\n%p %p %p %p\n", pt1, pt2, sums, sums+2);

	// // one pointer sub another pti
	// printf("\nsubtracting one pointer from another\n");
	// printf("pt1 = %p pt2 = %p pt2 - pt1 = %d\n", pt1, pt2, pt2 - pt1);

	//one pti sub a int
	// printf("\npt1 = %p pt1 -- = %p\n", pt1, pt1--);

	// int i = 10;
	// int * pt = &i;

	// printf("%p\n", pt);
	// pt++;
	// printf("%d %p\n", *pt, pt);

	// char T[2] = {'a', 'b'};
	// printf("%p %p\n", T, &T[1]);

	// int * pt1;
	// int * pt2;
	// int one[2] = {100, 200};
	// int two[2] = {300, 400};
	// pt1 = one;
	// pt2 = two;
	// printf("pt1 : %p, pt2 : %p, %d\n", pt1, pt2, pt1 > pt2);

	// char a = 'a';
 // 	char * cpt1;
 // 	cpt1 = &a;
 // 	*cpt1 = 'b';
 // 	printf("%c\n", a);

	// int urn[3];
	// int * pt1, * pt2;
	// pt2 = urn + 2;
	// printf("%p %p\n", urn, pt2);

	// double add[2] = {1.2, 4.6};
	// const double * dpt;
	// dpt = add;
	// dpt[1] = 4.7;
	// printf("%f %f %f %f", add[0], dpt[0], *(add + 1), *(dpt+1));
	// add_to(add, 2, 1);
	// printf("%f %f\n", add[0], add[1]);

	// int a[2] = {1 ,2 };
	// int * p1, * p2;
	// p1 = &a[1];
	// p2 = a+1;
	// printf("%p %p\n", p1, p2);

	// const int c_sums[2] = {3, 5};
	// const int * p1;
	// p1 = sums; // ok
	// p1 = c_sums; //ok
	// p1 = &sums[1]; // ok

	// const int * const pc = sums;
	// *pc = 10;
	// printf("%d\n", sums[0]);
	// int const * const pi = c_sums;
	// pi = sums;

	int zippo[4][2] = {{1,2},{3,4},{5,6},{7,8}};
	// printf("%p\n", &zippo[0][0]);
	// printf("%p\n", zippo[0]);

	// printf("%p\n", &zippo[0]);

	// zippo[0] = &zippo[0][0] = 0xa1;
	// &zippo[0] = 0xb1;
	// zippo = &zippo[0]	 = 0xb1;

	// show_array(sums);
	// show_array(c_sums);

	// show_array_1(c_sums);

	// zippo = &zippo[0];
	// &zippo[0] = &zippo[0][0];
	// zippo + 1 = &zippo[1] = &zippo[1][0];
	// printf("zippo = %p, zippo + 1 = %p, &zippo[0][1] = %p\n\n", zippo, zippo + 1, &zippo[1][0]); 

	// zippo[0] = &zippo[0][0] 
	// zippo[0] + 1  = &zippo[0][1] 
	// printf("zippo[0] = %p, zippo[0] + 1 = %p , &zippo[0][1] = %p\n\n", zippo[0], zippo[0] + 1, &zippo[0][1]);

	// *zippo = zippo[0] = &zippo[0][0]
	// printf("*zippo = %p, &zippo[0][0] = %p, *zippo + 1 = %p, &zippo[0][1] = %p\n\n", *zippo, &zippo[0][0], *zippo + 1, &zippo[0][1]);

	// 1
	// printf("zippo[0][0] = %d\n\n", zippo[0][0]);

	// 1
	// printf("*zippo[0] = %d\n\n", *zippo[0]);

	// 1
	// printf("**zippo = %d\n\n", **zippo);

	// 6
	// printf("zippo[2][1] = %d\n\n", zippo[2][1]);

	// zippo =  &zippo[0]
	// zippo + 2 = &zippo[2]; // its value is a address
	// *(zippo + 2) = zippo[2]
	// zippo[2] = &zippo[2][0]
	// zippo[2] + 1 = &zippo[2][0] + 1 = &zippo[2][1]
	// 6
	// printf("*(*(zippo + 2) + 1) = %d\n\n", *(*(zippo + 2) + 1));
	//
	// printf("**(zippo + 2) = %d, *(zippo+2)[0] = %d\n\n", **(zippo + 2), *(zippo + 2)[0]);

	// int sums[4]  = {1,2,3,4};
	// int * pi = sums;
	// printf("%d\n", pi[1]);

	// int (* pz)[2] = zippo;
	
	//pz = &zippo[0][0]
	// pz = &zippo[0] = &zippo[0][0]
	// printf("pz = %p, &pz[0][0] = %p, pz + 1 = %p, &pz[1][0] = %p\n\n", pz , &pz[0][0], pz + 1, &pz[1][0]);

	// pz[0] = &pz[0][0]
	// pz[0] + 1 = &pz[0][1]
	// printf("pz[0] = %p, pz[0][0] = %p, pz[0] + 1 = %p, &pz[0][1] = %p\n\n", pz[0], &pz[0][0], pz[0] + 1, &pz[0][1]);

	// int sums [4] = {1,2,3,4};
	// int * pi = sums;
	// printf("sums = %p, &sums = %p, &sums[0] = %p, pi = %p, &pi = %p\n\n", sums, &sums, &sums[0], pi, &pi);

	// *pz = pz[0]  = zippo[0] = &zippo[0][0]
	// *pz + 1 = &zippo[0][1]
	// printf("*pz = %p, &pz[0][0] = %p, *pz + 1 = %p, &pz[0][0] = %p\n\n", *pz, &pz[0][0], *pz + 1, &pz[0][1]);

	// * zippo[0] = * &zippo[0][0] = 1
	// printf("*pz[0] = %d\n\n", *pz[0]);

	// **pz = * *pz = * pz[0] = * &pz[0][0] = pz[0][0]
	// printf("**pz = %d\n\n", **pz);

	// pz + 2 = &pz [2] 
	// * (pz + 2) = pz[2] = &pz[2][0]
	// * (pz + 2) + 1 = &pz[2][1]
	// *(*(pz + 2) + 1) = pz[2][1]
	// printf("*(*(pz + 2) + 1) = %d\n\n", *(*(pz + 2) + 1));

	// printf("pz[2][1] = %d, *(*(pz + 2) + 1) = %d\n\n", pz[2][1], *(*(pz + 2) + 1));
	
	// int i = 5;
	// double x;
	// int * pi = &i;
	// double * pd = &x;
	// printf("%p\n", pd);
	// x = i;
	// pd = pi;

	// int p = 1;
	// int * pi = &p;
	// int * *pii = &pi;
	// printf("%d\n", *pi);
	// *pii = 0x7fffe3cc77d0;
	// printf("%d\n", *pi);

	// int i = 9;
	// int *pi;
	// int **pii;
	// pi = &i;
	// pii = &pi;

	// printf("pi = %p, pii = %p\n", pi, pii);

	int * p;
	int * * pp;
	int (*p3)[3];
	int ar1[2][3] = {{1,2,3}, {6,4,5}};
	int ar2[3][2]; // ar2 = &ar2[0]; ar2 + 1 = &ar2[1];

	// 指针的兼容性
	// p = &ar1[0][0]; // ok
	// p = ar1[0]; //ok -> &ar1[0][0]
	// pp = &p; //ok 
	// *pp = &ar1[0]; // wrong -> ar1 = &ar1[0] 3 int bytes
	// *pp = ar2[0];
	// p3 = &ar2[1]; //wrong -> 2 int bytes
	// p3 = ar2[1]; // wrong -> &ar2[1][0]
	// p = ar2[1]; //ok
	// p3 = ar1 + 1; // &ar1[1] = &ar[1][0]
	// printf("%d\n", **p3); 
	// printf("ar1 + 1 = %p, &ar1[1][0] = %p\n", ar1 + 1, &ar1[1][0]);

	// int x = 10;
	// const int y = 20;
	// int * px = &x;
	// const int * py = &y;
	
	// px = py;
	// *px = 15;
	// printf("%d\n", *py);
	// py = px;
	// *py = 15;

	// int x = 10;
	// const int **pp2;
	// int *p1 = &x;
	// pp2 = &p1; // pp2 指向一个int指针的地址，*pp2是该int指针的值，也是该指针指向整形变量的地址

	// int x = 10;
	// int * px = &x;
	// int **p2 = &px;

	// printf("&px = %p,*p2 = %p, &x = %p\n", &px, *p2, &x);

	int junks[ROWS][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int t_junks[4] = {1,2,4,5};
	int sums = 0;
	sums = sum2d(ROWS, COLS, junks);
	// printf("%d\n", sums);

	toset(ROWS, COLS,junks);
	// printf("%d\n", junks[0][0]);

	int *pt = (int []){1,2,4}; //ok
	int (* pt2)[4] = (int [][4]){{1,2,3,4},{5,6,7,8},{9,10,11,12}}; // ok
	// int (* pt2)[4] = (int [][]){blabla}; // wrong

	// int *pt1 = {1,2,4};// wrong not a compound literal

	return 0;
}

void toset(int rows, int cols, int ar[rows][cols]) {
	ar[0][0] = 10;
}

// int sum2d(int pt[][COLS]) 
// {
// 	int sums = 0,i,j;
// 	for(i = 0;i < ROWS;i++) {
// 		for(j = 0;j < COLS;j++) {
// 			sums += pt[i][j];
// 		}
// 	}
// 	return sums;
// }

int sum2d(int rows, int cols, int ar[rows][cols]) {
	int i,j,sums;
	sums = 0;

	for(i = 0;i < rows;i++) {
		for(j = 0;j < cols;j++) {
			sums += ar[i][j];
		}
	}

	return sums;
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

void add_to(double ar[], int n, double v)
{
	int i = 0;
	for(;i < n;i++) {
		ar[i] += v;
	}
}

void show_array(const int * array) {

}

void show_array_1(int array[]){

}

// 数组可以不初始化，但是值会从相同地址上的旧值，或者在不同的存储级别下会设置成0

// 数组元素可以比项数少，其余的会被初始化为0

// 但是不可以比项数多，报错

// 也可以不指定项数初始化，编译器会自动确定大小

// 可以指定初始化器，int days[10] = {[3] = 20};

// 数组的方括号只能是整形常量, C99之后允许变长数组，即int days[m]

// yiyuan * de youxianji dayu + -

// 如果在函数中不想改变数组的值 声明和原型使用const

// 如果指针声明为const，那么不能改变指针所指向的值，但是可以让指针指向别的地址，比如pt++; pt = &i;

/*
	与其他变量不同，const限定一个指针变量(double const * pd)，因为指针的值是地址，这个地址是可以变的，但是对应地址的值不可变
	但是如果写法改成，double * const pd，那么可以更改指针保存地址指向的值，但是不能更改指针的地址
	另外还可以const限定两次，这样指针指向地址的值和指针指向地址都不可以改变，如const int * const pd
*/

/*
	一个普通指针的地址只能初始化成非const数据的地址，例如
	int sums[2] = {1, 2};
	const int c_sums[2] = {3, 5};
	int * p1;
	p1 = sums; // ok
	p1 = c_sums; // 报错
	因为如果普通指针可以初始化成const数据的地址，那么就可以更改const数据的值
*/

/*
	而一个const限定的指针可以指向const或者非const数据的地址，例如：
	int sums[2] = {1, 2};
	const int c_sums[2] = {3, 5};
	const int * p1;
	p1 = sums; // ok
	p1 = c_sums; //ok
	p1 = &sums[1]; // ok
*/

/*
	对于一个数组,数组的地址和数组首元素的地址相同
	int sums[2] = {1,2};
	&sums == &sums[0] = sums;
*/

/*
定义一个指向多维数组的指针:
int a[m][n] = {};
int (* pi)[n] = a;
n代表了指针递增或递减一次地址跨度为n个类型大小
pi[m][n] = *(*(pi + m) + n);
*/

/*
定义一个变长数组函数声明
void a(int r, int c, int a[r][c]);
*/