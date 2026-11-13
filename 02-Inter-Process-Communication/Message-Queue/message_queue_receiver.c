
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok(".", 'A');

    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0600);

    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0) == -1) {
        perror("msgrcv");
        return 1;
    }

    printf("Received Message: %s\n", msg.msg_text);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    return 0;
}
