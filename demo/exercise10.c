#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define ROWS = 3
#define COLS = 4

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void show(const double ar[], int n);
void show_2(const double ar[][3], int n);

void copy_arr(double target[], double source[], int n);
void copy_ptr(double * target, double * source, int n);
void copy_ptrs(double * target, double *source ,double * last);
int returnIntArrayMaxValue(int * arr, int size);
int returnDoubleArrayMaxValueIndex(double * arr, int size);
double returnDifferOfMaxAndMinInArray(double * arr, int size);
void sortArrayDesc(double * arr, int size);
void copy_arr_2d(double (* target)[5], double source[][5], int size);
void copy_9(int , int , double source[*][*], double (*target)[2]);
void sum_10(int * a, int * b, int * c, int size);
void printdouble_11(int rows,double arr[][5]);
void printdouble_11_1(int cols,double (*arr)[cols]);
void dosomething_13();

int main(void)
{
    // test1();
    // test3();
    // test5();
    // test6();
    // int c[100] = {[5] = 101,[10] = 101, 11, 12, 13};
    // printf("%d\n", c[11]);
    // show((double []){8, 3, 9, 2}, 4);
    // show_2((double[3]){{8,3,9},{5,4,1}}, 2);

    double source[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    // int i = 0;
    // for(;i < 5;i++) {
    //     printf("%f\n", target3[i]);
    // }    

    int arr[7] = {7, 45, 3 , 89, 102, 65, 54};
    int max = returnIntArrayMaxValue(arr, 7);
    // printf("%d\n", max);

    double arr1[5] = {12,67.88888,67.88888,67.88888,67.88888};
    // printf("%d\n", returnDoubleArrayMaxValueIndex(arr1, 5));
    // printf("%d\n", 67.88888 < 67.88888);

    double arr2[3] = {1.256, 786.72, 456,};
    // printf("%f\n", returnDifferOfMaxAndMinInArray(arr2, 3));

    double arr3[10] = {99,56,25,123,176,57,199,1,55,200};
    sortArrayDesc(arr3, 10);
    // int i = 0;
    // for(;i < 10;i++) {
    //     printf("%f\n", arr3[i]);
    // } 

    double target11[2][5];
    double source11[2][5] = {{11,22,43,49,115},{61,72,89,19,10.2}};
    copy_arr_2d(target11, source11, 2);
    // int i = 0,j;
    // for(;i < 2;i++) {
    //     for(j = 0;j < 5;j++) {
    //         printf("%f\n", target11[i][j]);
    //     }
    // }
    // printf("%f\n", *(*(target11 + 1) + 2) );

    int rows = 3;
    int cols = 5;
    double copy_9_source[3][5] = {{1.1,4.2,3.3,5.9,6.01},{1.22,3.3,0.6,9.7,1.8},{0.0,1.2,9.1,7.3,0.5}};
    double copy_9_target[rows][cols];
    copy_9(rows, cols, copy_9_source, copy_9_target);
    // int i = 0,j;
    // for(;i < rows;i++) {
    //     for(j = 0;j < cols;j++) {
    //         printf("%f\n", copy_9_target[i][j]);
    //     }
    //     printf("\n");
    // }

    int size = 4;
    int a[4] = {1,2,3,4};
    int b[4] = {5,6,7,8};
    int c[size];
    sum_10(a, b, c, size);
    // int i = 0;
    // for(;i < size;i++) {
    //     printf("%d\n", c[i]);
    // } 

    int rows_11 = 3;
    int cols_11 = 5;
    double arr_11[3][5] = {{1.1,4.2,3.3,5.9,6.01},{1.22,3.3,0.6,9.7,1.8},{0.0,1.2,9.1,7.3,0.5}};
    // printdouble_11(rows_11, arr_11);
    // printdouble_11_1(cols_11, arr_11);
    // for(int i = 0;i < rows_11;i++) {
    //     for(int j = 0;j < 5;j++) {
    //         printf("%f\n", arr_11[i][j]);
    //     }
    //     printf("\n");
    // }

    dosomething_13();

    return 0;
}

void dosomething_13() {
    int rows = 3,cols = 5;
    double arr[rows][cols];
    double rec,allSum = 0.0;
    double max = 0.0;

    for(int i = 0;i < rows;i++) {
        double sum = 0.0;
        for(int j = 0;j < cols;j++) {
            scanf("%lf", &rec);
            !max && (max = rec) || (max = max < rec ? rec : max);
            *(*(arr + i) + j) = rec;
            sum += rec;
            allSum += rec;
        }
        printf("1 The avarage: %.2f\n", sum / cols);
    }
    printf("\nThe avarage of all number: %.2f\n", allSum / cols * rows);
    printf("\nThe max number: %f\n", max);
}

void printdouble_11_1(int cols,double (*arr)[cols]) {
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < cols;j++) {
            *(*(arr + i) + j) = 2 * *(*(arr + i) + j);
        }
    }
}

void printdouble_11(int rows,double (*arr)[5]) {
    for(int i = 0;i < rows;i++) {
        for(int j = 0;j < 5;j++) {
            *(*(arr + i) + j) = 2 * *(*(arr + i) + j);
        }
    }
}

void sum_10(int * a, int * b, int * c, int size) {
    for(int i = 0;i < size;i++) {
        *c++ = *a++ + *b++;
    }
}

void copy_8() {

}

void copy_9(int rows, int cols, double source[rows][cols], double (*target)[cols]) {
    int i = 0,j = 0;
    for(;i < rows;i++) {
        for(j = 0;j < cols;j++) {
            *((*(target + i)) + j) = source[i][j];
            // target[i][j] = source[i][j];
        }
    }
}

void copy_arr_2d(double (* target)[5], double source[][5], int size) {
    int i = 0;
    for(;i < size;i++) {
        copy_ptr(target[i], source[i], 5);
    }
}

/**
 * bubble sort
 * 
 */
void sortArrayDesc(double * arr, int size) {
    int i = 0,j = 0, temp;
    bool swap = false;
    for(;i < size - 1;i++) {
        for(j = 0;j < size - i -1;j++) {
            if(arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
        if(!swap) {
            break;
        }
    }
}

double returnDifferOfMaxAndMinInArray(double *  arr, int size)
{
    int i =0;
    double max = *arr,min = *arr;

    for(;i < size;i++) {
        if(min > *arr) {
            min = *arr;
        }
        if(max < *arr) {
            max = *arr;
        }
        arr++;
    }

    return max - min;
}

/**
 * return max value in an array 
 * 
 */
int returnIntArrayMaxValue(int * arr, int size) {
    int i = 0,max = *arr;
    // size = CHAR_BIT == 8 ? (sizeof arr) / (sizeof(int)) : 0;

    for(;i < size;i++) {
        (max <= arr[i]) && (max = arr[i]);
    }

    return max;
}

/**
 * return max value index in an array 
 * 
 */
int returnDoubleArrayMaxValueIndex(double * arr, int size) {
    int i = 0,max_index = 0;
    double max = *arr;

    for(;i < size;i++) {
        // (max < *arr) && (max = *arr) && (max_index = i) && (++arr);
        if(max < *arr) {
            max = *arr;
            max_index = i;
        }
        arr++;
    }

    return max_index;
}

/**
 * copy source to target 
 * 
 */
void copy_ptrs(double *target, double *source, double * last) {
    while(source < last) {
        *target++ = *source++;
    }
}

void copy_arr(double target[], double source[], int n) {
    int i = 0;
    for(;i < n;i++) {
        target[i] = source[i];
    }
}

void copy_ptr(double * target, double * source, int n) {
    int i = 0;
    for(;i < n;i++) {
        *target++ = *source++;
    }
}

void show(const double ar[], int n) {
    // do nothing
}

void show_2(const double ar[][3], int n) {
    // do nothing
}

void test1(void)
{
    int i;
    int * pt;
    int ref[] = {8, 4, 0, 2};

    for(i = 0, pt = ref;i < 4;i++,pt++) {
        printf("%d %d\n", ref[i], *pt);
    }
}

void test2(void)
{
    int *pt;
    int ref[2][2] = {{1},{2,3}};
    pt = ref[0];
    printf("%d\n", *pt);printf("%d\n", *(pt+1));
}

void test3(void)
{
    int (*pt)[2];
    int ref[2][2] = {{12},{14,16}};
    pt = ref;

    printf("%d %d\n", **pt, **(pt+1));
}

void test4(void)
{
    int ref[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // ref[2][3]
    printf("%d\n", *((*(ref+2))+3) );

    // ref[2][0]
    // ref+2 = &ref[2]
    // *(ref + 2) = ref[2] = &ref[2][0]
    // **(ref+2) = ref[2][0]
    printf("%d\n", **(ref+2));
    printf("%d\n", *((*(ref+2))+0));

    //ref[0][0]
    printf("%d\n", **ref);
    printf("%d\n", **(ref+0));
}

void test5(void)
{
    int x = 1, y = 2;
    int *a, *b;
    int i = 0;
    a = &x;
    b = &y;

    // 括号的优先级大于*，所以先和括号结合
    // int (*pt)[2] 是一个指向包含多个元素的数组，每个元素都是包含两个int类型值的数组
    // int (*pt)[2] = {{1,2},{2,4}};
    // int (*pt)[2] = {{{3,4},{5,6}},{{1,2},{37,8}}};
    // int *(pt[2]) = {a,b};
    // int (*pt)[2] = (int [][2]){{{1,2},{3,4}},{{5,6},{7,8}}};
    // for(;i < 2;i++) {
    //     printf("%d\n", *pt[i]);
    // }

    // int ref[2][2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}};
    // int (*pt)[2] = ref;

    // pt +1 = &pt[1]
    // * (pt + 1) = pt[1] = &pt[1][0]
    // *(pt+1)+1 = &pt[2][0]
    // printf("%d\n", **(pt + 1));
    // printf("%p\n", &(ref[1][1]));

    // int ref[] = {1,2};
    // printf("%d\n", *(ref+1));

    char (* pt)[2];
    char ca[][2] = {'h','e','l','l','o','d'};
    pt = ca;
    printf("%c\n", *(*(pt+2) + 1));
}

void test6(void)
{
    char a = 'a';
    char b = 'b';
    char *p1 = &a;
    char *p2 = &b;
    char ** psts;
    char *pst[20] = {p1, p2};
    psts = pst;

    printf("%p %p %p\n", pst, &pst[0], psts);
    printf("%c %c %c\n", **(pst + 1), *(pst[1]), **(psts + 1));
}