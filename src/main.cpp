#include <iostream>
#include <string>

#include "keyvalue.hpp"
#include "request.hpp"


int main(int argc, char *argv[], const char* env[]) {
  std::cout << "Content-Type: text/html" << std::endl << std::endl;
  std::cout << "Hello c++ cgi" << std::endl;

  List::KeyValueList request = Request::parse_request(env);

  std::cout << List::find(&request, "MAIL") << std::endl;
  return 0;
}

