#include "main.h"

/**
* main - the shell build
*
* @argc: counting the number of arguments entered
* @argv: is array to contain our command words
*
* Return: (0)
*/

int main(int argc, char **argv)
{
while (1)
{char *shell = "(ACshell)", *command = NULL, *command_copy = NULL, *token;
size_t n = 0;
ssize_t nchars_read;
const char *delim = " \n";
int tokens_num = 0, i;
(void)argc;
printf("%s $: ", shell);
nchars_read = getline(&command, &n, stdin);
if (nchars_read == -1)
{printf("shell shutdown. . . \n");
return (-1);
}
command_copy = malloc(sizeof(char) * nchars_read);
if (command_copy == NULL)
{perror("tsh: memory allocation ERROR!");
return (-1);
}
strcpy(command_copy, command);
token = strtok(command, delim);
while (token != NULL)
{tokens_num++;
token = strtok(NULL, delim);
}
tokens_num++;
argv = malloc(sizeof(char *) * tokens_num);
token = strtok(command_copy, delim);
for (i = 0; token != NULL; i++)
{argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
execmd(argv);
free(command);
free(command_copy);
}
return (0);
}
