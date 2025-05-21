#include "main.h"

int main (int argc, char *argv[])
{
    uint8_t *input_buffer;
    uint8_t test_buffer[BITS_PER_CHAR];
    uint16_t length;
    uint16_t i;
    uint8_t ch = 0x61;
    int ascii_value;

    if(argc < 2)
    {
        printf("Error: Too few arguments.\n");
        return -1;
    }

    //Test Functions Mode
    if(!strcmp("-t",argv[1]))
    {
        asciitobinary(ch,test_buffer);
        printbinary(test_buffer);
    }
    else if(!strcmp("-b",argv[1]))
    {
        if(argc < 3)
        {
            printf("Error: Too few arguments.\n");
            return -1;
        }
        //Print Length of Arguemnt
        length = strlen(argv[2]);
        input_buffer = (uint8_t*)malloc(length * sizeof(uint8_t));
        sprintf( (char *) input_buffer, "%s",argv[2]);
        printf("Length = %d\n",length);
        printf("Input = %s\n",input_buffer);

        //Convert Input to Binary
        for(i = 0; i < length; i++)
        {
            ascii_value = (uint8_t) input_buffer[i];
            asciitobinary(ascii_value,test_buffer);
            printbinary(test_buffer);
        }
    }
        
    return 0;
}