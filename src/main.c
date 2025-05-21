#include "main.h"

static uint8_t inBuf[MAX_IN_BUFFER_SIZE];
static uint8_t outBuf[MAX_OUT_BUFFER_SIZE];

int main (int argc, char *argv[])
{
    int ret = 0;
    // No arguements, read from standard out.
    if(argc < 2)
    {
        StandardIn();
    }
    else
    {
        ret = ProcessArgs(argc,argv);
    }
        
    return ret;
}

void StandardIn(void)
{
    char c;
    uint16_t bytes_read;
    uint16_t bytes_proc = 0;
    uint16_t outbuf_len;
    uint8_t tmpBuf[BITS_PER_CHAR];
    
    outbuf_len = DOUBLE_LEVEL_ENCODING; //Size of outbuf doubles with each encoding level

    bytes_read = util_ReadIn(inBuf);

    while(bytes_read != bytes_proc)
    {
        c = inBuf[bytes_proc];
        //Convert Ascii Value to Binary Buffer
        util_AsciitoBinary((uint8_t) c,tmpBuf);
        //Encode Binary Buffer with Oregon and Store in Output Buffer
        encode_Byte(tmpBuf,outBuf,COMBINE);
        util_PrintBinaryBuffer(outBuf,4);
        //Print Output Buffer
        util_WriteOut(outBuf,outbuf_len);
        util_NewLineOut();
        bytes_proc++;
    }
}

int ProcessArgs(int arg_total, char* arg_strings[])
{
    uint16_t len;
    //Standard Mode
    if(!strcmp("-s",arg_strings[1]))
    {
        if(arg_total < 3)
        {
            printf("Error: Too few arguments. (Needs 3 given %d)\n",arg_total);
            return -1;
        }
    
        len = strlen(arg_strings[2])+1;
        StandardEncode(len, (uint8_t*) arg_strings[2]); //Adds new line char to return str
    }
    else
    {
        //Run Standard mode as default except with the 2nd arg
        len = strlen(arg_strings[1])+1;
        StandardEncode(len, (uint8_t*) arg_strings[1]); //Adds new line char to return str
    }
    return 0;
}
void StandardEncode(uint16_t len, uint8_t *input_string)
{
    uint16_t outbuf_index = 0;
    uint16_t outbuf_len;
    uint8_t ascii_value;
    uint16_t i;
    uint8_t tmpBuf[BITS_PER_CHAR];

    //Allocate Binary Buffers
    sprintf( (char *) inBuf, "%s\n",input_string); //inBuff gets new line character to match example
    outbuf_len = len * BITS_PER_CHAR * DOUBLE_LEVEL_ENCODING; //Size of outbuf doubles with each encoding level

    //Convert Input to Binary
    for(i = 0; i < len; i++)
    {
        //Convert Character to Ascii Value
        ascii_value = (uint8_t) inBuf[i];
        //Convert Ascii Value to Binary Buffer
        util_AsciitoBinary(ascii_value,tmpBuf);
        //Get Output Buffer Index
        outbuf_index = i * BITS_PER_CHAR * DOUBLE_LEVEL_ENCODING;
        //Encode Binary Buffer with Oregon and Store in Output Buffer
        encode_Byte(tmpBuf,&outBuf[outbuf_index],COMBINE);
    }
    //Print Output Buffer
    util_PrintBinaryBuffer(outBuf,outbuf_len);
}