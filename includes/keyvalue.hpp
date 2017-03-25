#ifndef H_KEYVALUE
#define H_KEYVALUE

#include <string>
#include <vector>
#include <sstream>
#include <iterator>

namespace List {
  typedef struct{
    std::string key;
    std::string value;
  } KeyValue;
  typedef std::vector<KeyValue> KeyValueList;

  void add(KeyValueList *, KeyValue);
  void add_keyvalue(KeyValueList *, std::string, std::string);
  std::string find(KeyValueList *, std::string);
  void each(KeyValueList *, void (*cb)(KeyValue));
}

#endif
