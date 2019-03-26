#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void __redirect__(void) {
    char string[100];
    fgets(string, 100, stdin);
    puts(string);
}

void __count__(int argc, char ** argv)
{
    char ch;
    int count = 0;
    FILE * fp;

    if(argc != 2) {
        printf("Usage: %s filename", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        puts("Can not open this file");
        exit(EXIT_FAILURE);
    }

    while((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("\nOpened file %s has %d characters", argv[1], count);
}

void __reduce__(int argc, char ** argv)
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE * fp_read;
    FILE * fp_write;
    char ch;
    int read_char_count = 0;
    
    char write_file_name[strlen(argv[1]) + 5];

    // strcpy是会拷贝最后的空字符\0
    strcpy(write_file_name, argv[1]);
    strcat(write_file_name, ".end");

    if((fp_read = fopen(argv[1], "r")) == NULL || (fp_write = fopen(write_file_name, "w")) == NULL) {
        fprintf(stderr, "Can not open this file \"%s\"", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(fp_read)) != EOF) {
        if(read_char_count++ % 3 == 0) {
            putc(ch, fp_write);
        }
    }

    if(fclose(fp_write) != 0 || fclose(fp_read) != 0) {
        fprintf(stderr, "Error in closing files");
        exit(EXIT_FAILURE);
    }

    fprintf(stdin, "Finished");
}

void __test_1__(void)
{
    FILE * fp;
    if((fp = fopen("test.end", "a")) != NULL) {
        fprintf(fp, "i like %s", "rose");
    }
}

void __test_2__(void) 
{
    char string[100];
    FILE * fp;
    if((fp = fopen("test.end", "r")) != NULL) {
        fscanf(fp, "%s", string);
    }

    puts(string);
}

void __test_3__(void)
{
    fprintf(stdout, "Enter few words that you want, \'#\' for finish\n");

    FILE * fp;
    char word[20];

    if((fp = fopen("wendy's", "a+")) == NULL) {
        fprintf(stderr, "Can not open the file\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(stdin, "%10s", word) == 1 && word[0] != '#'){
        fprintf(fp, "%s ", word);
    }

    fprintf(stdout, "These are your input\n");
    rewind(fp);

    while(fscanf(fp, "%s", word) == 1) {
        fprintf(stdout, "%s\n", word);
    }

    if(fclose(fp) != 0) {
        fprintf(stderr, "Error in closing\n");
    }
}

void __test_4__(void)
{
    char ch;
    while((ch = getchar()) != '\n') {
        // putchar(ch);
        // fflush(stdout);

        // non-buffering, depend on os
        // fprintf(stderr, "%c", ch);
    }
}

void __test_5__(void)
{
    char static_buf[BUFSIZ];
    setvbuf(stdout, static_buf, _IOLBF, BUFSIZ);
    // setbuf(stdout, static_buf);
    // fprintf(stdout, "hello");
    puts("hello");
    printf("%lu\n", strlen(static_buf));
    // now two same string in buffering static_buf
    // fprintf(stdout, "%s", static_buf);
    puts("hello");
    printf("%lu\n", strlen(static_buf));

    // 将缓存区中的数据刷新到对应的流中
    // fflush(stdout);
    // fclose(stdout);
    sleep(2);
    // puts(static_buf);
    printf("%lu\n", strlen(static_buf));
}

void __test_6__(void) 
{
    char string[20];
    fgets(string, 20, stdin);
    fputs(string, stdout);
}

#define CNTL_Z '\032'
int _outer_static = 10;
int _outer_static_no_init;
void __test_7__(void)
{
    char file_name[10];
    FILE * fp;
    char ch;

    fputs("What file you want process:\n", stdout);
    while(scanf("%s", file_name) != 1) {
        fputs("Please Enter a correct filename\n", stderr);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(file_name, "rb")) == NULL) {
        fputs("Can not open this file\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 10f -> static data
    // ffee -> stack
    // fff9 -> heap
    int * _heap_ = (int *) malloc(sizeof(int));
    printf("heap: %p\n Data segment: %p\n unkown: %p\n stack: %p\n Bss segment: %p\n Code Segment: %p\n", _heap_, &_outer_static, fp, &fp, &_outer_static_no_init, __test_7__);

    if(fseek(fp, 0L, SEEK_END) != 0) {
        fputs("Can not move fp at this file\n", stderr);
        exit(EXIT_FAILURE);
    }

    long pos = ftell(fp);
    if(pos != 0L) {
        while(fseek(fp, --pos, SEEK_SET) == 0) {
            ch = getc(fp);
            putc(ch, stdout);
        }
    }

    // for(long count = 1L;count <= pos;count++) {
    //     fseek(fp, -count, SEEK_END);
    //     ch = fgetc(fp);
    //     if(ch != CNTL_Z && ch != '\r') 
    //         putchar(ch);
    // }
    putchar('\n');

    if(fclose(fp) != 0) {
        fprintf(stderr, "Error in closing\n");
    }
}

void __test_8__(void)
{
    int ch;
    FILE * fp = fopen("test", "r");
    fseek(fp, 0L, SEEK_END);
    long count = ftell(fp);

    for(int i = 0;i < count;i++) {
        ch = getc(fp);
        fprintf(stdout, "%x ", ch);
    }
}

void __test_ungetc__(void)
{
    char ch;
    ch = getc(stdin);
    putc(ch, stdout);
    ungetc(ch, stdin);
    putc(getc(stdin), stdout);
}

void __test_fwrite__(void)
{
    int num = 12345;
    FILE * fp = fopen("test", "w+");
    // fprintf(fp, "%d", num);
    fwrite(&num, sizeof(int), 1, fp);
}

void __test_fread__(void)
{
    int num; 
    char string[10];
    FILE * fp = fopen("test", "r");
    if(fp == NULL) {
        puts("Can not open this file\n");
        exit(EXIT_FAILURE);
    }
    size_t ret_code = fread(&num, sizeof(int), 1, fp);
    if(ret_code != 2) {
        // end of file
        if(feof(fp)) {
            puts("end of file");
        } else if(ferror(fp)) {
            puts("some wrong happened.");
        }
    }
    // printf("%lu\n", ret_code);
    // fseek(fp, 0L, SEEK_SET);
    // fread(string, sizeof *string, 4, fp);
    printf("%d\n", num);
    // fputs(string, stdout);
}

#define LEN 5
void __readbin__(void) 
{
    double numbers[LEN];
    double read_num;
    for(int i = 0;i < LEN;i++) {
        numbers[i] = 100 * i + 1 / (i + 1.0);
    }

    FILE * fp;
    if((fp = fopen("readbin", "wb")) == NULL) {
        puts("Can not open this file");
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof *numbers, LEN, fp);
    fclose(fp);

    if((fp = fopen("readbin", "rb")) == NULL) {
        puts("Can not open this file");
        exit(EXIT_FAILURE);
    }

    int index;
    puts("Enter a index");
    while(scanf("%d", &index) == 1 && index < LEN && index >= 0) {
        long pos = sizeof(double) * index;
        fseek(fp, pos, SEEK_SET);
        size_t read_size = fread(&read_num, sizeof(double), 1, fp);
        if(read_size != 1) {
            if(ferror(fp)) {
                puts("error");
            }
        }

        printf("%f\n", read_num);
        puts("Next index(out of range to quit)");
    }

    fclose(fp);
}

#define SIZE 20
#define READ_SIZE 1024
void __test_one_program__(void) 
{
    char buffer[BUFSIZ];
    char add_filename[SIZE];
    char open_filename[SIZE];
    FILE * open_fp;
    FILE * add_fp;

    puts("please enter name of file that you want write to");
    if(fscanf(stdin, "%s", open_filename) != 1) {
        puts("Please enter correct filename");
        exit(EXIT_FAILURE);
    }

    if((open_fp = fopen(open_filename, "w+")) == NULL) {
        puts("Can not open this file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    puts("Now, enter name of file that you want copy");
    while(fscanf(stdin, "%s", add_filename) == 1 && i++ < 5) {
        if(strcmp(add_filename, open_filename)) {
            if((add_fp = fopen(add_filename, "r")) == NULL) {
                puts("Can not open this file");
                continue;
            }
            
            if(setvbuf(add_fp, buffer, _IOFBF, BUFSIZ)) {
                puts("Can not set buffer");
                continue;
            }

            static char _read[READ_SIZE];
            while(!feof(add_fp) && !ferror(add_fp)) {
                size_t read_size = fread(_read, sizeof *_read, READ_SIZE, add_fp);

                fwrite(_read, sizeof *_read, read_size, open_fp);
            }

            fclose(add_fp);
            puts("Enter again");
        }
    }

    fclose(open_fp);
}

void __test_e4__(int argc, char ** argv) 
{
    FILE * fp;
    double num = 0.0;
    double sum = 0.0;
    int count  = 0;

    if(argc == 2) {
        if((fp = fopen(argv[1], "r")) == NULL) {
            puts("Can not open this file");
            exit(EXIT_FAILURE);
        }
    } else {
        fp = stdin;
    }

    while(!feof(fp) && !ferror(fp) && fscanf(fp, "%lf", &num) == 1) {
        sum += num;
        count++;
    }

    if(count > 0) {
        printf("The average is %.2f\n", sum / count);
    }
    fclose(fp);
}

#define LINE_SIZE  256
void __test_e5__(int argc, char **argv)
{
    if(argc != 3) {
        fprintf(stderr, "Usage: %s character filename", argv[0]);
        exit(EXIT_FAILURE);
    } 

    FILE * fp;
    char ch = *argv[1];

    if((fp = fopen(argv[2], "r")) == NULL) {
        puts("Can not open this file");
        exit(EXIT_FAILURE);
    }

    char line[LINE_SIZE];
    while(!feof(fp) && !ferror(fp) && fgets(line, LINE_SIZE, fp) != NULL) {
        if(strchr(line, ch) != NULL) {
            puts(line);
        }
    }
    // for(int i = 0;i < 4;i++) {
    //     if(!fgets(line, LINE_SIZE, fp)) {
    //         puts("oop");
    //     }

    //     puts(line);
    //     if(feof(fp)) {
    //         puts("end");
    //     }   
    // }
}

int main(int argc, char ** argv) 
{
    // __redirect__();
    // __count__(argc, argv);
    // __reduce__(argc, argv);

    // __test_1__();

    // __test_2__();

    // __test_3__();

    // __test_4__();

    // __test_5__();

    // __test_6__();

    // __test_7__();

    // __test_8__();

    // __test_ungetc__();

    // __test_fwrite__();

    // __test_fread__();

    // __test_one_program__();

    // __readbin__();

    // FILE * fp = stdout;
    // fputs("hello", fp);

    // __test_e4__(argc, argv);

    // __test_e5__(argc, argv);

    int a;
    FILE * fp = fopen("test", "r");
    // fwrite(&a, sizeof(int), 1, fp);
    fread(&a, sizeof(int), 1, fp);
    printf("%d\n", a);

    return 0;
    // exit(0);
}

// 对于计算来说没有二进制文件和文本文件一说，当打开一个文本文件时会按照特定的编码（utf-8）去翻译成可见文字，而二进制保存的是原始的字节数据。
//最初的main函数调用中，return 0等同于exit(0)
// 文本模式和二进制模式在程序读取文件的实现上没有太大区别，主要是在不同的操作系统上，涉及到一些换行符的转换，比如windows会将\n转换成\r\n, 使用二进制模式打开则没有转换问题

// 文件指针和一般指针不同，一般指针指定了一个存储地址的对象（一块内存），而文件指针指向的对象不仅存储了地址还存储了一些其他信息，综合起来称之为一个结构体。不同的stdio.h文件对文件指针的结构定义不同，大致都有char * base:文件在缓冲区的基址，int cnt:剩下未读取的字符

// putc和getc是实现putchar和getchar的基础 
// 程序读取是超过文件的最后一个字符，才知道文件结尾，而不是只读取到最后一个字符

// int setvbuf (FILE *stream, char buf, int mode, size_t size)
// 这个函数是用来定义stream流该采用何种缓冲策略——可以是 _IOFBF (满缓冲), _IOLBF (行缓冲), or _IONBF (无缓冲)。如果你输入的一个空指针作为buf参数，那么setvbuf会自动使用malloc申请一块内存，当你关闭流的时候，缓冲区会被清除释放掉。否则buf对应的内存块至少应该是size大小。你不应该释放掉buf对应的空间只要流还没有关闭。你应该确保buf对应的内存是静态存储的（例如使用malloc)。使用一个自动存储期限的buf块不是一个好的选择——除非在退出当前块之前关掉了流。当buf对应的数组块是缓冲区的时候，stream流i/o函数会使用这个内存块作为一些内部用途——所以你不应该试着去直接访问这个数组的值当它被使用的时候。 setvbuf 成功时返回0，否则返回非零数当mode是不可取的或者要求不能被满足。

//fopen fclose putc getc fprintf fscanf fgets fputs ftell fseek
//fgets会读取最后一个换行符，而fputs会省略最后一个换行符，他们配合的非常好

// fwrite和fread使用二进制的方式读取和写入数据

// 标准io的机理
// 当我们使用标准（磁盘文件）io的第一步是打开文件，打开文件会有两个作用产生，第一个是创建一块缓冲区，用于存放输入或者输出的内容，第二是创建一个结构变量，并将变量的地址赋值给一个文件指针，这个结构变量不同的stdio.h文件定义的不同，通常会包含以下信息：
// 1. 创建的缓冲区基址
// 2. 流中当前位置的文件位置指示器（下一个位置的地址）
// 3. 一个统计已经拷贝进缓冲区的字节数
// 第二步是调用标准io库中的函数，当调用这些函数时，则会从缓冲区中读取，因为unix下无论时二进制模式还是文本模式，都是按照字节读取，所以在读取一个字节后，文件指示器会指向下一个字节。当缓冲区中所有字节都被读取完毕，会请求（系统调用）将文件的下一步部分（内核缓冲区）拷贝进缓冲区（用户进程缓冲区）
// 输出函数类似，将数据写入到缓冲区（内核缓冲区），当缓冲区写满时，flush到文件中。

// network i/o model
// blocking
// read 
// 进程发起系统调用，系统调用会进入内核，检查缓冲内有无数据，如果没有数据，该进程会被阻塞，直到缓冲内有数据被copy进来。然后将内核缓冲区的数据copy到进程的缓冲区（用户空间）

// non-blocking
// read
//  进程发起系统调用，系统调用会进入内核，检查缓冲内有无数据，如果没有数据，会立刻返回错误，所以用户进程不会被阻塞，但是会不断的轮询（不断的发出系统调用，比较费时），直到缓冲内有数据被copy进来。然后将内核缓冲区的数据copy到进程的缓冲区（用户空间）