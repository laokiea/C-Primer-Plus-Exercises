#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
#define ONE_M (1024*1024)
int main()
{
    char *some_memory;
    int size_to_allocate = ONE_M;
    int megs_obtained = 0;
    int ks_obtained = 0;
    //allocate memory by MegaByte
      
    while(1)
    {
        some_memory = (char *)malloc(size_to_allocate);
        if(some_memory == NULL)
            exit(EXIT_FAILURE);
        megs_obtained++;
        printf("Now allocate %d Megabytes\n", megs_obtained);
    }
    
    //allocate memory by KiloByte
    /*
    while(1)
    {   
        for(ks_obtained = 0; ks_obtained < 1024; ks_obtained++)
        {   
            some_memory = (char *)malloc(size_to_allocate);
if(some_memory == NULL)
                exit(EXIT_FAILURE);
        }
        megs_obtained++;
        printf("Now allocated %d Megabytes/n", megs_obtained);
    }
    */
    exit(EXIT_SUCCESS);
}