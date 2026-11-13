
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());

        exit(10);
    }
    else {
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent Process\n");
            printf("Child exited with status: %d\n",
                   WEXITSTATUS(status));
        }
    }

    return 0;
}
