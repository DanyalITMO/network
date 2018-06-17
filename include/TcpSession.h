//
// Created by danyal on 16.06.18.
//

#ifndef SERVER_TCPSESSION_H
#define SERVER_TCPSESSION_H

#include <string>

class TcpSession {
public:
    explicit TcpSession(int);
    std::string recv();
    void send(std::string);

    ~TcpSession();
private:
    const int _buf_size{1024};
    int _sock;
};


#endif
