//
// Created by danyal on 16.06.18.
//
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <regex>
#include <iostream>
#include "TCPServer.h"

#include <cstdio>
#include <TCPSession.h>

#include "TCPServer.h"
#include "TCPSession.h"

TCPServer::TCPServer(int port) : Server{port}{
    struct sockaddr_in addr;
    listen(_listener, 1);
}

std::shared_ptr<TCPSession> TCPServer::accept() {
    int sock;
    sock = ::accept(_listener, nullptr, nullptr);
    if (sock < 0) {
        perror("accept");
        exit(3);
    }

//    _sessions.push_back((sock));
    return std::make_shared<TCPSession>(sock);//_sessions.back();
}
TCPServer::~TCPServer()
{
//    for(auto&& it : _sessions)
//        it.reset();

}


