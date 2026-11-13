
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5, sum = 0;

    if (pipe(fd) == -1) {
        printf("Pipe creation failed!\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        // Child Process - Check Prime
        close(fd[1]);

        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);

        int flag = 1;

        if (sum <= 1) {
            flag = 0;
        }
        else {
            for (int i = 2; i * i <= sum; i++) {
                if (sum % i == 0) {
                    flag = 0;
                    break;
                }
            }
        }

        printf("Child Process\n");
        printf("Received Sum = %d\n", sum);

        if (flag)
            printf("%d is a Prime Number.\n", sum);
        else
            printf("%d is not a Prime Number.\n", sum);
    }
    else {
        // Parent Process - Calculate Sum
        close(fd[0]);

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        printf("Parent Process\n");
        printf("Sum of array elements = %d\n", sum);

        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);

        wait(NULL);
    }

    return 0;
}
