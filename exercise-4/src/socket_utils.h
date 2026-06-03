#pragma once

#include <netinet/in.h>
#include <string>

void check_error(bool test, const std::string& error_message);
int create_socket();
sockaddr_in create_address(const std::string& server_ip, int port);
sockaddr_in create_server_address(int port);
