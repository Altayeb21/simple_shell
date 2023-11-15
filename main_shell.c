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
{
char *shell = "(ACshell)";
char *command = NULL, *command_copy = NULL;
size_t n = 0;
ssize_t nchars_read;
const char *delim = " \n";
int tokens_num = 0;
char *token;
char *exit = "exit";
int i;
int j;
int result;
(void)argc;
printf("%s $: ", shell);
nchars_read = getline(&command, &n, stdin);
if (nchars_read == -1)
{
printf("shell shutdown. . . \n");
return (-1);
}
command_copy = malloc(sizeof(char) * nchars_read);
if (command_copy == NULL)
{
perror("tsh: memory allocation ERROR!");
return (-1);
}
strcpy(command_copy, command);
token = strtok(command, delim);
while (token != NULL)
{
tokens_num++;
token = strtok(NULL, delim);
}
tokens_num++;
argv = malloc(sizeof(char *) * tokens_num);
token = strtok(command_copy, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
result = strcmp(argv[0], exit);
if (result == 0)
{
printf("shell exiting. . . .\n");
return (-1);
}
printf("running command ( ");
for (j = 0; j < tokens_num - 1; j++)
{
printf("%s ", argv[j]);
}
printf(" ) . . .\n");
execmd(argv);
free(command);
free(command_copy);
}
return (0);
}
