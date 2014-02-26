#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include "NetworkServices.h"
#include <ws2tcpip.h>
#include <map>

using namespace std;
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN512
#define DEFAULT_PORT "6881"

