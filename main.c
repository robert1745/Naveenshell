// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("naveenshell> ");          // Show prompt
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) {
            break;  // Handle Ctrl+D
        }

        // Remove newline at the end
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Fork and exec to run the command
        pid_t pid = fork();
        if (pid == 0) {
            // Child
            execlp(input, input, NULL);
            perror("Command failed");
            exit(1);
        } else {
            // Parent
            wait(NULL);
        }
    }

    return 0;
}
