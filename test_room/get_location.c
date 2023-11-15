#include "main.h"

/**
* get_location - is function to get and generate command path
* @command_path: is the command line optained from shell
*
* Return: it's the path of command at the environment
*/

char *get_location(char *command_path)
{
char *path, *path_c, *path_tok, *file_path;
int command_l, directory_l;
struct stat buffer;
path = getenv("PATH");
if (path)
{
path_c = strdup(path);
command_l = strlen(command_path);
path_tok = strtok(path_c, ":");
while (path_tok != NULL)
{
directory_l = strlen(path_tok);
file_path = malloc(command_l + directory_l + 2);
strcpy(file_path, path_tok);
strcat(file_path, "/");
strcat(file_path, command_path);
strcat(file_path, "\0");

if (stat(file_path, &buffer) == 0)
{
free(path_c);
return (file_path);
}
else
{
free(file_path);
path_tok = strtok(NULL, ":");
}
}
free(path_c);
if (stat(command_path, &buffer) == 0)
{
return (command_path);
}
return (NULL);
}
return (NULL);
}
