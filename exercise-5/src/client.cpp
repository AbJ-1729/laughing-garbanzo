#include "client.h"
#include "net/chat-sockets.h"
#include "utils.h"

#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

namespace tt::chat::client {

Client::Client(const std::string &server_ip, int port) : sock_(-1) {
  server_address_ = net::create_address(port);
  auto err_code = inet_pton(AF_INET, server_ip.c_str(), &server_address_.sin_addr);
  tt::chat::check_error(err_code <= 0, "Invalid address/ Address not supported\n");
}

Client::~Client() {
  if (sock_ >= 0) close(sock_);
}

void Client::connect_to_server() {
  sock_ = net::create_socket();
  auto err_code = connect(sock_, (sockaddr *)&server_address_, sizeof(server_address_));
  tt::chat::check_error(err_code < 0, "Connection Failed.\n");
}

void Client::send_and_receive_message(const std::string &message) {
  const int kBufferSize = 1024;
  char recv_buffer[kBufferSize] = {0};

  send(sock_, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";

  ssize_t read_size = read(sock_, recv_buffer, kBufferSize);
  tt::chat::check_error(read_size < 0, "Read error.\n");
  if (read_size > 0) {
    std::cout << "Received: " << recv_buffer << "\n";
  } else if (read_size == 0) {
    std::cout << "Server closed connection.\n";
  }
}

std::string Client::read_args(int argc, char *argv[]) {
  std::string message = "Hello from client";
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " <message>\n";
    exit(EXIT_FAILURE);
  }
  if (argc > 1) {
    message = argv[1];
  }
  return message;
}

} // namespace tt::chat::client
