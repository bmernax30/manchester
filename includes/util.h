#ifndef __UTIL_H_
#define __UTIL_H_

#define MAX_IN_BUFFER_SIZE 1024
#define MAX_OUT_BUFFER_SIZE 1024
#define BITS_PER_CHAR   8
#define BIT_MASK 0x80

void util_AsciitoBinary(uint8_t input_ch, uint8_t *output);
uint8_t util_BinarytoAscii(uint8_t *input_binary);
void util_PrintBinary(uint8_t *input);
void util_PrintBinaryBuffer(uint8_t *input, uint16_t len);
uint16_t util_ReadIn(uint8_t *input);
void util_WriteOut(uint8_t *output, uint16_t len);
void util_NewLineOut(void);

#endif