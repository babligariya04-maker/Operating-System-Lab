
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *fp;

    fp = fopen("student.txt", "w");

    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }

    fprintf(fp, "Name: Aditya\n");
    fprintf(fp, "Roll Number: 123456\n");
    fprintf(fp, "Class: B.Tech CSE\n");

    fclose(fp);

    printf("Parent: Data written to file successfully.\n");

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        char line[100];

        fp = fopen("student.txt", "r");

        if (fp == NULL) {
            perror("File opening failed");
            exit(1);
        }

        printf("\nChild: Reading data from file:\n");

        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }

        fclose(fp);
    }
    else {
        wait(NULL);
        printf("\nParent: Child process completed.\n");
    }

    return 0;
}
