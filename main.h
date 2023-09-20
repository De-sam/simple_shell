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

extern char **environ;

/* TYPE DEFS */
typedef char *string;

/*FUNCTION PROTOTYPES*/
int printChar(char c);
int printString(char *str);
void execmd(char *prog_name, char **argv);
char *get_location(char *command);
string get_location_new(string command);
/*ssize_t _getline(char **lineptr, size_t *n, int fd);*/
char *tokenize(char *str, const char *delim);
int prompt(char *prog_name, char **command);
void print_environment(void);
char **set_args(char *command);
void set_env_variable(const char *variable, const char *value);
void unset_env_variable(const char *variable);
void change_directory(const char *new_dir);
int cmd_set_unset_env(char **argv);
int cmd_change_directory(char **argv);
void cmd_exit(char *command, char **argv);
string loc_perser(string path_copy, string command);
int _str_cmp(const char *string1, const char *string2);
char *_str_cat(char *dest, char *src);
size_t _str_len(const char *s);

/* MACROS */
#define TRUE 1
#define FALSE 0
#define PATH_MAX 4096

#endif
