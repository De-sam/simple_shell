#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

typedef char *string;

int printChar(char c);
int printString(char *str);
void execmd(char **argv);
char *get_location(char *command);
string get_location_new(string command);
__ssize_t _getline(char **command, size_t *len, FILE *stream);
char *tokenize(char *str, const char *delim);
ssize_t prompt(char **command);

#endif
