#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef unsigned int uint;
/* String operations */
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_tolower(char *string);
int alpha(int r);
/* Print operations */
int _putchar(char c);
int _print(char *string);
int _printf(const char *format, ...);
/* Math operations */
int _abs(int num);
int itoa(int n, char s[]);
uint uitoa(uint n, char s[]);
/* Switch Hub */
int switch_hub(const char, char, int, int, va_list, int);
int spec_add(char *speclist, int speci, char c);
/* Conversion operations */
int base_op(char *buffer, uint number, int base, int pos, int lower);
int addstring(char *string, void *add, int pos);
int addnum(char *string, void *num, int pos);
int addunum(char *string, void *num, int pos);
/* Special operations */
char *rot13(char *string);
char *rev(char *string);
/* Memory operations */
char *_strdup(char *str);
/**
 * struct op - structure to store operations
 * @op: operation input
 * @f: operation value as a function pointer
 */
typedef struct op
{
	char op;
	int (*f)(char *string, void *add, int pos);
} op_t;
op_t *initializeops(void);
int (*get_op_func(char s))(char *, void *, int);
int binary(char *buffer, void *number, int pos);
int octal(char *buffer, void *number, int pos);
int upperhex(char *buffer, void *number, int pos);
int lowerhex(char *buffer, void *number, int pos);
int addchar(char *string, void *add, int pos);
int addpercent(char *string, void *add, int pos);
int addthis(char *string, char add, int pos);
#endif /* HOLBERTON_H */
