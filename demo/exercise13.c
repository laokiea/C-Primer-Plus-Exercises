#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1024

char _map(char ch);

char buf[SIZE];

void __test_2__(int argc, char **argv)
{
   if(argc != 3) {
       fputs("wrong_1", stderr);
       exit(EXIT_FAILURE);
    } 

    FILE * fp_src;
    FILE * fp_des;

    if((fp_src = fopen(argv[1], "rb")) == NULL) {
        fputs("wrong_2", stderr);
        exit(EXIT_FAILURE);
    }

    if((fp_des = fopen(argv[2], "wb")) == NULL) {
        fputs("wrong_3", stderr);
        exit(EXIT_FAILURE);
    }

    while(!feof(fp_src) && !ferror(fp_src)) {
        size_t read_size = fread(buf, sizeof *buf, SIZE, fp_src);
        fwrite(buf, sizeof *buf, read_size, fp_des);
    }

    fputs("done", stdout);

    fclose(fp_src);
    fclose(fp_des);
}

void __test_3__(int argc, char **argv) 
{
    if(argc != 2) {
       fputs("wrong_1", stderr);
       exit(EXIT_FAILURE);
    }

    FILE * fp_read;
    FILE * fp_write;
    long last_read_pos = 0L;

    fp_read = fopen(argv[1], "rb");
    fp_write = fopen(argv[1], "r+b"); //r+模式从开头写，然后覆盖

    while(!feof(fp_read) && !ferror(fp_read)) {
        size_t read_size = fread(buf, sizeof *buf, SIZE, fp_read);
        for(size_t i = 0;i < read_size;i++) {
            fputc(toupper(buf[i]), fp_write);
        }
    }

    fputs("Done", stdout);

    fclose(fp_read);
    fclose(fp_write);
}

void __test_4__(int argc, char **argv) 
{
    if(argc < 2) {
        fputs("wrong_1", stderr);
        exit(EXIT_FAILURE);
    }

    FILE * fp_read;

    int i = 1;
    while(i < argc) {
        if((fp_read = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "Can not open this file: %s\n", argv[i]);
        }

        size_t read_size;
        while(!feof(fp_read) && !ferror(fp_read)) {
            // char * buf = (char *)malloc(SIZE);
            // char buf_1[SIZE];
            char buf_2[SIZE];
            // printf("%p\n", buf_2);
            puts(buf_2);
            read_size = fread(buf_2, sizeof *buf_2, SIZE, fp_read);
            printf("%ld\n", read_size);
            fputs(buf_2, stdout);
        }
        fclose(fp_read);
        // fprintf(stdout, "\n%s has done\n\n", argv[i]);
        i++;
    }
}

void __test_7__(int argc, char **argv)
{
    FILE * fp_1;
    FILE * fp_2;
    char file_1[40];
    char file_2[40];
    char mode;

    if(argc == 4) {
        mode = *argv[3];
        strncpy(file_1, argv[1], 40);
        strncpy(file_2, argv[2], 40);
    } else {
        fputs ("Enter first file name", stdout);
        fscanf(stdin, "%40s", file_1);
        fputs ("Enter second file name", stdout);
        fscanf(stdin, "%40s", file_2);
        fputs ("Enter mode", stdout);
        fscanf(stdin, "%c", &mode);
    }

    fp_1 = fopen(file_1, "rb");
    fp_2 = fopen(file_2, "rb");

    while(!feof(fp_1) || !feof(fp_2)) {
        // char * read_buf_1 = (char *) malloc(SIZE); 
        // char * read_buf_2 = (char *) malloc(SIZE); 
        char read_buf_1[SIZE];
        char read_buf_2[SIZE];

        if(fgets(read_buf_1, SIZE, fp_1) != NULL) {
            fputs(read_buf_1, stdout);
        }
        if(fgets(read_buf_2, SIZE, fp_2) != NULL) {
            fputs(read_buf_2, stdout);
        }
    }

    fclose(fp_1);
    fclose(fp_2);
}

void __test_8__(int argc, char ** argv) 
{
    if(argc < 2) {
        printf("Usage: %s targer_char file1 file2 ...", argv[0]);
        exit(EXIT_FAILURE);
    }

    char des_ch = *argv[1];
    char read_ch;

    if(argc == 2) {
        int match_time = 0;
        char stdin_buf[SIZE];
        setvbuf(stdin, stdin_buf, _IOLBF, (size_t)SIZE);
        while((read_ch = getchar()) != '\n') {
            if(des_ch == read_ch) {
                match_time++;
            }
        }
        fprintf(stdout, "charater '%c' appear %d times\n", des_ch, match_time);
    } else {
        FILE * open_fp;
        static char buf[SIZE];
        for(int i = 2;i < argc;i++) {
            int match_time = 0;
            if((open_fp = fopen(argv[i], "rb")) == NULL) {
                puts("Can not open this file");
                exit(EXIT_FAILURE);
            }

            while(!feof(open_fp) && !ferror(open_fp)) {
                read_ch = fgetc(open_fp);
                if(des_ch == read_ch) {
                    match_time++;
                }
            }

            fprintf(stdout, "File Name: %s, charater '%c' appear %d times\n", argv[i], des_ch, match_time);
            fclose(open_fp);
        }
    }
}

void __test_10__(void)
{
    char filename[20];
    long pos;
    FILE * fp;

    puts("Enter file name");
    if(fscanf(stdin, "%20s", filename) != 1) {
        puts("Enter correct filename");
        exit(EXIT_FAILURE);
    }

    puts("Enter pos");
    char buf[SIZE];
    fp = fopen(filename, "rb");

    while(fscanf(stdin, "%ld", &pos) == 1 && pos >= 0) {
        rewind(fp);
        fseek(fp, pos, SEEK_SET);
        if(fgets(buf, SIZE, fp) != NULL) {
            fputs(buf, stdout);
        }
        puts("Enter pos agin");
    }

    fclose(fp);
}

void __test_11__(char **argv)
{
    char buf[SIZE];
    FILE * fp = fopen(argv[2], "rb");
    while(fgets(buf, SIZE, fp) != NULL) {
        if(strstr(buf, argv[1]) != NULL) {
            puts(buf);
        }
    }

    fclose(fp);
}

void __test_12__()
{
    FILE * fp = fopen("test.end", "rb");
    int read_num;
    char * strings[20];
    char buf[SIZE];
    char rev_buf[31];
    int index = 0;
    char rev;

    while(fgets(buf, SIZE, fp) != NULL) {
        for(int i = 0;i < strlen(buf);i += 2) {
            rev_buf[i / 2] = _map(buf[i]);
        }
        strings[index++] = rev_buf;
    }

    // char * __strings[2] = {"helo", "halo"};
    // char ** _string = strings;
    // while(*_string) {
    //     puts(*_string);
    //     _string++;
    // }
    // int a = 1;
    // int b = 20;
    // int z[2][3] = {{1,2,3},{2,3,4}};
    // int ** _z = z;
}

char _map(char ch) {
    char maps[11] = {' ', '.', '!', '@', '$', '%', '^', '&', '*', '#', '\0'};
    return maps[ch - '0'];
}

int main(int argc, char **argv) 
{
    // __test_2__(argc, argv);
    FILE * fp_1;

    // fp_1 = fopen("test", "rb");
    // printf("%d\n", fseek(fp_1, 0L, SEEK_END) == -1);
    // if(feof(fp_1) || ferror(fp_1)) {
    //     puts("wrong");
    // }
    // if(fgetc(fp_1) == EOF) {
    //     puts("end");
    // }

    // __test_3__(argc, argv);

    // for(int i = 0;i < 3;i++) {
    //     fscanf(stdin, "%s", buf);
    //     fputs(buf, stdout);
    // }

    // __test_4__(argc, argv);

    // __test_7__(argc, argv);

    // for(int i = 0;i < 2;i++) {
        // int i = 1;
        // size_t bytes;
        // fp_1 = fopen("test", "rb");
        // FILE * fp_2 = fopen("test.end", "w+b");
        // static char buf1[1024];

        // while((bytes = fread(buf1, sizeof(char), 1024, fp_1)) > 0) {
            // fwrite(buf1, sizeof(char), bytes, fp_2);
        // }
        // while(fgets(buf1, 1024, fp_1) != NULL) {
        //     fputs(buf1, fp_2);
        // }
        // while(!feof(fp_1)) {
            // char buf1[18];
            // printf("%d:", i);puts(buf1);i++;
            // puts(buf1);
            // size_t size = fread(buf1, sizeof *buf1, 16, fp_1);
            // printf("%ld\n", size);
            // fgets(buf1, 18, fp_1);
            // printf("%d:", i);puts(buf1);i++;
            // fputs(buf1, stdout);
        // }
    // }

    // __test_8__(argc, argv);

    // __test_10__();

    // __test_11__(argv);

    // __test_12__();

    // char a[2][5] = {"halo", "helo"}; // 二维数组
    // char (*_a)[5] = a;
    // char * b[2] = {"hello", "halo"}; // 一位数组
    // char ** _b = b;

    // int d[2] = {1,2};
    // int e[2] = {3,4};
    // int * c[2] = {d, e};

    exit(0);
}


// fgets会按照字节读取到指定的num或者换行，并且补上\0这也是为什么fputs输出不会把buf剩下的字符也输出出来。
// fwrite会将buf中前size个字符写进指定的文件流中