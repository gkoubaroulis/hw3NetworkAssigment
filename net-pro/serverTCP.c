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
    char maxBuffer[]="Hello World";
    int sockfd, clientfd;
    struct sockaddr_in servaddr,clientAddress;

//-------SOCKER-arxikopoiisi--------------------------------------    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
        {
            printf("Socker Error -- DieWithError sockfd() failed.");
            exit(0);
        }
    else
        {
            printf("Socket created with id= %s \n",sockfd);
        }
//-------BIND------------------------------------------
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    printf("INADDR_ANY = %s\n",INADDR_ANY);
    printf("servaddr.sin_addr.s_addr = %s\n",servaddr.sin_addr.s_addr); 
	servaddr.sin_port = htons(servPort); 
//int bind (int sockfd, struct sockaddr *myaddr, int addrlen)
    if ((bind(sockfd, (struct sockaddr_in *) &servaddr, sizeof(servaddr))) < 0) 
        { 
            printf("DieWithError bind() failed...\n"); 
            exit(0); 
        } 
	else
		printf("Socket successfully binded..\n"); 

//-------CONNECT---------------------------------------

    if(listen(sockfd,MAXPENDING)<0)
        {
            printf("DieWithError listen() failed....\n");
            exit(0);
        }
    else
        {
           printf("Listen is correct.");
        }
//------ACCEPT------
/*
    if ((accept(sockfd,(struct servaddr_in *)&clientAddress,sizeof(clientAddress.sin_zero))<0))
        {
            printf("DieWithError accept() failed.\n");    /* code 
            exit(0);
        }
    else
        {
            printf("Accepted");
        }
 */  
    while(1){
        if(clientfd=(clientaccept(sockfd,(struct servaddr_in *)&clientAddress,sizeof(clientAddress.sin_zero)))<0)
        {
            printf("DieWithError accept() failed.\n");
            exit(-1);
            /* data */
        };
        send(clientfd,maxBuffer,strlen(maxBuffer),0);
        printf("Sending %d bytes to client : %c\n",sizeof(maxBuffer),clientAddress.sin_addr.s_addr);
        
        close(clientfd);
        }
        close(sockfd); //close the socket
    
    
    
    return 0;
}