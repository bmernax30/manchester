#ifndef __ENCODE_H_
#define __ENCODE_H_

//Types of Encryption- Combine = Oregon then Manchester
#define MANCHESTER 0
#define OREGON 1
#define COMBINE 2

//SINGLE- does either Oregon or Manchester
//DOUBLE- does both Oregon and Manchester
#define SINGLE_LEVEL_ENCODING 2
#define DOUBLE_LEVEL_ENCODING 4

#define OM_OUTPUT_0_MASK 0x99
#define OM_OUTPUT_1_MASK 0x66

#define MSB_MASK 0xF0
#define LSB_MASK 0x0F

void encode_Byte(uint8_t *input, uint8_t *output, uint8_t encode_type);

#endif