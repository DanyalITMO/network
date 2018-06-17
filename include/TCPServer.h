//
// Created by danyal on 16.06.18.
//

#ifndef SERVER_SOCKETWRAPPER_H
#define SERVER_SOCKETWRAPPER_H


#include <memory>
#include "string_view"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "TcpSession.h"
#include <list>


class TCPServer {
public:
    explicit TCPServer(int port);
    ~TCPServer();
    std::shared_ptr<TcpSession> accept();

private:
    std::list<std::shared_ptr<TcpSession>> _sessions;
    std::size_t _buf_size{1024};
    int _listener;
};


#endif //SERVER_SOCKETWRAPPER_H
