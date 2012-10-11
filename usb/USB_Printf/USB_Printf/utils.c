/*
Title:    utils.c
Author:   Sven Arnold <s.arnold@alpha-technology.de> http://alpha-technology.de
Version:  0.1
Software: CodeSourcery GCC
License:

DESCRIPTION:


USAGE:


NOTES:

*/

/* Includes */
#include "utils.h"
#include <stdlib.h>

/* Functions */
/**
  * @brief  Creates a CPU Delay. delay(16795); results in a delay of 1 ms.
  * @param  count Count for the delay
  * @retval None
  */
void delay(unsigned int count){

	for(; count != 0; count--);
}


/**
  * @brief Creates a Delay in milliseconds
  * This method is provided for convenience.
  * @param  ms is the delay in milliseconds
  * @retval None
  */
void delayMs(unsigned int ms){

	delay(16795 * ms);
}

/**
 * @brief  Converts string into int
 * @param  *s String to convert
 * @retval converted integer
 */
int atoi(const char *s){
	static const char digits[] = "0123456789"; // legal digits in order
	unsigned val = 0; // value we're accumulating
	int neg = 0; // set to true if we see a minus sign

	// skip whitespace
	while (*s == ' ' || *s == '\t'){

		s++;
	}

	// check for sign
	if (*s == '-'){

		neg = 1;
		s++;
	} else if (*s == '+'){

		s++;
	}

	// process each digit
	while (*s){

		const char *where;
		unsigned digit;

		// look for the digit in the list of digits (using char * strchr ( const char *, int ); )
		where = strchr(digits, *s);
		if (where == NULL){

			// not found; not a digit, so stop
			break;
		}

		// get the index into the digit list, which is the value
		digit = (where - digits);

		// could (should?) check for overflow here

		// shift the number over and add in the new digit
		val = val*10 + digit;

		// look at the next character
		s++;
	}

	// handle negative numbers
	if (neg){

		return -val;
	}

	// done
	return val;
}

/**
 * @brief  Search a character in the given string.
 * @param  Pointer to the start of the string to search.
 * @param  The character to find.
 * @retval Returns a pointer to the character location.
 */
char * strchr(const char *pString, int character)
{
    char * p = (char *)pString;
    char   c = character & 0xFF;

    while(*p != c) {
        if (*p == 0) {
            return 0;
        }
        p++;
    }
    return p;
}


/**
   http://www.jb.man.ac.uk/~slowe/cpp/itoa.html
 * C++ version 0.4 char* style "itoa":
 * Written by Luk‡s Chmela
 * Released under GPLv3.
 */
char* ltoa(long value, char* result)
{
    char* ptr = result, *ptr1 = result, tmp_char;
    long tmp_value;


    do
    {
        tmp_value = value;
        value /= BASE;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * BASE)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';

    *ptr-- = '\0';

    while(ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }

    return result;
}
