#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("/dev/memchardev", O_RDWR);
    char buf[128];

    write(fd, "hello kernel", 12);
    read(fd, buf, 12);
    buf[12] = '\0';

    printf("Read back: %s\n", buf);

    close(fd);
    return 0;
}
