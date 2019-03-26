#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int __exec_4__(void)
{
    // 编译时定义count, count只能被该函数访问
    static int count = 0;
    count++;

    return count;
}

int * __exec_5__(int num)
{
    int * pti = malloc(sizeof(int) * num);
    if(pti == NULL) {
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    for(int i = 0;i < num;i++) {
        pti[i] = rand() % 100 + 1;
    }

    for(int i = 0;i < num;i++){
        int max = i;
        for(int j = i + 1;j < num;j++) {
            if(pti[j] > pti[max]) {
                max = j;
            }
        }

        if(max != i) {
            int temp;
            temp = pti[i];
            pti[i] = pti[max];
            pti[max] = temp;
        }
    }

    return pti;
}

void __exec_6__(void)
{
    int * pti = calloc(10, sizeof(int));

    srand(time(0));
    for(int i = 0;i < 1000;i++) {
        pti[rand() % 10 + 1]++;
    }

    for(int i = 1;i <= 10;i++) {
        printf("%d appears %d times. \n", i, pti[i]);
    }

    free(pti);
}

int * make_array(int num, int value)
{
    if(num > 0) {
        int * pti = (int *) malloc(num * sizeof(int));
        if(NULL != pti) {
            for(int i = 0;i < num;i++) {
                pti[i] = value;
            }
            return pti;
        }
    }

    return NULL;
}

void show_array(const int arr[], int n) 
{
    for(int i = 0;i < n;i++)
    {
        printf("%d\n", arr[i]);
    }
}

void __exec_9__(void)
{
    int num;
    puts("How many words do you want to enter:");
    if(scanf("%d", &num) == 1) {
        char ** words = (char **) malloc(sizeof(char *) * num);
        if(words != NULL) {
            printf("Enter %d words:\n", num);
            for(int i = 0;i < num;i++) {
                char * tmp_word = (char *) malloc(sizeof(char) * 20);
                // static char tmp_word[20];
                // char tmp_word[20];
                if(scanf("%s", tmp_word) == 1) {
                    // printf("%p\n", tmp_word);
                    // strncpy(words[i], tmp_word, 125);
                    words[i] = tmp_word;
                }
                printf("%p\n", tmp_word);
                free(tmp_word);
                printf("%p\n", tmp_word);
                puts(words[i]);
            }

            puts("Here are your words");
            for(int i = 0;i < num;i++) {
                puts(words[i]);
            }
            free(words);
        }
    }
}

int main(int argc, char **argv) 
{   
    // exercise1
    // for(int i = 0;i < 6;i++) {
    //     printf("count: %d\n", __exec_4__());
    // }

    // exercise2
    // int * pti = __exec_5__(20);
    // for(int i = 0;i < 20;i++) {
        // printf("%d\n", pti[i]);
    // }
    // free(pti);

    //exercise3
    // for(int i = 0;i < 10;i++) {
    //     __exec_6__();
    //     putchar('\n');
    // }

    //exercise4
    // int num,value;
    // puts("input numbers of array and begining value");
    // if(scanf("%d %d", &num, &value) == 2) {
    //     int * pti = make_array(num, value);
    //     show_array(pti, num);
    //     free(pti);
    // }

    // exercise5
    // __exec_9__();

    // char * buf = (char *) malloc(10);
    // fgets(buf, 10, stdin);
    // puts(buf);
    // free(buf);
    // puts(buf);

    // for(int i = 0;i< 5;i++) {
    //     printf("%d at %p\n", i, &i);
    //     // int a = 14;
    //     // printf("%p\n", &a);
    //     int i = 5;
    //     i++;
    //     printf("%d at %p\n\n", i, &i);
    // }

    return 0;
}