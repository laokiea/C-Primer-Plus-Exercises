#include <time.h>

unsigned long int seed = 1;

void _srand(unsigned long int u_seed);

unsigned long int _rand(void) 
{
    _srand((unsigned long int)(time(NULL) + 1));
    seed = seed * 1103515245 + 12345;
    return (unsigned long int)(seed / 65536) % 32768;
}

void _srand(unsigned long int u_seed) 
{
    seed = u_seed;
} 