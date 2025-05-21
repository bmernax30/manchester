#include <stdint.h>
#include <stdio.h>

#include "util.h"
#include "encode.h"

/*Function: encode_Byte
* Take 1 byte and encode it with Oregon Weather
* institute addition.
* Oregon
* 0 = {1,0}
* 1 = {0,1}
* Manchester
* 0 = {0,1}
* 1 = {1,0}
*/

void encode_Byte(uint8_t *input, uint8_t *output, uint8_t encode_type)
{
    uint8_t bit_mask = MSB_MASK;
    uint8_t byte_index = 0;
    uint8_t tmpByte;

    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        if(encode_type == COMBINE)
        {
            //0->OREGON->{1,0}->MANCHESTER->{1,0,0,1}
            //1->OREGON->{1,0}->MANCHESTER->{0,1,1,0}
            tmpByte = OM_OUTPUT_0_MASK;
            
            //Invert 0->1 Mask
            if(input[i] == 1)
            {
                tmpByte = ~tmpByte;
            }

            tmpByte = tmpByte & bit_mask;
            
            //Invert MSB to LSB Mask
            if(bit_mask == MSB_MASK)
            {
                output[byte_index] = tmpByte;
                bit_mask = LSB_MASK;
            }
            else
            {
                output[byte_index] = output[byte_index] | tmpByte;
                bit_mask = MSB_MASK;
                byte_index++;
            }
        }
    }
}