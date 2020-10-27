#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/* String operations */
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_tolower(char *string);
int alpha(int r);

/* Math operations */
int _abs(int num);
int itoa(int n, char s[]);
uint uitoa(uint n, char s[]);

/* Conversion operations */
int base_op(char *buffer, unsigned long n, int b, int p, int l, int *retval);
int addstring(char *string, void *add, int pos, int *retval);
int addnum(char *string, void *num, int pos, int *retval);
int addunum(char *string, void *num, int pos, int *retval);

/* Memory operations */
char *_strdup(char *str);

/* Print operations */
int _putchar(char c, int *retval);
int _print(char *string, int *retval);
int _printf(const char *format, ...);

/**
 * struct op - structure to store operations
 * @op: operation input
 * @f: operation value as a function pointer
 */
typedef struct op
{
	char op;
	int (*f)(char *string, void *add, int pos, int *retval);
} op_t;
op_t *initializeops(void);
int (*get_op_func(char s))(char *, void *, int, int *);
int binary(char *buffer, void *number, int pos, int *retval);
int octal(char *buffer, void *number, int pos, int *retval);
int upperhex(char *buffer, void *number, int pos, int *retval);
int lowerhex(char *buffer, void *number, int pos, int *retval);
int addchar(char *string, void *add, int pos, int *retval);
int addpercent(char *string, void *add, int pos, int *retval);
int addthis(char *string, char add, int pos, int *retval);
int address(char *string, void *add, int pos, int *retval);

/* Switch Hub */
int switch_hub(const char *f, char *b, int i, int j, va_list args, int *r);
int spec_add(char *speclist, int speci, char c);

/* Special operations */
int rot13(char *string, void *add, int pos, int *retval);
int rev(char *string, void *add, int pos, int *retval);

#endif
