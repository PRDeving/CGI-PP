#include "request.hpp"

List::KeyValueList Request::parse_request(const char* env[]) {
  List::KeyValueList list;
  int c = 0;
  while ((char*)env[c]) {
    #ifdef VERBOSE
      std::cout << "Parsing " << env[c] << std::endl;
    #endif
    List::add(&list, Parse::to_keyvalue(std::string(env[c]), '='));
    c++;
  }
  return list;
}
