#include<stdio.h>

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