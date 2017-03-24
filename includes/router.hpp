#ifndef H_ROUTER
#define H_ROUTER

#include <vector>
#include <string>

#include "keyvalue.hpp"

namespace Router {
  typedef struct {
    std::string url;
    void (*cb)(List::KeyValueList);
  } State;

  void state(std::string, void (*)(List::KeyValueList));
  State find(std::string key);
  void evaluate(std::string);
}

#endif
