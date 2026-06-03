#include "server.h"
#include "net/chat-sockets.h"
#include "utils.h"

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

namespace tt::chat::server {

Server::Server(int port) : port_(port) {}

Server::~Server() {}

int Server::create_server_socket() {
  int sock = net::create_socket();
  const int kSocketOptions = 1;
  auto err_code = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &kSocketOptions, sizeof(kSocketOptions));
  tt::chat::check_error(err_code < 0, "setsockopt() error\n");
  return sock;
}

sockaddr_in Server::create_server_address() {
  sockaddr_in address = net::create_address(port_);
  address.sin_addr.s_addr = INADDR_ANY;
  return address;
}

void Server::bind_and_listen(int sock, sockaddr_in &address) {
  auto err_code = bind(sock, (sockaddr *)&address, sizeof(address));
  tt::chat::check_error(err_code < 0, "bind failed\n");
  err_code = listen(sock, 3);
  tt::chat::check_error(err_code < 0, "listen failed\n");
}

void Server::handle_connections(int sock, sockaddr_in &address) {
  socklen_t address_size = sizeof(address);
  while (true) {
    int accepted_socket = accept(sock, (sockaddr *)&address, &address_size);
    tt::chat::check_error(accepted_socket < 0, "Accept error n ");

    const int kBufferSize = 1024;
    char buffer[kBufferSize] = {0};
    ssize_t read_size = read(accepted_socket, buffer, kBufferSize);
    tt::chat::check_error(read_size < 0, "Read error on client socket");
    if (read_size > 0) {
      std::cout << "Received:" << buffer << "\n";
      send(accepted_socket, buffer, read_size, 0);
      std::cout << "Echo message sent\n";
    } else if (read_size == 0) {
      std::cout << "Client disconnected.\n";
    } else {
      std::cerr << "Read error on client socket " << accepted_socket << "\n";
    }
    close(accepted_socket);
  }
}

} // namespace tt::chat::server
