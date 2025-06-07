#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <cstring>

void signal_handler(int sig) {
	//std::cout<<"Signal with id: "<<signal<<" Recived";    
	char buffer[100];
   	int len = snprintf(buffer, sizeof(buffer), "Signal with id: %d received\n", sig);
    	write(STDOUT_FILENO, buffer, len);
}

int main() {
	pid_t pid = getpid();
    	std::cout << "PID: " << pid << std::endl;

	for (int i = 1; i < NSIG; ++i) {
        	if (i == SIGKILL || i == SIGSTOP) {
            		continue;
        	}
        	signal(i, signal_handler);
    	}

    	while (true) {
        	pause();
    	}
    	return 0;
}
