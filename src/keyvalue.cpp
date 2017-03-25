#include "keyvalue.hpp"

void List::add(List::KeyValueList *list, List::KeyValue kv) {
  if (!kv.key.empty() && !kv.value.empty()) list -> push_back(kv);
}

void List::add_keyvalue(List::KeyValueList *list, std::string key, std::string val) {
  List::KeyValue kv;
  kv.key = key;
  kv.value = val;
  List::add(list, kv);
}

std::string List::find(List::KeyValueList *list, std::string key) {
  List::KeyValue kv;
  for(std::vector<List::KeyValue>::iterator it = list -> begin(); it != list -> end(); ++it) {
    kv = *it;
    if (kv.key == key) return kv.value;
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
