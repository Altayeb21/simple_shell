#include "main.h"

/**
* main - the shell build
* @alta: int vairable
* @classy: char variable
* *
* Return: (0)
*/

int main(int alta, char **classy)
{
char *prompt = "(ACshell) $ ";
char *lineptr;
size_t n = 0;

/* void variables of main */
(void)alta;
(void)classy;

printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", lineptr);

free(lineptr);
return (0);
}
