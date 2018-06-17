//
// Created by danyal on 17.06.18.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>

Server::Server(int port) {
    struct sockaddr_in addr;

    _listener = socket(AF_INET, SOCK_STREAM, 0);
    if (_listener < 0) {
        perror("socket");
//        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(_listener, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
//        exit(2);
    }
}

Server::~Server()
{
    close(_listener);
}