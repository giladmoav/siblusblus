#ifndef __SERVER_H__
#define __SERVER_H__
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <stdexcept>

#pragma comment(lib, "ws2_32.lib")

constexpr char SOCKET_ERROR_MSG[] = "Socket error";
constexpr char PORT[] = "13337";
const std::string EMPTY_STR;
const std::string PING = "PING";
const std::string PONG = "PONG";
const std::string UNKNOWN_COMMAND = "Unkown command";

namespace server {

void runServer();

class SocketError : public std::runtime_error {
  public:
    SocketError();
};

class SocketResource {
  public:
    explicit SocketResource(const char* port);
    ~SocketResource();

    SOCKET accept_client();

  private:
    SOCKET m_socket;
};

} // namespace server

#endif // !__SERVER_H__
