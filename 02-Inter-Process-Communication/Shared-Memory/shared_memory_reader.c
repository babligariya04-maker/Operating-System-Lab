
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;
    char *shared_memory;

    key = ftok(".", 'B');

    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, 1024, 0666);

    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shared_memory = (char *)shmat(shmid, NULL, 0);

    if (shared_memory == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Message from shared memory: %s\n", shared_memory);

    shmdt(shared_memory);

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    return 0;
}
