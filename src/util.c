#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "util.h"

/*Function: util_AsciitoBinary
* Take an ascii character and return
* the binary string.
*/
void util_AsciitoBinary(uint8_t input_ch, uint8_t *output)
{
    uint8_t tmp_ch;

    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        tmp_ch = (input_ch & (BIT_MASK >> i));
        output[i] = tmp_ch >> (BITS_PER_CHAR-i-1);
    }
}

/*Function: util_BinarytoAscii
* Convert binary string to 8 byte value.
*/
uint8_t util_BinarytoAscii(uint8_t *input_binary)
{
    uint8_t output_ch = 0;

    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        output_ch = output_ch | (input_binary[i] << (BITS_PER_CHAR-i-1));
    }

    return output_ch;
}

/*Function: util_PrintBinary
* Print an 8 bit binary number.
*/
void util_PrintBinary(uint8_t *input)
{
    printf("%d%d%d%d%d%d%d%d",
        input[0],input[1],input[2],input[3],
        input[4],input[5],input[6],input[7]);
}

/*Function: util_ReadIn
* Read standard in buffer.
*/
uint16_t util_ReadIn(uint8_t *input)
{
    return read(0, input, MAX_IN_BUFFER_SIZE);
}

/*Function: util_WriteOut
* Write buffer to standard out.
*/
void util_WriteOut(uint8_t *output, uint16_t len, uint8_t type)
{
    uint8_t tmpBuf[BITS_PER_CHAR];
    switch(type)
    {
        case BINARY:
            for(uint16_t i = 0; i < len; i++)
            {
                util_AsciitoBinary(output[i],tmpBuf);
                util_PrintBinary(tmpBuf);
            }
            break;
        case HEX:
            for(uint16_t i = 0; i < len; i++)
            {
                printf("%02x",output[i]);
            }
            break;
        default:
        case ASCII:
            write(STDOUT_FILENO, output, len);
            break;
    }
}

/*Function: util_WriteOutFile
* Write buffer to output file.
*/
void util_WriteOutFile(FILE * fptr, uint8_t *output, uint16_t len, uint8_t type)
{
    uint8_t tmpBuf[BITS_PER_CHAR];
    switch(type)
    {
        case BINARY:
            for(uint16_t i = 0; i < len; i++)
            {
                util_AsciitoBinary(output[i],tmpBuf);
                fprintf(fptr,"%d%d%d%d%d%d%d%d",
                    output[0],output[1],output[2],output[3],
                    output[4],output[5],output[6],output[7]);
            }
            break;
        case HEX:
            for(uint16_t i = 0; i < len; i++)
            {
                fprintf(fptr,"%02x",output[i]);
            }
            break;
        default:
        case ASCII:
            fprintf(fptr,"%s",output);
            break;
    }
}
