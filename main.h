#ifndef _MAIN_H
#define _MAIN_H

/* HEADER FILES */
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* TYPE DEFS */
typedef char *string;

int printChar(char c);
int printString(char *str);
void execmd(char **argv);
char *get_location(char *command);
string get_location_new(string command);
ssize_t _getline(char **command, size_t *len, FILE *stream);
char *tokenize(char *str, const char *delim);
void prompt(char **command);
void print_environment(void);
char **set_args(char *command);

/* MACROS */
#define TRUE 1
#define FALSE 0

#endif
