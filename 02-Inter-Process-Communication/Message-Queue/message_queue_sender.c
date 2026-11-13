
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);

    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    msg.msg_type = 1;

    printf("Enter a message: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully!\n");

    return 0;
}
