
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child Process - Prime Check
        int flag = 1;

        if (n <= 1) {
            flag = 0;
        }
        else {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
            printf("\n%d is a Prime Number.\n", n);
        else
            printf("\n%d is not a Prime Number.\n", n);
    }
    else {
        // Parent Process - Factorial
        wait(NULL);

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        printf("Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}
