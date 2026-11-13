#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0)
        printf("Child Process\n");
    else if (pid > 0)
        printf("Parent Process\n");
    else
        printf("Fork failed!\n");

    return 0;
}