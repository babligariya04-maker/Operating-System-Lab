
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        printf("Child Process Started\n");
        printf("Child PID: %d\n", getpid());
        printf("Original Parent PID: %d\n", getppid());

        sleep(5);

        printf("\nAfter Parent Terminates:\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());
    }
    else {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent Process Terminating...\n");
    }

    return 0;
}
