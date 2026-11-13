
#include <stdio.h>

int main() {
    int n, frames;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of pages.\n");
        return 1;
    }

    int pages[n];

    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    if (frames <= 0) {
        printf("Invalid number of frames.\n");
        return 1;
    }

    int memory[frames];
    int last_used[frames];

    int page_faults = 0;
    int page_hits = 0;

    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
        last_used[i] = -1;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        int position = -1;

        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                position = j;
                break;
            }
        }

        if (found) {
            page_hits++;
            last_used[position] = i;
        } else {
            int lru_index = 0;

            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    lru_index = j;
                    break;
                }

                if (last_used[j] < last_used[lru_index]) {
                    lru_index = j;
                }
            }

            memory[lru_index] = pages[i];
            last_used[lru_index] = i;
            page_faults++;
        }

        printf("%d\t", pages[i]);

        for (int j = 0; j < frames; j++) {
            if (memory[j] == -1)
                printf("- ");
            else
                printf("%d ", memory[j]);
        }

        if (found)
            printf("\tHit\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nTotal Page Hits: %d\n", page_hits);
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
