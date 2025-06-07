#include <iostream>
#include <fcntl.h>           // For shm_open
#include <sys/mman.h>        // For mmap
#include <unistd.h>
#include <cerrno>
#include <cstring>

#define SHM_SIZE 10
const char* SHM_NAME = "/my_shm";  // POSIX shared memory name

int main() {
	int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to open shared memory: " << strerror(errno) << std::endl;
        return 1;
    }

    char* buffer = static_cast<char*>(mmap(nullptr, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0));
    if (buffer == MAP_FAILED) {
        std::cerr << "Memory mapping failed: " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "Receiver reading buffer:\n";
    for (int i = 0; i < SHM_SIZE; ++i) {
        std::cout << buffer[i];
    }
    std::cout << std::endl;

    munmap(buffer, SHM_SIZE);
    close(shm_fd);
    return 0;
}
