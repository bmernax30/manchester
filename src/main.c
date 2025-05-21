#include "main.h"
#include "util.h"

int16_t main (int16_t argc, uint8_t *argv[])
{
    uint8_t *input_buffer;
    uint8_t *test_buffer[8];
    uint16_t length;
    uint16_t i;
    int ascii_value;

    if(argc < 2)
    {
        printf("Error: Too few arguments.\n");
        return -1;
    }

    //Test Functions Mode
    if(!strcmp("-t",argv[1]))
    {
        asciitobinary("a",test_buffer);
        
    }
    //Print Length of Arguemnt
    length = strlen(argv[1]);
    input_buffer = (uint8_t*)malloc(length * sizeof(uint8_t));
    sprintf(input_buffer, "%s",argv[1]);
    printf("Length = %d\n",length);
    printf("Input = %s\n",input_buffer);
        
    //Convert Input to Binary
    for(i = 0; i < length; i++)
    {
        ascii_value = (uint8_t) input_buffer[i];
        printf("Value[%c] = %d\n",input_buffer[i],ascii_value);
    }

    return 0;
}