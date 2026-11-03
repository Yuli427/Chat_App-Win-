#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <windows.h>

void startListeningMessagesOnNewThread(SOCKET fd);

DWORD WINAPI ListenAndPrint(LPVOID arg);

#endif