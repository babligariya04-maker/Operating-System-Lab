
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char message[100];

    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
    }

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    fd = open("myfifo", O_WRONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, message, strlen(message) + 1);

    close(fd);

    printf("Message sent successfully!\n");

    return 0;
}
