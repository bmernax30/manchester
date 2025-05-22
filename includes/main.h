#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "util.h"
#include "encode.h"

//Errors
#define ERROR1 0
#define ERROR2 1
#define ERROR3 2

void StandardIn(void);
int ProcessArgs(int arg_total, char* arg_strings[]);
void Mode_PrintSelect(uint16_t len, uint8_t *input_string, uint8_t print_type);
int Mode_File(uint8_t * file_name, uint8_t print_type);
int8_t GetPrintType(uint8_t* flag);
int8_t ErrorOut(uint8_t error);
void PrintHelpScreen(void);

#endif
