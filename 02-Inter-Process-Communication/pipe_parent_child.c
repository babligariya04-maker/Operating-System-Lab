
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char message[] = "Graphic Era";
    char buffer[100];

    if (pipe(fd) == -1) {
        printf("Pipe creation failed!\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        // Child Process - Write to Pipe
        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);
    }
    else {
        // Parent Process - Read from Pipe
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        printf("Message received from child: %s\n", buffer);

        close(fd[0]);

        wait(NULL);
    }

    return 0;
}
