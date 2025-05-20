#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int16_t main (int16_t argc, uint8_t *argv[])
{
    if(argc < 2)
    {
        printf("Error: Too few arguments.");
    }
    else
    {
        for(uint8_t i = 0; i < argc; i++)
        {
            printf("Arg %d= %s\n",i+1,argv[i]);
        }
    }
}