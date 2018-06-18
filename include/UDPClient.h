//
// Created by danyal on 19.06.18.
//

#ifndef PROTEITESTTASK_UDPCLIENT_H
#define PROTEITESTTASK_UDPCLIENT_H

#include <netinet/in.h>
#include <string>

class UDPClient {
public:
    UDPClient(int port);
    ~UDPClient();
    void send(const std::string& msg);
    std::string recv();

private:
    int _sock;
    struct sockaddr_in _addr;
};


#endif //PROTEITESTTASK_UDPCLIENT_H
