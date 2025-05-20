#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int16_t main (int16_t argc, uint8_t *argv[])
{
    uint8_t *input_buffer;
    uint16_t length;
    uint16_t i;
    int ascii_value;

    if(argc < 2)
    {
        printf("Error: Too few arguments.\n");
    }
    else
    {
        //Print Length of Arguemnt
        length = strlen(argv[1]);
        input_buffer = (int*)malloc(length * sizeof(uint8_t));
        sprintf(input_buffer, "%s",argv[1]);
        printf("Length = %d\n",length);
        printf("Input = %s\n",input_buffer);
        
        //Convert Input to Binary
        for(i = 0; i < length; i++)
        {
            ascii_value = (uint8_t) input_buffer[i];
            printf("Value[%c] = %d\n",input_buffer[i],ascii_value);
        }
    }
    return 0;
}