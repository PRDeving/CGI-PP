#include "request.hpp"

List::KeyValueList Request::parse_request(const char* env[]) {
  List::KeyValueList list;
  int c = 0;
  while ((char*)env[c]) {
    #ifdef VERBOSE
      std::cout << "Parsing " << env[c] << std::endl;
    #endif
    List::add(&list, List::split(std::string((const char*)env[c]), '='));
    c++;
  }
  return list;
}
