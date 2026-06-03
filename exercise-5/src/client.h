#pragma once

#include <netinet/in.h>
#include <string>

namespace tt::chat::client {

class Client {
public:
  Client(const std::string &server_ip, int port);
  ~Client();

  void connect_to_server();
  void send_and_receive_message(const std::string &message);
  static std::string read_args(int argc, char *argv[]);

private:
  int sock_;
  sockaddr_in server_address_;
};

} // namespace tt::chat::client
