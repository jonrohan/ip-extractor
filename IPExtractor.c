//Jon Rohan
//CS3260 Net-Centric Computing Programming Assignment 1
//02.04.2005
//This assignment is used to determine the IP address of the 
//machine the program is being run on. This program is 
//Unix specific. 

#include <stdio.h>
#include <netdb.h>

int main()
{
	char hostn[400]; //placeholder for the hostname
	struct hostent *hostIP; //placeholder for the IP address
	
	//if the gethostname returns a name then the program will get the ip address using gethostbyname
	if((gethostname(hostn, sizeof(hostn))) == 0) 
  	{
		hostIP = gethostbyname(hostn); //the netdb.h function gethostbyname
		printf("IP address: %s\n", inet_ntoa(*(struct in_addr *)hostIP->h_addr));
  	}
	else
	{
    		printf("ERROR:FC4539 - IP Address not found."); //error if the hostname is not found
  	}
  	return 0;
}
