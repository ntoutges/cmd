#ifndef _CMD_STR_H
#define _CMD_STR_H

/**
 * @file cmd_str.h
 * @author Nicholas T.
 * @brief Various functions for parsing/building strings
 * @version 0.1
 * @date 2026-05-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Float to Max ASCII
 * Convert some floating point number to a string, conforming to the `atof` parser's standard
 * Attempts to optimize the following constraints, in the following order:
 * 1. Maximum precision in the available buffer
 * 2. Simplest form to parse
 * 
 * This function will add a NULL terminator to the end of the produced string
 * 
 * @param val   The value to stringify
 * @param buf   The buffer to fill
 * @param size  The available bytes in the buffer
 * @return      The filled bytes. Same as the input `buf`
 */
char* cmd_str_ftoma(double val, char* buf, int size);

/**
 * Int to ASCII
 * Convert some integer to a string, conforming to the `atoi` parser's standard
 * If not enough space to fit the value, produces the empty string

 * This function will add a NULL terminator to the end of the produced string
 * 
 * @param val   The value to stringify
 * @param buf   The buffer to fill
 * @param size  The available bytes in the buffer
 * @return      The filled bytes. Same as the input `buf`
 */
char* cmd_str_itoa(int32_t val, char* buf, int size);

#ifdef __cplusplus
}
#endif

#endif