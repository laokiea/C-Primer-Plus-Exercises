#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void __test_1__(char * string, int num) {
    fgets(string, num, stdin);
}

void __test_2__(char * string, int num) {
    char ch;
    while(num-- > 1) {
        ch = getchar();
        if(ch == ' ' || ch == '\n' || ch == '\t') {
            break;
        } else {
            *string++ = ch;
        }
    }
}

void __test_3__(void) {
    bool begin_space = true;
    char string[10];
    char word[10];
    fgets(string, 10, stdin);

    int i = 0, j = 0;
    while(string[i]) {
        if(isblank(string[i])) {
            if(!begin_space) {
                break;
            }
        } else {
            word[j] = string[i];
            j++;
            begin_space = false;
        }
        i++;
    }

    puts(word);
}

void __test_4__() {
    
}

const char * __test_5__(const char * string, char ch) {
    while(*string) {
        if(*string == ch) {
            return string;
        }
        string++;
    }

    return NULL;
}

int is_within(char ch, const char * string) {
    while(*string) {
        if(*string == ch) {
            return 1;
        }
        string++;
    }

    return 0;
}

char * mystrncpy(char * target, const char * source, unsigned int num) {
    int i = 0;
    int start_pos = strlen(target);
    
    while(i++ < num) {
        target[start_pos++] = *source++;
    }

    return target;
}

const char * string_in(const char * haystack, const char * needle) {
    while(*haystack) {
        if(*haystack == *needle) {
            int i;
            int times = 0;
            bool match = true;
            for(i = 1;i < strlen(needle);i++) {
                times++;
                if(needle[i] != *++haystack) {
                    match = false;
                    break;
                }
            }

            for(int j = 0;j < times;j++) {
                haystack--;
            }

            if(match) {
                return haystack;     
            }
        }
        haystack++;
    }

    return NULL;
}

void revert_string_1(char * string, char ** revert) {
    int i = 0;
    size_t length = strlen(string) - 1;
    static char revert_x[10]; // heap

    for(;length > 0;length--,i++) {
        revert_x[i] = string[length];
    }

    *revert = revert_x;
}

char * __t(void) {
    char * a = "hello"; // return value of local variable a, that is address of string literal "hello" storage in heap frame
    // char a[10] = "hello"; // a is a copy of string literal that storage in stack frame 
    return a;
}

char * revert_string(char * string) {
    int length = strlen(string);
    int middle = length / 2;
    for(int i = 0;i < middle;i++) {
        char temp;
        temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }

    return string;
}

void __menu__(void) {
    char strings[5][20];
    char * string_pts[5];
    int i = 0;

    printf("Please input:\n");
    for(;i < 5;i++) {
        fgets(strings[i], 20, stdin);
        string_pts[i] = strings[i];
    }

    while(1) {
        printf("\nMenu:\n1. print\n2. print ascii order\n3. print by length\n4. print by first word length\n5. quit\n");
        int select;
        scanf("%d", &select);
    
        switch(select) {
            case 1:
            for(int j = 0;j < 5;j++) {
                puts(string_pts[j]);
            }
            break;

            case 2:
            for(int k = 0;k < 4;k++) {
                for(int l = k + 1;l < 5;l++) {
                    if(strcmp(string_pts[k], string_pts[l]) > 0) {
                        char * temp;
                        temp = string_pts[k];
                        string_pts[k] = string_pts[l];
                        string_pts[l] = temp;
                    }
                }
            }

            for(int j = 0;j < 5;j++) {
                puts(string_pts[j]);
            }
            break;

            case 3:
            for(int x = 0;x < 4;x++) {
                for(int y = x + 1;y < 5;y++) {
                    if(strlen(string_pts[x]) > strlen(string_pts[y])) {
                        char * temp;
                        temp = string_pts[x];
                        string_pts[x] = string_pts[y];
                        string_pts[y] = temp;
                    }
                }
            }

            for(int w = 0;w < 5;w++) {
                puts(string_pts[w]);
            }
            break;

            case 4:
            break;

            case 5:
            return;
            break;
        }
    }
}

void __test_12__(void) {
    char string[20];
    bool word_begin = false;
    int upper_count = 0,lower_count = 0,word_count = 0,digital_count = 0,puncuation_count = 0;

    fgets(string, 20, stdin);

    char last_char;
    for(int i = 0;i < 20;i++) {
        if(!string[i]) break;

        if(isspace(string[i]) && !isspace(last_char)) {
            word_count++;
        } else {
            if(ispunct(string[i])) {
                puncuation_count++;
            } else if(isupper(string[i])) {
                upper_count++;
            } else if(islower(string[i])) {
                lower_count++;
            } else if(isdigit(string[i])) {
                digital_count++;
            }
        }

        last_char = string[i];
    }

    printf("word count: %d\nupper count: %d\nlower count: %d\npuncuation count: %d\ndigital count: %d\n", word_count, upper_count, lower_count, puncuation_count, digital_count);
}

void revert_arg(int argc, char **argv) {
    if(argc > 2)
    for(int i = 1;i < argc;i++) {
        puts(revert_string(argv[i]));
    }
}

void calculator(char **argv) {
    double result = 1.0;
    for(int i = 0;i < atoi(argv[2]);i++) {
        result *= atof(argv[1]);
    }
    printf("%f\n", result);
}

int _atoi(const char * int_string) {
    int i = 0;
    int result = 0;
    char real_int_string[256];

    while(*int_string) {
        if(isdigit(*int_string)) {
            real_int_string[i++] = *int_string;
            int_string++;
        } else {
            break;
        }
    }

    unsigned int length = strlen(real_int_string);

    if(length) {
        for(int j = 0;j < length;j++) {
            result = result * 10 + (real_int_string[j] - '0'); 
        }
    }

    return result;
}

void _print(int argc, char **argv) {
    char string[20];
    fgets(string, 20, stdin);

    if(argc < 2 || strcmp("-p", argv[1]) == 0) {
        puts(string);
    } else if(strcmp("-u", argv[1]) == 0) {
        for(int i = 0;i < strlen(string);i++) {
            putchar(toupper(string[i]));
        }
        putchar('\n');
    } else if(strcmp("-l", argv[1]) == 0) {
        for(int i = 0;i < strlen(string);i++) {
            putchar(tolower(string[i]));
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {

    // char string[10];
    // __test_2__(string, 10);
    // puts(string);

    // __test_3__();

    // const char * string = "hello";
    // puts(__test_5__(string, 'l'));

    // const char * string = "hello";
    // printf("%d\n", is_within('l', string));

    // char string[10] = "hello";
    // const char * source = "world";
    // puts(mystrncpy(string, source, 4));

    // const char * haystack = "i am fine and you";
    // const char * needle = "ek";
    // puts(string_in(haystack, needle));

    char string[10] = "2";
    char * revert;
    // revert_string(string, &revert);
    // puts(revert_string(string));
    // puts(string);

    // printf("%s\n", __t());

    // __menu__();

    // __test_12__();

    // revert_arg(argc, argv);

    // calculator(argv);

    // printf("%d\n", '0' - 48);

    // printf("%d\n", _atoi("7826"));

    _print(argc, argv);

    return 0;
}
