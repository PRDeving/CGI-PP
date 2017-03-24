#include "router.hpp"

std::vector<Router::State> routes;

Router::State Router::find(std::string key) {
  Router::State r;
  for (std::vector<Router::State>::iterator it = routes.begin(); it != routes.end(); ++it) {
    r = *it;
    if (r.url == key) return r;
  }
  return r;
}

void Router::state(std::string state, void (*cb)(List::KeyValueList)) {
  Router::State s;
  s.url = state;
  s.cb = cb;
  routes.push_back(s);
}

void Router::evaluate(std::string path) {
  List::KeyValueList kvl;
  Router::find(path).cb(kvl);
}
