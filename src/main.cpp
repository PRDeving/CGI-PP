#include <iostream>
#include <string>

#include "keyvalue.hpp"
#include "request.hpp"

void showListAsHTML(List::KeyValue kv) {
  std::cout << "<p>" << kv[0] << ": " << kv[1] << "</p>" << std::endl;
}

int main(int argc, char *argv[], const char* env[]) {
  std::cout << "Content-Type: text/html" << std::endl << std::endl;
  std::cout << "Hello c++ cgi" << std::endl;

  std::cout << "<h1>Request</h1>" << std::endl;
  List::KeyValueList request = Request::parse_request(env);
  List::each(&request, &showListAsHTML);

  std::cout << "<h1>Data</h1>" << std::endl;
  List::KeyValueList data = Request::parse_data(List::find(&request, "QUERY_STRING"));
  List::each(&data, &showListAsHTML);

  return 0;
}

