//
// Created by danyal on 19.06.18.
//

#ifndef PROTEITESTTASK_HELPER_H
#define PROTEITESTTASK_HELPER_H

#include <UDPClient.h>
#include <TCPClient.h>
#include <memory>

template<typename... Ts>
decltype(auto) makeClient(std::string_view type, Ts&& ... args)
{
   std::unique_ptr<Client> client;
   if (type == "UDP")
      client.reset(new UDPClient(3426, std::forward<Ts>(args)...));
   else if (type == "TCP")
      client.reset(new TCPClient(3425, std::forward<Ts>(args)...));

   return client;
}

#endif //PROTEITESTTASK_HELPER_H
