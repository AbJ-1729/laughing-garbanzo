#pragma once

#include <netinet/in.h>

namespace tt::chat::server {

class Server {
public:
  Server(int port);
  ~Server();

  int create_server_socket();
  sockaddr_in create_server_address();
  void bind_and_listen(int sock, sockaddr_in &address);
  void handle_connections(int sock, sockaddr_in &address);

private:
  int port_;
};

} // namespace tt::chat::server
