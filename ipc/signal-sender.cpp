#include <iostream>
#include <csignal>
#include <cerrno>

int main() {
    	int x;
	std::cout<<"Enter PID of Reciver: ";
	std::cin>>x;
	int sigID;
	while (1){
		std::cout<<"Enter Signal number: ";
		std::cin>>sigID;
		if(kill(x,sigID)==0){
			std::cout<<"Signal: "<<sigID<<" has been sended to reciver: "<<x<<"\n";
		} else {
			std::cout<<"Error sending signal";
		}
	}
	return 0;
}
