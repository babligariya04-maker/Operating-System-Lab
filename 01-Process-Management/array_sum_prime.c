
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int n, arr[100];

    printf("Enter the number of elements: ");
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
        // Child Process
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        printf("\nChild Process\n");
        printf("Sum of array elements = %d\n", sum);

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

        if (flag)
            printf("%d is a Prime Number.\n", sum);
        else
            printf("%d is not a Prime Number.\n", sum);
    }

    return 0;
}
