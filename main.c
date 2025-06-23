#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

// Function to parse the input line into arguments
void parse_input(char *input, char **args) {
    int i = 0;
    args[i] = strtok(input, " \t\n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \t\n");
    }
}

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        write(STDOUT_FILENO, "naveenshell> ", 13);

        ssize_t nread = read(STDIN_FILENO, input, MAX_INPUT);
        if (nread <= 0) break;

        input[nread] = '\0'; // terminate the string

        if (strcmp(input, "exit\n") == 0) break;

        parse_input(input, args);
        if (args[0] == NULL) continue;

        pid_t pid = fork();

        if (pid == 0) {
            // In child
            execvp(args[0], args);
            write(STDERR_FILENO, "Command not found\n", 19);
            _exit(1);
        } else {
            // In parent
            wait(NULL);
        }
    }

    return 0;
}
