#include <iostream>
#include <string>

#include "keyvalue.hpp"


List::KeyValueList parse_request(const char* env[]) {
  List::KeyValueList list;
  int c = 0;
  while ((char*)env[c]) {
    std::cout << "Parsing " << env[c] << std::endl;
    List::add(&list, List::split(std::string((const char*)env[c]), '='));
    c++;
  }
  return list;
}


int main(int argc, char *argv[], const char* env[]) {
  std::cout << "Content-Type: text/html" << std::endl << std::endl;
  std::cout << "Hello c++ cgi" << std::endl;

  List::KeyValueList request = parse_request(env);

  std::cout << List::find(&request, "MAIL") << std::endl;
  return 0;
}

