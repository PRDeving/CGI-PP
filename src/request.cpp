#include "request.hpp"

List::KeyValueList Request::parse_request(const char* env[]) {
  List::KeyValueList list;
  int c = 0;
  while ((char*)env[c]) {
    #ifdef VERBOSE
      std::cout << "Parsing " << env[c] << std::endl;
    #endif
    List::add(&list, List::split_keyvalue(std::string((const char*)env[c]), '='));
    c++;
  }
  return list;
}

List::KeyValueList Request::parse_data(std::string data) {
  std::vector<std::string> d = List::split(data, '&');
  List::KeyValueList kvl;

  for(std::vector<std::string>::iterator it = d.begin(); it != d.end(); ++it) {
    List::add(&kvl, List::split_keyvalue(*it, '='));
  }

  return kvl;
}
