
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
        // Child Process - Print Odd Numbers
        printf("Child Process - Odd Numbers:\n");

        for (int i = 1; i <= 20; i += 2) {
            printf("%d ", i);
        }

        printf("\n");
    }
    else {
        // Parent Process - Print Even Numbers
        wait(NULL);

        printf("Parent Process - Even Numbers:\n");

        for (int i = 2; i <= 20; i += 2) {
            printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
