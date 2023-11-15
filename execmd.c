#include "main.h"
/**
* execmd - function to execute /my_shell.c commands
* @argv: array that containing command from shell
*/
void execmd(char **argv)
{
char *command_path = NULL;

if (argv)
{
/*get command*/
command_path = argv[0];

/*execute command with execve*/
if (execve(command_path, argv, NULL) == -1)
{
perror("ERROR ");
}

}

}
