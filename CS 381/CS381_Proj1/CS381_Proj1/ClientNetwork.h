#pragma once
#include<WinSock2.h>
#include<Windows.h>
#include "NetworkServices.h"
#include <WS2tcpip.h>
#include <stdio.h>


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "6881"
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class ClientNetwork
{
public:
	int iResult;

	SOCKET ConnectSocket;

	ClientNetwork(void);
	~ClientNetwork(void);


};

