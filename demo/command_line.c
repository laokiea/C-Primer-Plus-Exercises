#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define M1 "hello"

void __test__(int * num) {
    int a = 10;
    *num = a;
}

const char * __test_1__(char * string) {
    return (const char *)string;
}

int main(int argc, char **argv) {
    // int i = 0;
    // for(;i < argc;i++) {
    //     puts(argv[i]);
    // }
    // printf("%d\n", argc);

    // char strings[2][10] = {"hello", "world"};
    // char * strings[2] = {"hello", "world"};
    // __test__(strings);

    // char a[10] = "hello";
    // printf("%c\n", *a);

    // printf("%d\n", atoi(argv[1]));
    
    // char * string = "10aaom";
    // char * end;
    // printf("value: %ld, %s\n", strtol(string, &end, 16), end);

    // char string[10] = "helo";
    // __test__(string);

    // int a = 10;
    // __test__(&a);

    // printf(M1);

    // int a;
    // __test__(&a);
    // printf("%d\n", a);

    // int num = 10;
    // char string[10];
    // fgets(string, num, stdin);

    // char * temp;
    // if( (temp = strchr(string, '\n')) != NULL) {
    //     *temp = 't';
    // }

    // puts(string);

    char string[10] = "hello";
    const char * temp;
    temp = __test_1__(string);
    // *temp = 't';
    // puts(temp);

    return 0;
}