
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    read(fd, buffer, sizeof(buffer));

    printf("Message received: %s\n", buffer);

    close(fd);

    unlink("myfifo");

    return 0;
}
