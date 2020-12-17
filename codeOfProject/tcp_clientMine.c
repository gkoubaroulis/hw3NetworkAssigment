#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h>
#include<sys/socket.h>

#define MAX 80
#define servPort  2019    
#define MAXPENDING 5
    
int main(int argc, char *argv){
    char maxBuffer[MAX];
    bzero(maxBuffer,MAX);
    int sockfd, n;
    struct sockaddr_in servaddr,clientAddress;
    /*struct sockaddr_in
    {
        uint8_t sin_len;            //length of stracture(16)
        sa_family_t sin_family;     //AF_INET
        in_port_t   sin_port;       //16-bit TCP or UDP port number
        struct in_addr sin_addr;    //(sin_addr=32bitIPv4 address network byte orderd
        char    sin_zero[8];
        
    };
    */
    if(argc!=2){
        printf("Usage: %s <ipaddress>\n",argv[0]);
    }
//-------SOCKER-arxikopoiisi--------------------------------------    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("Socker Error -- DieWithError sockfd() failed.");
        exit(0);
    }
    else
    {
        printf("Socket created with id= %s \n",sockfd);
    }
    ;
//-------BIND------------------------------------------
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl("127.0.0.1");//INADDR_ANY); 
	servaddr.sin_port = htons(servPort); 
//int bind (int sockfd, struct sockaddr *myaddr, int addrlen)
    if ((bind(sockfd, (struct sockaddr_in *) &servaddr, sizeof(servaddr))) < 0) { 
		printf("DieWithError bind() failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 
//-------CONNECT---------------------------------------
    if(listen(sockfd,MAXPENDING)<0){
        printf("DieWithError listen() failed....\n");
        exit(0);
        }
        else
        {
            printf("Listen is correct.");
        }
//------ACCEPT------
    if ((accept(sockfd,(struct servaddr_in *)&clientAddress,sizeof(clientAddress.sin_zero))<0))
        {
            printf("DieWithError accept() failed.\n");    /* code */
            exit(0);
        }
    for(;;){
        bzero(maxBuffer,MAX);
        //------read----------
        read(sockfd,maxBuffer,sizeof(maxBuffer));
        printf("Message from Client %s\t :\n",maxBuffer);
        bzero(maxBuffer,MAX);
        n=0;
        while((maxBuffer[n++]=getchar()) != '\n'); //----copy server message in the buffer
        write(sockfd,maxBuffer,sizeof(maxBuffer)); //----send that buffer to client
   		// if msg contains "Exit" then server exit and chat ended. 
		if (strncmp("exit", maxBuffer, 4) == 0) { 
			printf("Server Exit...\n"); 
			break; 
		} 
    }
    close(sockfd); //close the socket
    return 0;

}