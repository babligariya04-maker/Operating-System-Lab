
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        printf("Child Process Started\n");
        printf("Child PID: %d\n", getpid());
        sleep(2);
        printf("Child Process Completed\n");
    }
    else {
        printf("Parent Process Waiting for Child...\n");

        wait(NULL);

        printf("Parent Process Resumed\n");
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}
