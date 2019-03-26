#ifndef NORMAL_INCLUDE_UNIT
#define NORMAL_INCLUDE_UNIT

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#endif

// 自定义函数代替fgets
// 获取整行输入，如果输入里有换行替换成\0,如果有空字符串\0，就抛弃缓冲区内的后续输入
char * s_gets(char * st, int len) {
    fgets(st, len, stdin);
    int i = 0;
    while(*(st + i) != '\n' && st[i] != '\0') {
        i++;
    }
    switch(*(st + i)) {
        case '\n':
        st[i] = '\0';
        break;

        case '\0':
        while(getchar() != '\n') ;
        break;
    }

    return st;
}

void string_sort(char * strings[], int num) {
    for(int i = 0;i < num - 1;i++) {
        for(int j = i + 1;j < num;j++) {
            if(strcmp(strings[i], strings[j]) > 0) {
                char * temp;
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

void toUpper(char * string) {
    while(*string) {
        *string = toupper(*string);
        string++;
    }
}