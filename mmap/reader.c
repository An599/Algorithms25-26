#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SHM_NAME "/my_shared_memory"
#define SIZE 4096

int main(void) {
    int fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    char *ptr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    printf("Reader read: %s\n", ptr);

    munmap(ptr, SIZE);
    close(fd);

    shm_unlink(SHM_NAME);

    return 0;
}
