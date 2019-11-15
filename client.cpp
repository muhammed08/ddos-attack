#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <iostream>
#include <signal.h>
#define PORT 443
#define IP "xxx.xxxx.xxxx.xxxx"

using namespace std;

int createConn()
{
		struct sockaddr_in address; 
		int sock = 0, valread; 
		struct sockaddr_in serv_addr; 
		//char message[100];
		//char buffer[1024] = {0}; 
	
		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)  
		{ 
			printf("\n Socket creation error \n"); 
			return 0; 
		} 

		memset(&serv_addr, '0', sizeof(serv_addr)); 

		serv_addr.sin_family = AF_INET; 
		serv_addr.sin_port = htons(PORT); 
	

		if(inet_pton(AF_INET, IP, &serv_addr.sin_addr)<=0) 
		{ 
			printf("\nInvalid address/ Address not supported \n"); 
			return 0; 
		} 

		if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		{ 
			printf("\nConnection Failed \n"); 
			return 0 ; 
		} 


		cout<<"Connection Success";
		return 1;
		
}
int main()
{
	int i=0;
	while(1)
	{
    int chpid = fork();
    if (chpid == 0)
    {
		  t= createConn();
      break;
    } 
		
	}
}
