#ifndef H_PARSER
#define H_PARSER

#include <string>
#include <sstream>
#include <string>
#include "keyvalue.hpp"

namespace Parse {
  List::KeyValue to_keyvalue(std::string, char);
  std::vector<std::string> to_chunks(std::string, char);
  List::KeyValueList to_keyvaluelist(std::string, char, char);
}

#endif
