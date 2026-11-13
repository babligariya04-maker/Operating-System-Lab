
#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);

        if (p[i].burst_time < 0) {
            printf("Burst time cannot be negative.\n");
            return 1;
        }
    }

    // Sort processes by burst time using insertion sort
    for (int i = 1; i < n; i++) {
        struct Process key = p[i];
        int j = i - 1;

        while (j >= 0 && p[j].burst_time > key.burst_time) {
            p[j + 1] = p[j];
            j--;
        }

        p[j + 1] = key;
    }

    p[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        p[i].waiting_time =
            p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        p[i].turnaround_time =
            p[i].waiting_time + p[i].burst_time;

        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i].id,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f",
           total_waiting_time / n);

    printf("\nAverage Turnaround Time: %.2f\n",
           total_turnaround_time / n);

    return 0;
}
