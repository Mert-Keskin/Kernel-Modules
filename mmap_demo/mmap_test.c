// mmap_test.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEV_PATH "/dev/mmap_demo"
#define MMAP_SIZE 4096
#define MMAP_DEMO_PRINT _IO('m', 1)

int main(void)
{
    int fd;
    char *map;

    fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    map = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    printf("Initial page content: \"%s\"\n", map);

    /* Write into mapped area */
    strncpy(map, "User wrote: Hello from user-space mmap!\n", MMAP_SIZE - 1);
    /* Ensure visible; not necessary but safe */
    msync(map, MMAP_SIZE, MS_SYNC);

    /* Ask kernel to print what it sees */
    if (ioctl(fd, MMAP_DEMO_PRINT) < 0) {
        perror("ioctl");
    }

    /* Read back and print */
    printf("After write, user sees: \"%s\"\n", map);

    munmap(map, MMAP_SIZE);
    close(fd);
    return 0;
}
