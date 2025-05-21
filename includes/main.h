#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "util.h"
#include "encode.h"

void StandardIn(void);
int ProcessArgs(int arg_total, char* arg_strings[]);
void StandardEncode(uint16_t len, uint8_t *input_string);

#endif
