#include "../Util/socketutil.h"
#include "client.h"
#include <stdbool.h>



int main(){

    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Winsock initialization failed.\n");
        return 1;
    }

    // Create an IPv4 TCP socket
    SOCKET socketFD=createTCPIpv4Socket();
    
    //create the server address using localhost and port 2000
    struct sockaddr_in* address= createIPv4Address("127.0.0.1",2000);
    
    // Connect the client socket to the server
    int result = connect(socketFD,(struct sockaddr*)address,sizeof(*address));
    if(result==0){
        printf("connection was successful.\n");
    }

    //start a seperate thread to listen for message from the server
    startListeningMessagesOnNewThread(socketFD);
    
    //create a buffer for store final message
    char buffer[1024];
    
    // store the user's message input
    char line[512];
    printf("type and we will send..\n");
    
    // store the user's name
    char name[50];
    printf("Please enter your name: ");
    
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    //send name
    send(socketFD,name,strlen(name),0);
  
    while(true){
       
        //read message from user
       fgets(line,sizeof(line),stdin); 

        //remove new line character
       line[strcspn(line, "\n")] = '\0';

        //combine username and message
       sprintf(buffer,"%s:%s",name,line);
       
        if(strcmp(line,"exit")==0){ 
            
            break;
        }
        int amountWasSent=send(socketFD,buffer,strlen(buffer),0);
       
    
}
   closesocket(socketFD);
   WSACleanup();
   return 0;
}

