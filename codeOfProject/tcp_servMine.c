#include <stdio.h> 
// #include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 80
#define servPort  8180    
#define MAXPENDING 5
    
int main(){

    // char maxBuffer[MAX];
    // bzero(maxBuffer,MAX);
    int serversock, n;
    struct sockaddr_in servaddr; //,clientAddress;
    
    int newSocket;
    struct sockaddr_in servaddr; //,clientAddress;
    socklen_t addr_size;
    char buffer[1024];
//-------SOCKER-arxikopoiisi--------------------------------------    
    if (serversock=socket(AF_INET,SOCK_STREAM,0)<0)
    {
        printf("Socker Error -- DieWithError sockfd() failed.");
        exit(0);
    }
    printf("Socket created with id= %s \n",serversock);
    ;

//--------------------------------
    memset(&servaddr,'\0',sizeof(servaddr));
//-------BIND------------------------------------------
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl("127.0.0.1"); 
	servaddr.sin_port = htons(servPort); 
//int bind (int sockfd, struct sockaddr *myaddr, int addrlen)
    if ((bind(serversock, (struct sockaddr_in *) &servaddr, sizeof(servaddr))) < 0) { 
		printf("DieWithError bind() failed...\n"); 
		exit(0); 
	} 
	printf("Socket successfully binded to port %d.\n",servPort); 
//-------CONNECT---------------------------------------
    if(listen(serversock,MAXPENDING)<0){
        printf("DieWithError listen() failed....\n");
        exit(0);
        }
    printf("Listening......\n");
    //------ACCEPT------
    if(newSocket = accept(serversock,(struct servaddr_in *)&newSocket,&addr_size)<0)
        {
            printf("DieWithError accept() failed.\n");    /* code */
            exit(0);
        }
    strcpy(buffer,"Hello anybody...");
    send(newSocket,buffer,strlen(buffer),0);
    printf("Closing the connection. \n");   
    close(serversock);
    return 0; 
        // printf("")
    // for(;;){
    //     bzero(maxBuffer,MAX);
    //     //------read----------
    //     read(sockfd,maxBuffer,sizeof(maxBuffer));
    //     printf("Message from Client %s\t :\n",maxBuffer);
    //     bzero(maxBuffer,MAX);
    //     n=0;
    //     while((maxBuffer[n++]=getchar()) != '\n'); //----copy server message in the buffer
    //     write(sockfd,maxBuffer,sizeof(maxBuffer)); //----send that buffer to client
   	// 	// if msg contains "Exit" then server exit and chat ended. 
	// 	if (strncmp("exit", maxBuffer, 4) == 0) { 
	// 		printf("Server Exit...\n"); 
	// 		break; 
	// 	} 
    // }
    // close(sockfd); //close the socket
    // return 0;

}