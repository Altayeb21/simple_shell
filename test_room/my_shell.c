#include "main.h"

/**
* main - the shell build
*
* Return: (0)
*/

int main(void)
{
/* creating infinite loop (shell running) */
while (1)
{
char *shell = "(ACshell)";
char *command = NULL, *command_copy = NULL;
char **argv;
size_t n = 0;
ssize_t nchars_read;
const char *delim = " \n";
int tokens_num = 0;
char *token;
int i; /*1st for loop int*/
int j; /*2nd for loop int*/

printf("%s $: ", shell);
nchars_read = getline(&command, &n, stdin);

/*checking getline func (CTRL+D to exit)*/
if (nchars_read == -1)
{
printf("shell shutdown. . . \n");
return (-1);
}

/* allocate space for command_copy */
command_copy = malloc(sizeof(char) * nchars_read);
if (command_copy == NULL)
{
perror("tsh: memory allocation ERROR!");
return (-1);
}

/* copy the command to command_copy */
strcpy(command_copy, command);

/** split the string (command) into an array of words **/
/* calculate tokens number */
token = strtok(command, delim);

while (token != NULL)
{
tokens_num++;
token = strtok(NULL, delim);
}

tokens_num++;

/* allocate space for stings array */
argv = malloc(sizeof(char *) * tokens_num);

/* storing tokens in argv array */
token = strtok(command_copy, delim);

for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);

token = strtok(NULL, delim);
}

argv[i] = NULL;

/* print the content of argv (command) */
for (j = 0; j < tokens_num - 1; j++)
{
printf("%s ", argv[j]);
}

printf("\n");

/* free up memory*/
free(token);
free(argv);
free(command);
free(command_copy);
}

return (0);
}
