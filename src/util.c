#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "util.h"

/*Function: asciitobinary
* Take an ascii character and return
* the binary string.
*/

int8_t asciitobinary(uint8_t input_ch, uint8_t *output)
{
    uint8_t tmp_ch;

    printf("Value[%c] = %x\n",input_ch,input_ch);
    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        tmp_ch = (input_ch & (BIT_MASK >> i));
        output[i] = tmp_ch >> (BITS_PER_CHAR-i-1);
    }
}

/*Function: binarytoascii
* Convert binary string to 8 byte value.
*/

int8_t binarytoascii(uint8_t *input_binary, uint8_t output_ch);
{
    uint8_t tmp_ch;

    printf("Value[%c] = %x\n",input_ch,input_ch);
    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        tmp_ch = (input_ch & (BIT_MASK >> i));
        output[i] = tmp_ch >> (BITS_PER_CHAR-i-1);
    }
}

/*Function: printbinary
* Print an 8 bit binary number.
*/

void printbinary(uint8_t *input)
{
    printf("[%d][%d][%d][%d] [%d][%d][%d][%d]\n",
        input[0],input[1],input[2],input[3],
        input[4],input[5],input[6],input[7]);
}