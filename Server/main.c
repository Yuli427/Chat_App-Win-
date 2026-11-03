#include "../Util/socketutil.h"
#include"server.h"




int main()
{   
    // Initialize Winsock
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Winsock initialization failed.\n");
        return 1;
    }

    char serverIP[50];

    printf("Please enter your server IP: ");
    fgets(serverIP,sizeof(serverIP),stdin);
    serverIP[strcspn(serverIP, "\n")] = '\0';

    // Create an IPv4 TCP socket
    SOCKET serverSocketFD= createTCPIpv4Socket();
    struct sockaddr_in *serverAddress=createIPv4Address(serverIP,2000);
    
    // Bind the socket to the server address and port
    int result=bind(serverSocketFD,(struct sockaddr*)serverAddress,sizeof(*serverAddress));

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
    
    shutdown(serverSocketFD, SD_BOTH);
    closesocket(serverSocketFD);
    WSACleanup();

 
    return 0;
}

