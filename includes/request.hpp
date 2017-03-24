#ifndef H_REQUEST
#define H_REQUEST

#ifdef VERBOSE
  #include <iostream>
#endif

#include "keyvalue.hpp"

namespace Request {
  List::KeyValueList parse_request(const char*[]);
  List::KeyValueList parse_data(std::string);
}

#endif
