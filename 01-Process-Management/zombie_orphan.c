
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid1 == 0) {
        // Supervisor Child Process
        printf("Supervisor Process Started\n");
        printf("Supervisor PID: %d\n", getpid());

        pid2 = fork();

        if (pid2 < 0) {
            printf("Second fork failed!\n");
            exit(1);
        }

        if (pid2 == 0) {
            // Worker Child Process
            printf("Worker Child Process\n");
            printf("Worker PID: %d\n", getpid());
            printf("Worker Process Terminating...\n");
            exit(0);
        }
        else {
            printf("Supervisor waiting for 20 seconds...\n");
            sleep(20);

            printf("Supervisor collecting child status...\n");
            wait(NULL);
            printf("Worker process collected.\n");
        }
    }
    else {
        // Original Parent Process
        printf("Original Parent Process Terminating.\n");
        exit(0);
    }

    return 0;
}
