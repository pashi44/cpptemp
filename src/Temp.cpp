#include <string.h>
#include "threadplay.hpp"
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "IterOne.hpp"
#include "Itertwo.hpp"
#include "Iterthree.hpp"
using namespace std;
using namespace Iterone;
using namespace Itertwo;
using namespace threadone;
using namespace threadplay;b 

using namespace Iterthree;

int main()
{

    IterOne<string, nullptr_t> iterobj{std::string("TestString"), nullptr};

    sockaddr_in mysocket;
    memset(&mysocket, 0, sizeof(mysocket));
    mysocket.sin_family = AF_INET;
    mysocket.sin_port = htons(1296);
    mysocket.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    /* we are dealing with posix based sockets here so need not to worry about Windows
    WSAStartup and WSACleanup
    */
    auto serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0)
    {
        cout << "Socket creation failed" << endl;
        return -1;
    }
    if (bind(serverSocket, (const sockaddr *)&mysocket, sizeof(mysocket)) == -1)
    {
        cerr << "Binding failed" << endl;
        return -1;
    }

    if (listen(serverSocket, 3) == -1)
    {
        cerr << "listen failed" << endl;
        close(serverSocket);
        return -1;
    }
    cout << "Server is listening on port 1296" << endl;


    sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);

    if (clientSocket < 0) {
        cerr << "Accept failed" << endl; 
        close(serverSocket);
        return -1;
    }
    
    cout << "Client connected successfully!" << endl;
    const char* msg = "Welcome to the server!\n";
        send(clientSocket, msg, strlen(msg), 0);

    close(clientSocket);
    close(serverSocket);
    return 0;
}