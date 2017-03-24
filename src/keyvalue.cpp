#include "keyvalue.hpp"

template<typename Out>
void List::split_keyvalue(const std::string &s, char delim, Out result) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  std::getline(ss, item, delim);
  *(result) = item;
  std::getline(ss, item);
  *(result++) = item;
}

List::KeyValue List::split_keyvalue(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split_keyvalue(s, delim, std::back_inserter(elems));
  return elems;
}

template<typename Out>
void List::split(const std::string &s, char delim, Out result) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    *(result++) = item;
  }
}

std::vector<std::string> List::split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

void List::add(List::KeyValueList *list, List::KeyValue kv) {
  list -> push_back(kv);
}

void List::add_keyvalue(List::KeyValueList *list, std::string key, std::string val) {
  List::KeyValue kv;
  kv.push_back(key);
  kv.push_back(val);
  List::add(list, kv);
}

std::string List::find(List::KeyValueList *list, std::string key) {
  List::KeyValue kv;
  for(std::vector<List::KeyValue>::iterator it = list -> begin(); it != list -> end(); ++it) {
    kv = *it;
    if (kv[0] == key) return kv[1];
  }
  return "";
}

void List::each(List::KeyValueList *list, void (*cb)(List::KeyValue)) {
  List::KeyValue kv;
  for (std::vector<List::KeyValue>::iterator it = list -> begin(); it != list -> end(); ++it) {
    kv = *it;
    cb(kv);
  }
}
