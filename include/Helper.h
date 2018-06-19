//
// Created by danyal on 19.06.18.
//

#ifndef PROTEITESTTASK_HELPER_H
#define PROTEITESTTASK_HELPER_H

#include <UDPClient.h>
#include <TCPClient.h>
#include <memory>
enum class Protocol{
   TCP,
   UDP
};

Protocol stringToProtocol(std::string_view);

inline decltype(auto) makeClient(Protocol type)
{
   std::unique_ptr<Client> client;
   if (type == Protocol::UDP)
      client.reset(new UDPClient(3426));
   else if (type == Protocol::TCP)
      client.reset(new TCPClient(3425));

   return client;
}



#endif //PROTEITESTTASK_HELPER_H
