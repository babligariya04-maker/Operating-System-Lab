
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, arr[100];
    int evenSum = 0, oddSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child Process - Sum of Even Elements
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                evenSum += arr[i];
            }
        }

        printf("\nChild Process\n");
        printf("Sum of even elements = %d\n", evenSum);
    }
    else {
        // Parent Process - Sum of Odd Elements
        wait(NULL);

        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                oddSum += arr[i];
            }
        }

        printf("\nParent Process\n");
        printf("Sum of odd elements = %d\n", oddSum);
    }

    return 0;
}
