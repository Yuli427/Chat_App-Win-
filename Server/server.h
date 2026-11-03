#include "../Util/socketutil.h"
#include<windows.h>

struct AcceptedSocket{
    SOCKET acceptedSocketFD;  // Client socket
    struct sockaddr_in address; // Client address
    int error;// Error value
    bool acceptedSuccessfully;// Whether accept() was successful
    char username[50];
};

struct AcceptedSocket* acceptIncomingConnection(SOCKET serverSocketFD);

DWORD WINAPI receiveAndPrintIncomingData(LPVOID arg);

void acceptNewConnection(SOCKET serverSocketFD);

void startAcceptingIncomingConnections(SOCKET serverSocketFD);

void receiveAndPrintIncomingDataOnSeperateThread(struct AcceptedSocket*clientSocket);

int sendReceiveMessageToTheOtherClients(char*buffer,SOCKET socketFD);

void setSocketUsername(SOCKET socketFD, char* name);

char* getSocketUsername(SOCKET socketFD);