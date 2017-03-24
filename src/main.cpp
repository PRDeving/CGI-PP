#include <iostream>
#include <string>

#include "keyvalue.hpp"
#include "request.hpp"


int main(int argc, char *argv[], const char* env[]) {
  std::cout << "Content-Type: text/html" << std::endl << std::endl;
  std::cout << "Hello c++ cgi" << std::endl;

  List::KeyValueList request = Request::parse_request(env);

  List::KeyValue kv;
  for(std::vector<List::KeyValue>::iterator it = request.begin(); it != request.end(); ++it) {
    kv = *it;
    std::cout << "<p>" << kv[0] << ": " << kv[1] << "</p>" << std::endl;
  }

  List::KeyValueList data = Request::parse_data(List::find(&request, "QUERY_STRING"));
  std::cout << "<h1>Data</h1>" << std::endl;
  for(std::vector<List::KeyValue>::iterator it = data.begin(); it != data.end(); ++it) {
    kv = *it;
    std::cout << "<p>" << kv[0] << ": " << kv[1] << "</p>" << std::endl;
  }

  return 0;
}

