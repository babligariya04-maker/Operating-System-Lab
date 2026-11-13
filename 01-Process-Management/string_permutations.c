
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[], int left, int right) {
    if (left == right) {
        printf("%s\n", str);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(&str[left], &str[i]);

        permute(str, left + 1, right);

        swap(&str[left], &str[i]);
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        printf("\nPermutations of the string:\n");

        permute(str, 0, strlen(str) - 1);
    }
    else {
        // Parent Process
        wait(NULL);
        printf("\nParent Process Completed.\n");
    }

    return 0;
}
