
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *fp;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        fp = fopen("even.txt", "w");

        if (fp == NULL) {
            perror("File creation failed");
            exit(1);
        }

        printf("Child: Writing even numbers into file.\n");

        for (int i = 2; i <= 20; i += 2) {
            fprintf(fp, "%d ", i);
        }

        fclose(fp);
        exit(0);
    }
    else {
        wait(NULL);

        fp = fopen("even.txt", "r");

        if (fp == NULL) {
            perror("File opening failed");
            return 1;
        }

        int num;

        printf("\nParent: Reading even numbers from file:\n");

        while (fscanf(fp, "%d", &num) == 1) {
            printf("%d ", num);
        }

        printf("\n");

        fclose(fp);
    }

    return 0;
}
