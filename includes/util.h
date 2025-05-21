#define BITS_PER_CHAR   8
#define BIT_MASK 0x80

int8_t asciitobinary(uint8_t input_ch, uint8_t *output);
int8_t binarytoascii(uint8_t *input_binary, uint8_t output_ch);
void printbinary(uint8_t *input);