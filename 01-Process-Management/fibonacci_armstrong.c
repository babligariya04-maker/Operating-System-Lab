
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
}

void armstrong(int n) {
    printf("Armstrong Numbers up to %d:\n", n);

    for (int num = 1; num <= n; num++) {
        int temp = num;
        int sum = 0;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        printf("\nChild Process:\n");
        fibonacci(n);
    }
    else {
        // Parent Process
        wait(NULL);

        printf("\nParent Process:\n");
        armstrong(n);
    }

    return 0;
}
