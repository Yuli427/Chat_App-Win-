#include "client.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <winsock2.h>
#include <windows.h>

// Start a new thread to listen for incoming messages from the server
void startListeningMessagesOnNewThread(SOCKET fd){
   
    

    // Create a new thread that runs ListenAndPrint()
     CreateThread(NULL,0,ListenAndPrint,(LPVOID)(uintptr_t)fd,0,NULL);
    
    
}

// Receive and print messages from the server
DWORD WINAPI ListenAndPrint(LPVOID arg)
{   

    SOCKET SocketFD=(SOCKET)(uintptr_t)arg;
    
    char buffer[1024];

    while (true)
    {   
        //Receive data from the server
        int amountReceived = recv(SocketFD, buffer, 1023, 0);

        if (amountReceived > 0)
        {   

            //add null terminator - string
            buffer[amountReceived] = 0;
            printf("%s",buffer);

            
        }

        //stop listening if the connection is closed or error occurs
        if (amountReceived <= 0)
        {   
            break;
        }
    }
    
     closesocket(SocketFD);
     return 0;
}