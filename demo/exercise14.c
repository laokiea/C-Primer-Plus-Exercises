#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "function.h"

struct name {
    char f[10];
    char l[10];
    char m[10];
};

struct bx {
    char no[128];
    struct name name;
};

struct student {
    struct name name;
    float grade[3];
    float average;
};
#define CSIZE 4

struct bx bx_arr[5] = {
    {"20131231", {"Sason", "laokiea", "Sam"}},
    {"20131231", {"Sason", "laokiea", ""}},
    {"20131231", {"Sason", "laokiea", "Sam"}},
    {"20131231", {"Sason", "laokiea", "Sam"}},
    {"20131231", {"Sason", "laokiea", "Sam"}}
};

void _exec_4_c_(struct bx val) 
{
    if(*(val.name.m))
        printf("%s, %s .%c -- %s\n", val.name.f, val.name.l, *(val.name.m), val.no);
    else 
        printf("%s, %s -- %s\n", val.name.f, val.name.l, val.no);       
}

void _exec_4_a_(struct bx * val, int count) 
{
    for(int i = 0;i < count;i++) {
        _exec_4_c_(val[i]);
    }
}

void _exec_5_(struct student * s_p)
{
    char buf[BUFSIZ];
    setvbuf(stdout, buf, _IOFBF, BUFSIZ);

    float all = 0.0;
    for(int i = 0;i < CSIZE;i++) {
        puts("Please enter score:");
        float count = 0.0;
        for(int j = 0;j < 3;j++) {
            scanf("%f", &s_p[i].grade[j]);
            count += s_p[i].grade[j];
        }
        s_p[i].average = count / 3;
        all += s_p[i].average;

        printf("%s %s, score: %.2f %.2f %.2f, average: %.2f\n", s_p[i].name.f, s_p[i].name.l, s_p[i].grade[0], s_p[i].grade[1], s_p[i].grade[2], s_p[i].average);
    }
    printf("Class average score: %.2f\n", all / CSIZE);
    fflush(stdout);
}

void _exec_6_(void)
{
    FILE * fp = fopen("test.end", "r");
    typedef struct {
        short no;
        struct name name;
        int play_times;
        int hit_times;
        int run_times;
        int rbi;
    } RECORD, * record_p;

    RECORD * record_arr = malloc(sizeof(RECORD) * 19);
    int tmp_no;
    record_p tmp_record_p = &((RECORD){});
    while(!feof(fp) && !ferror(fp)) {
        fscanf(fp, "%hd", &tmp_record_p->no);
        fscanf(fp, "%s", tmp_record_p->name.f);
        fscanf(fp, "%s", tmp_record_p->name.l);
        fscanf(fp, "%d", &tmp_record_p->play_times);
        fscanf(fp, "%d", &tmp_record_p->hit_times);
        fscanf(fp, "%d", &tmp_record_p->run_times);
        fscanf(fp, "%d", &tmp_record_p->rbi);

        if((tmp_no = tmp_record_p->no) >= 0 && tmp_no <= 18) {
            if(!record_arr[tmp_no].name.f[0]) {
                record_arr[tmp_no] = *tmp_record_p;
            } else {
                record_arr[tmp_no].play_times += tmp_record_p->play_times;
                record_arr[tmp_no].hit_times += tmp_record_p->hit_times;
                record_arr[tmp_no].run_times += tmp_record_p->run_times;
                record_arr[tmp_no].rbi += tmp_record_p->rbi;
            }
        }
    }

    for(int i = 0;i < 19;i++) {
        if(!*record_arr[i].name.f) 
            continue;
        printf("%s %s, player no: %hd, play_times: %d, hit_times: %d, run_times: %d, rbi: %d\n",
            record_arr[i].name.f,
            record_arr[i].name.l,
            record_arr[i].no,
            record_arr[i].play_times,
            record_arr[i].hit_times,
            record_arr[i].run_times,
            record_arr[i].rbi
        );
    }
}

#define SEAT_NUM 12
typedef struct {
    short no;
    unsigned char booked;
    struct name name;
} SEAT, * seat_p;

void _exec_8_init_(seat_p seat_arr)
{
    for(int i = 0;i < SEAT_NUM;i++)
    {
        seat_arr[i].no = i + 1;
        seat_arr[i].booked = 0;
    }
}

void _exec_8_a_(seat_p seat_arr)
{
    int empty_count = 0;
    for(int i = 0;i < SEAT_NUM;i++)
    {
        !seat_arr[i].booked && empty_count++;
    }
    printf("Empty seat nums: %d\n", empty_count);
}

void _exec_8_b_(seat_p seat_arr)
{
    for(int i = 0;i < SEAT_NUM;i++)
    {
        if(!seat_arr[i].booked) {
            printf("Seat No: %hd\n", seat_arr[i].no);
        }
    }
}

void _exec_8_c_(seat_p seat_arr)
{
    char * name_arr[12];
    int index = 0;
    for(int i = 0;i < SEAT_NUM;i++)
    {
        if(seat_arr[i].booked) {
            name_arr[index] = seat_arr[i].name.f;
            index++;
        }
    }

    for(int i = 0;i < index;i++) {
        int max = i;
        for(int j = i + 1;j < index;j++) {
            if(strcmp(name_arr[j], name_arr[max]) > 0) {
                max = j;
            }
        }

        if(max != i) {
            char tmp[100];
            strcpy(tmp, name_arr[i]);
            strcpy(name_arr[i], name_arr[max]);
            strcpy(name_arr[max], tmp);
        }
    }

    for(int i = 0;i < index;i++) {
        puts(name_arr[i]);
    }
}

void _exec_8_d_(seat_p seat_arr)
{
    short no;
    puts("Please enter seat no");
    scanf("%hd", &no);
    while(no < 1 || no > 12 || seat_arr[no - 1].booked) {
        puts("Seat not exists or booked, enter again");
        scanf("%hd", &no);
    }

    puts("Please enter customer's first name");
    scanf("%s", seat_arr[no - 1].name.f);
    puts("Please enter customer's last name");
    scanf("%s", seat_arr[no - 1].name.l);
    while(getchar() != '\n')
        continue;
    
    seat_arr[no - 1].booked = 1;
}

void _exec_8_e_(seat_p seat_arr)
{
    short no;
    puts("Please enter seat no");
    scanf("%hd", &no);
    while(no < 1 || no > 12) {
        puts("Seat not exists");
        scanf("%hd", &no);
    }

    while(getchar() != '\n')
        continue;

    // seat_arr[no].name = {"\0","\0","\0"};
    seat_arr[no - 1].booked = 0;    
}

void _exec_8_f_(seat_p seat_arr)
{
    for(int i = 0;i < SEAT_NUM;i++)
    {
        printf("Seat no: %hd Status: %d Customer: %s %s\n", seat_arr[i].no, seat_arr[i].booked, seat_arr[i].name.f, seat_arr[i].name.l);
    }
}

typedef void (*EXEC8_FUNCS[6]) (seat_p);
EXEC8_FUNCS funcs = {_exec_8_a_, _exec_8_b_, _exec_8_c_, _exec_8_d_, _exec_8_e_, _exec_8_f_};
// #define CONCATD(c) _exec_8_##c##_

seat_p _exec_8_(seat_p s_p, int alloc)
{ 
    if(alloc) {
        s_p = malloc(sizeof(SEAT) * SEAT_NUM);
        _exec_8_init_(s_p);
    }
    
    puts("To choose a function, enter its letter label.");
    puts("a) 空座数量");
    puts("b) 展示空座");
    puts("c) 按姓名作为排序");
    puts("d) 给用户分配座位");
    puts("e) 删除座位分配");
    puts("f) 确认座位分配");
    puts("q) 离开");

    char choice;
    
    while(scanf("%c", &choice) == 1 && choice != 'q') {
        while(getchar() != '\n');

        switch(choice) {
            case 'a':
            funcs[0](s_p);
            break;

            case 'b':
            funcs[1](s_p);
            break;

            case 'c':
            funcs[2](s_p);
            break;

            case 'd':
            funcs[3](s_p);
            break;

            case 'e':
            funcs[4](s_p);
            break;

            case 'f':
            funcs[5](s_p);
            break;
        }
        puts("\nEnter next choice");
    }
    // free(s_p);
    return s_p;
} 

void _exec_9_(void)
{
    seat_p p[4];
    puts("Please enter flight no");
    int flight_no;

    int ready_102 = 0, ready_311 = 0, ready_444 = 0, ready_519 = 0;
    while(scanf("%d", &flight_no) == 1) {
        while(getchar() != '\n');
        switch(flight_no) {
            case 0X66:
            p[0] = _exec_8_(p[0], !ready_102);
            ready_102 = 1;
            break;

            case 0X137:
            p[1] = _exec_8_(p[1], !ready_311);
            ready_311 = 1;
            break;

            case 0X1bc:
            p[2] = _exec_8_(p[2], !ready_444);
            ready_444 = 1;
            break;

            case 0X207:
            p[3] = _exec_8_(p[3], !ready_519);
            ready_519 = 1;
            break;

            default:
            puts("Unknown flight, bye-bye");
            exit(EXIT_FAILURE);
        }
        puts("Please enter flight no");
    }
}

typedef double (*DR_DP)(double);

void transform(double * target, double * source, int count, DR_DP f_p) {
    for(int i = 0;i < count;i++) {
        target[i] = f_p(source[i]);
    }

    printf("%.2f\n", target[0]);
}

int main(int argc, char ** argv) 
{
    DR_DP f_ps[4] = {sin, cos, round, ceil};
    double target[4];
    transform(target, (double [4]){11.4, 2.0, 8.9, 7.2}, 4, f_ps[2]);
    // _exec_4_a_(bx_arr, 5);

    // struct student students[CSIZE] = {
    //     {.name = {"sason","sam1",""}},
    //     {.name = {"sason","sam2",""}},
    //     {.name = {"sason","sam3",""}},
    //     {.name = {"sason","sam4",""}}
    // };
    // _exec_5_(students);

    // _exec_6_();

    // _exec_8_();

    // _exec_9_();

    return 1;
}