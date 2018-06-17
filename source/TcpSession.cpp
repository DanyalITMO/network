//
// Created by danyal on 16.06.18.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "TcpSession.h"
#include <unistd.h>



#include <cstdlib>

TcpSession::TcpSession(int sock) : _sock{sock}
{}

std::string TcpSession::recv() {
    char _buf[_buf_size];
    auto bytes_read = ::recv(_sock, _buf, _buf_size, 0);// ret ssize t
    if(bytes_read <= 0) return "";

    std::string t(_buf);
    return t;
}

void TcpSession::send(std::string msg) {
    ::send(_sock, msg.c_str(), msg.size(), 0);
}

TcpSession::~TcpSession() {
    close(_sock);
}