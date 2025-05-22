#include "main.h"

static uint8_t inBuf[MAX_IN_BUFFER_SIZE];
static uint8_t outBuf[MAX_OUT_BUFFER_SIZE];

int main (int argc, char *argv[])
{
    int ret = 0;

    if(argc < 2)
    {
        StandardIn();
    }
    else
    {
        ret = ProcessArgs(argc,argv);
    }

    //Added for certain modes to make it more readable
    //Ignore 0x0A value in hex dump
    printf("\n");
    return ret;
}

/*Function: StandardIn
* Read standard in buffer, encode, and print.
*/
void StandardIn(void)
{
    char c;
    uint16_t bytes_read;
    uint16_t bytes_proc = 0;
    uint8_t tmpBuf[BITS_PER_CHAR];

    bytes_read = util_ReadIn(inBuf);

    while(bytes_read != bytes_proc)
    {
        c = inBuf[bytes_proc];
        util_AsciitoBinary((uint8_t) c,tmpBuf);
        encode_Byte(tmpBuf,outBuf,COMBINE);
        util_WriteOut(outBuf,DOUBLE_LEVEL_ENCODING,ASCII);
        bytes_proc++;
    }
}

/*Function: ProcessArgs
* Process arguement flags to program.
*/
int ProcessArgs(int arg_total, char* arg_strings[])
{
    int ret = 0;
    uint16_t len;
    uint8_t print_type = ASCII;

    if(!strcmp("-s",arg_strings[1]))
    {
        if(arg_total < 4)
        {
            return ErrorOut(ERROR2);
        }
    
        len = strlen(arg_strings[2]);
        print_type = GetPrintType((uint8_t*)arg_strings[3]);
        if(print_type == -1)
        {
            return ErrorOut(ERROR2);
        }
        Mode_PrintSelect(len, (uint8_t*) arg_strings[2],print_type); //Adds new line char to return str
    }
    else if(!strcmp("-f",arg_strings[1]))
    {
        if(arg_total < 3)
        {
            return ErrorOut(ERROR3);
        }
        print_type = GetPrintType((uint8_t*)arg_strings[3]);
        if(print_type == -1)
        {
            return ErrorOut(ERROR3);
        }
        ret = Mode_File((uint8_t *)arg_strings[2],print_type);
    }
    else
    {
        ErrorOut(ERROR1);
    }
    return ret;
}

/*Function: Mode_PrintSelect
* Print out an input string to binary, hex, or ascii.
*/
void Mode_PrintSelect(uint16_t len, uint8_t *input_string, uint8_t print_type)
{
    uint8_t ascii_value;
    uint16_t i;
    uint8_t tmpBuf[BITS_PER_CHAR];

    sprintf((char *)inBuf,"%s",input_string);

    for(i = 0; i < len; i++)
    {
        ascii_value = (uint8_t) inBuf[i];
        util_AsciitoBinary(ascii_value,tmpBuf);
        encode_Byte(tmpBuf,outBuf,COMBINE);
        util_WriteOut(outBuf,DOUBLE_LEVEL_ENCODING,print_type);
    }
}

/*Function: Mode_File
* Read file, encode, write to output file.
*/
int Mode_File(uint8_t * file_name, uint8_t print_type)
{
    char ch;
    uint8_t ascii_value;
    uint8_t tmpBuf[BITS_PER_CHAR];
    uint8_t file_path[MAX_FILE_NAME_SIZE];
    FILE *fin,*fout;

    sprintf((char *)file_path,"../%s",file_name);
    fin = fopen((char *)file_path, "r");
    if (fin == NULL)
    {
        printf("Error1 = %s\n",(char*)file_name);
        return -1;
    }
    fout = fopen("../output.txt", "w");
    if (fout == NULL)
    {
        printf("Error2 = %s\n",(char*)file_name);
        return -1;
    }

    while(1)
    {
        ch = fgetc(fin);
        if(ch == EOF)
        {
            return 0;
        }
        ascii_value = (uint8_t) ch;
        util_AsciitoBinary(ascii_value,tmpBuf);
        encode_Byte(tmpBuf,outBuf,COMBINE);
        util_WriteOutFile(fout,outBuf,DOUBLE_LEVEL_ENCODING,print_type);
    }

    fclose(fin);
    fclose(fout);
}

/*Function: GetPrintType
* Return the print type selected.
* (Binary,Hex,Ascii)
*/
int8_t GetPrintType(uint8_t* flag)
{
    if(!strcmp("-b",(char*)flag))
    {
        return BINARY;
    }
    else if(!strcmp("-h",(char*)flag))
    {
        return HEX;
    }
    else if(!strcmp("-a",(char*)flag))
    {
        return ASCII;
    }
    else
    {
        ErrorOut(ERROR2);
        return -1;
    }
}

/*Function: ErrorOut
* Error messages.
*/
int8_t ErrorOut(uint8_t error)
{
    switch(error)
    {
        default:
        case ERROR1:
            printf("Error: Incorrect or no mode given.\n");
            PrintHelpScreen();
        break;
        case ERROR2:
            printf("Error: Print Select.\n");
            printf("\nMode = Print Select\n");
            printf("Format: 'manchester [mode] [string] [print_type]'\n");
            printf("Description: Encode string and print selected output.\n");
            printf("[mode] = -s\n");
            printf("[string]\n");
            printf("\t Any String (MAX = 1024)\n");
            printf("[output_type]\n");
                printf("\t-b = Binary\n");
                printf("\t-h = Hex\n");
                printf("\t-a = Ascii\n");
            break;
        case ERROR3:
            printf("\nMode = File Input Output\n");
            printf("Format: 'manchester [mode] [print_type]'\n");
            printf("Description: Type string to encode in input.txt. Encode saved to output.txt.\n");
            printf("[mode] = -f\n");
            printf("[output_type]\n");
                printf("\t-b = Binary\n");
                printf("\t-h = Hex\n");
                printf("\t-a = Ascii\n");
            break;
    }
    return -1;
}

/*Function: PrintHelpScreen
* Print the help screen to describe
* usage.
*/
void PrintHelpScreen(void)
{
    printf("\n\n****** MANCHESTER HELP MENU ******\n");
    printf("\nMode = Standard In\n");
    printf("Format: 'manchester'\n");
    printf("Description: Type in string and press enter to encode string.\n");
    
    printf("\nMode = Print Select\n");
    printf("Format: 'manchester [mode] [string] [print_type]'\n");
    printf("Description: Encode string and print selected output.\n");
    printf("[mode] = -s\n");
    printf("[string]\n");
        printf("\t Any String (MAX = 1024)\n");
    printf("[output_type]\n");
        printf("\t-b = Binary\n");
        printf("\t-h = Hex\n");
        printf("\t-a = Ascii\n");

    printf("\nMode = File Input Output\n");
    printf("Format: 'manchester [mode] [file] [print_type]'\n");
    printf("Description: Type string to encode in input.txt. Encode saved to output.txt.\n");
    printf("[mode] = -f\n");
    printf("[file] = Ex. file_name.txt");
    printf("[output_type]\n");
        printf("\t-b = Binary\n");
        printf("\t-h = Hex\n");
        printf("\t-a = Ascii\n");
}