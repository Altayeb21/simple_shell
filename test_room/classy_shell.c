#include "main.h"

/**
* main - the shell build
* @count: number of words entered
* @argv: words array
*
* Return: (0)
*/

int main(int count, char **argv)
{
char *shell = "(ACshell)";

(void)argv;

printf("%s $: %d \n", shell, count);

return (0);
}
