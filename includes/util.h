#ifndef __UTIL_H_
#define __UTIL_H_

#define MAX_IN_BUFFER_SIZE 1024
#define MAX_OUT_BUFFER_SIZE 1024
#define MAX_FILE_NAME_SIZE 64
#define BITS_PER_CHAR   8
#define BIT_MASK 0x80

#define BINARY 0
#define HEX 1
#define ASCII 2

void util_AsciitoBinary(uint8_t input_ch, uint8_t *output);
uint8_t util_BinarytoAscii(uint8_t *input_binary);
void util_PrintBinary(uint8_t *input);
uint16_t util_ReadIn(uint8_t *input);
uint16_t util_ReadInByte(uint8_t *input);
void util_WriteOut(uint8_t *output, uint16_t len, uint8_t type);
void util_WriteOutFile(FILE * fptr, uint8_t *output, uint16_t len, uint8_t type);

#endif