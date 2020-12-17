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
    char stringToSend[]="Hello Server!";
    int clientfd;
    struct sockaddr_in clientAddress;

//-------SOCKER-arxikopoiisi--------------------------------------    
    clientfd=socket(AF_INET,SOCK_STREAM,0);
    if(clientfd<0)
        {
            printf("Socker Error -- DieWithError sockfd() failed.");
            exit(0);
        }
    else
        {
            printf("Socket created with id= %s \n",clientfd);
        }
//-------Connect------------------------------------------
	// assign IP, PORT 
	clientAddress.sin_family = AF_INET; 
	clientAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    printf("INADDR_ANY = %s\n",INADDR_ANY);
    printf("servaddr.sin_addr.s_addr = %s\n",clientAddress.sin_addr.s_addr); 
	clientAddress.sin_port = htons(servPort); 
    if ((connect(clientfd, (struct sockaddr_in *) &clientAddress, sizeof(clientAddress))) < 0) 
        { 
            printf("DieWithError bind() failed...\n"); 
            exit(0); 
        } 
	else
		printf("Socket successfully connected..\n"); 

//-------send data---------------------------------------
    int lengthStrintToSend=sizeof(stringToSend);
    if (send(clientfd,stringToSend,lengthStrintToSend,0)!=lengthStrintToSend){
        printf("DieWithError sent a differnt number of bytes than expected");
    }
    
    
    
    
    
    
    
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