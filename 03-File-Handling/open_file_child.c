
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *fp;

    fp = fopen("sample.txt", "w");

    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }

    fprintf(fp, "Welcome to Operating System Lab.\n");
    fclose(fp);

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        fp = fopen("sample.txt", "r");

        if (fp == NULL) {
            perror("File opening failed");
            exit(1);
        }

        printf("Child: File opened successfully.\n");
        fclose(fp);
    }
    else {
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}
