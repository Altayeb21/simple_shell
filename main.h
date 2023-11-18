#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function prototypes
void execmd(char **argv);
char *get_location(char *command_path);

#endif /* MAIN_H */
