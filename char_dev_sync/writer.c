#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define THREADS 10
#define WRITES  1000

void *thread_func(void *arg) {
    int fd = open("/dev/racechardev", O_WRONLY);
    if (fd < 0) {
        perror("open");
        return NULL;
    }

    for (int i = 0; i < WRITES; i++) {
        if (write(fd, "X", 1) < 0) {
            perror("write");
            break;
        }
    }

    close(fd);
    return NULL;
}

int main() {
    pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
