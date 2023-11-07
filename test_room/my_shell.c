#include <main.h>

int main(int alta, char **clasy){
    char *prompt = "(ACshell) $ ";
    char *lineptr;
    size_t n = 0;

    /* void variables of main */
    (void)alta; (void)clasy;

    printf("%s", prompt);
    getline(&lineptr, &n, stdin);
    printf("%s\n", lineptr);

    free(lineptr);
    return (0);
}