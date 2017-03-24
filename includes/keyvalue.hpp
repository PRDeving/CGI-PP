#ifndef H_KEYVALUE
#define H_KEYVALUE

#include <string>
#include <vector>
#include <sstream>
#include <iterator>

namespace List {
  typedef std::vector<std::string> KeyValue;
  typedef std::vector<KeyValue> KeyValueList;

  template<typename Out> void split(const std::string &, char, Out);
  template<typename Out> void split_keyvalue(const std::string &, char, Out);
  KeyValue split(const std::string &, char);
  KeyValue split_keyvalue(const std::string &, char);

  void add(KeyValueList *, KeyValue);
  void add_keyvalue(KeyValueList *, std::string, std::string);
  std::string find(KeyValueList *, std::string);
}

#endif
