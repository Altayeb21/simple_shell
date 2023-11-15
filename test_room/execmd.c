#include "main.h"
/**
* execmd - function to execute /my_shell.c commands
* @argv: array that containing command from shell
*/
void execmd(char **argv)
{
char *command_path = NULL, *real_command = NULL;

if (argv)
{
/*get command*/
command_path = argv[0];

/* generating the path of command */
real_command = get_location(command_path);

/*execute command with execve*/
if (execve(real_command, argv, NULL) == -1)
{
perror("ERROR ");
}

}

}
