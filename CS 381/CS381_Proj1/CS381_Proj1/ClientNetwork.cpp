#include "StdAfx.h"
#include "ClientNetwork.h"


ClientNetwork::ClientNetwork(void)
{
	WSADATA wsaData;

	ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result=NULL,
					*ptr=NULL,
					hints;

	iResult= WSAStartup(MAKEWORD(2,2), &wsaData);
	if(iResult !=0){
		printf("WSAStartup failed with error: &d\n",iResult);
		exit(1);
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family= AF_UNSPEC;
	hints.ai_socktype= SOCK_STREAM;
	hints.ai_protocol= IPPROTO_TCP;
	iResult= getaddrinfo("127.0.1",DEFAULT_PORT, &hints, &result);

	if(iResult !=0)
	{
		printf("getaddrinfo failed with error: &d \n",iResult);
		WSACleanup();
		exit(1);
	}
	u_long iMode=1;
	iResult= ioctlsocket(ConnectSocket, FIONBIO, &iMode);
	if( iResult == SOCKET_ERROR)
	{
		printf("ioctlsocket failed with error: &d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		exit(1);
	}

}


ClientNetwork::~ClientNetwork(void)
{
}
