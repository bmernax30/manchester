#include <stdint.h>

#include "util.h"
#include "encode.h"

/*Function: byteEncodeOregon
* Take 1 byte and encode it with Oregon Weather
* institute addition.
* 0 = {1,0}
* 1 = {0,1}
*/

int8_t byteEncodeOregon(uint8_t *input, uint8_t *output)
{
    uint8_t index = 0;
    for(uint8_t i = 0; i < BITS_PER_CHAR; i++)
    {
        if(input[i] == 1)
        {
            output[index] = 0;
            output[index+1] = 1;
        }
        else if(input[i] == 0)
        {
            output[index] = 1;
            output[index+1] = 0;
        }
        else
        {
            return -1;
        }
        index += 2;
    }
    return 0;
}