#include "server.h"
#include <iostream>
#include <ws2tcpip.h>

using server::SocketError;
using server::SocketResource;
using std::cout;
using std::endl;
using std::string;

SocketResource::SocketResource(const char* port) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
        throw SocketError();
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the local address and port to be used by the server
    struct addrinfo* result;
    if (getaddrinfo(NULL, port, &hints, &result)) {
        WSACleanup();
        throw SocketError();
    }
    m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (m_socket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        throw SocketError();
    }
    if (bind(m_socket, result->ai_addr, static_cast<int>(result->ai_addrlen)) == SOCKET_ERROR) {
        freeaddrinfo(result);
        closesocket(m_socket);
        WSACleanup();
        throw SocketError();
    }
    freeaddrinfo(result);

    if (listen(m_socket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(m_socket);
        WSACleanup();
        throw SocketError();
    }
}

SocketResource::~SocketResource() {
    int closeStatus = closesocket(m_socket);
    int cleanupStatus = WSACleanup();
}

/// accept clients for the socket resource
SOCKET SocketResource::accept_client() {
    return accept(m_socket, nullptr, nullptr);
}

SocketError::SocketError() : runtime_error(SOCKET_ERROR_MSG) {
    // intentionally empty
}

/// recieve a message from client
string recvMsg(SOCKET client) {
    // please i dont care about endianess
    // we use unsigned int and not size_t because the next recv will need to use this variable and is limited to int
    unsigned int msgLength;
    int status = recv(client, reinterpret_cast<char*>(&msgLength), sizeof(int), 0);
    if (!status) {
        return EMPTY_STR;
    }
    string msg;
    msg.resize(msgLength);
    status = recv(client, &msg[0], msgLength, 0);
    if (!status) {
        return EMPTY_STR;
    }
    return msg;
}

/// send a message from client
bool sendMsg(SOCKET client, string msg) {
    // message length including null-byte
    if (msg.size() > static_cast<unsigned int>(-1)) {
        cout << "Warning: message to send is longer then max-unsigned-int" << endl;
    }
    unsigned int msgLength = static_cast<unsigned int>(msg.size());

    int status = send(client, reinterpret_cast<char*>(&msgLength), sizeof(int), 0);
    if (status == SOCKET_ERROR) {
        cout << "There was an error sending: " << msg.c_str() << endl;
        return false;
    }
    status = send(client, msg.c_str(), msgLength, 0);
    if (status == SOCKET_ERROR) {
        cout << "There was an error sending: " << msg.c_str() << endl;
        return false;
    }
    cout << "Successfully sent: " << msg.c_str() << endl;
    return true;
}

/// run server using the port configured
void server::runServer() {
    SocketResource sock(PORT);
    cout << "Server is up..." << endl;
    while (1) {
        SOCKET client = sock.accept_client();
        cout << "Client connected!" << endl;
        string msg = recvMsg(client);
        if (msg == EMPTY_STR) {
            break;
        }
        cout << "Recieved: " << msg.c_str() << endl;
        if (msg == PING) {
            sendMsg(client, PONG);
        } else {
            sendMsg(client, UNKNOWN_COMMAND);
        }
    }
}