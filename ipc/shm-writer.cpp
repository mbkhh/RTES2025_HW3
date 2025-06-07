#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>

#define SHM_SIZE 10
const char* SHM_NAME = "/my_shm";

int main() {
	int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to create shared memory: " << strerror(errno) << std::endl;
        return 1;
    }

    // Set the size
    if (ftruncate(shm_fd, SHM_SIZE) == -1) {
        std::cerr << "Failed to set size: " << strerror(errno) << std::endl;
        return 1;
    }

    // Map the memory
    char* buffer = static_cast<char*>(mmap(nullptr, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (buffer == MAP_FAILED) {
        std::cerr << "Memory mapping failed: " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "Sender started. Type messages (Ctrl+C to quit).\n";

    int write_pos = 0;
    std::string input;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        for (char ch : input) {
            buffer[write_pos] = ch;
            write_pos = (write_pos + 1) % SHM_SIZE;
       	}
    }

    munmap(buffer, SHM_SIZE);
    close(shm_fd);
    return 0; 
}
