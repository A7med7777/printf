#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#define BUF_SIZE 1024
#define PLUS_FLAG 1
#define SPACE_FLAG 2
#define HASH_FLAG 4

int _putchar(char c);
int _printf(const char *format, ...);
int print_binary(char *buffer, unsigned int n);
int print_unsigned(char *buffer, unsigned int n, int flags);
int print_octal(char *buffer, unsigned int n, int flags);
int print_hex(char *buffer, unsigned int n, int upper, int flags);
int print_string_S(char *buffer, char *s);

#endif
