#ifndef SOCKETUTIL_SOCKETUTIL_H
#define SOCKETUTIL_SOCKETUTIL_H

#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>
#include <stdlib.h>


SOCKET createTCPIpv4Socket();
struct sockaddr_in* createIPv4Address(char *ip, int port);


#endif //SOCKETUTIL_SOCKETUTIL_H
