#include <iostream>
#include <string>

#include "keyvalue.hpp"
#include "request.hpp"
#include "router.hpp"

void printList(List::KeyValue kv) {
  std::cout << "<p>" << kv[0] << ": " << kv[1] << "</p>" << std::endl;
}

void homeHandler(List::KeyValueList kvl) {
  std::cout << "<div>This is the home</div>" << std::endl;
}

void testHandler(List::KeyValueList kvl) {
  std::cout << "<div>This is the test</div>" << std::endl;
}

int main(int argc, char *argv[], const char* env[]) {
  std::cout << "Content-Type: text/html" << std::endl << std::endl;

  List::KeyValueList request = Request::parse_request(env);
  List::KeyValueList data = Request::parse_data(List::find(&request, "QUERY_STRING"));

  #ifdef VERBOSE
    std::cout << "Hello c++ cgi" << std::endl;
    std::cout << "<h1>Request</h1>" << std::endl;
    List::each(&request, &printList);
    std::cout << "<h1>Path</h1>" << std::endl
      << "<p>" << List::find(&request, "PATH_INFO") << "</p>" << std::endl;
    std::cout << "<h1>Data</h1>" << std::endl;
    List::each(&data, &printList);
  #endif

  Router::state("/home", &homeHandler);
  Router::state("/test", &testHandler);

  Router::evaluate(List::find(&request, "PATH_INFO"), data);

  return 0;
}

