/*
Title:    
Author:   Sven Arnold <s.arnold@alpha-technology.de> http://alpha-technology.de
Version:  0.1
Software: CodeSourcery GCC
License:

DESCRIPTION:


USAGE:


NOTES:

*/

/* __UTILS_H */
#ifndef __UTILS_H
#define __UTILS_H

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

/* Defines */
#define BASE 10

/* Type definitions */
typedef enum { false, true } bool;

/* Functions */
void delay(unsigned int count);
void delayMs(unsigned int ms);
int atoi(const char *s);
char * strchr(const char *pString, int character);
char* ltoa(long value, char* result);

 /* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H */

