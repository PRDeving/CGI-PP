#include "parser.hpp"

List::KeyValue Parse::to_keyvalue(std::string s, char delim) {
  List::KeyValue ans;
  if (s.find(delim) == std::string::npos) return ans;
  std::stringstream ss;
  ss.str(s);

  std::string item;
  std::getline(ss, item, delim);
  ans.key = item;
  std::getline(ss, item);
  ans.value = item;

  return ans;
}

std::vector<std::string> Parse::to_chunks(std::string s, char delim) {
  std::vector<std::string> ret;

  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    ret.push_back(item);
  }
  return ret;
}

List::KeyValueList Parse::to_keyvaluelist(std::string s, char cdelim, char vdelim) {
  List::KeyValueList kvl;
  std::vector<std::string> ch = Parse::to_chunks(s, cdelim);
  List::KeyValue c;
  for(std::vector<std::string>::iterator it = ch.begin(); it != ch.end(); ++it) {
    c = Parse::to_keyvalue(*it, vdelim);
    if (c.key.empty() || c.value.empty()) {
    } else {
      List::add(&kvl, c);
    }
  }
  return kvl;
}
