#include "../Util/socketutil.h"




int main()
{   
    char serverIP[50];
    size_t serverIpSize = 0;

    printf("Please enter your server IP: ");
    size_t serverIPcount=getline(&serverIP,&serverIpSize,stdin);
    serverIP[serverIPcount-1]=0;

    // Create an IPv4 TCP socket
    int serverSocketFD= createTCPIpv4Socket();
    struct sockaddr_in *serverAddress=createIPv4Address(serverIP,2000);
    
    // Bind the socket to the server address and port
    int result=bind(serverSocketFD,serverAddress,sizeof(*serverAddress));

    if(result==0){
        printf("bound successfuly!\n");
    }
    
    // put the socket into listening mode
    // The server can queue up to 10 pending connections
    int listen_result=listen(serverSocketFD,10);

    if(listen_result==0){
        printf("server is listening...\n");
    }
    else{
        printf("server is not listening..\n");
    }

    // Continuously accept and handle incoming client connections
    startAcceptingIncomingConnections(serverSocketFD);
    
    shutdown(serverSocketFD,SHUT_RDWR);
 
    return 0;
}

