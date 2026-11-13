
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    for (int i = 1; i <= 3; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
            return 1;
        }

        if (pid == 0) {
            printf("\nChild Process %d\n", i);
            printf("Child PID: %d\n", getpid());
            printf("Parent PID: %d\n", getppid());
            return 0;
        }
    }

    // Original Parent waits for all three children
    for (int i = 1; i <= 3; i++) {
        wait(NULL);
    }

    printf("\nAll child processes completed.\n");

    return 0;
}
