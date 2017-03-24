#include "router.hpp"

void err404(List::KeyValueList kvl) {
  std::cout << "404 Error" << std::endl;
}

std::vector<Router::State> routes;
Router::State notFound = {
  "/404",
  &err404
};

Router::State Router::find(std::string key) {
  Router::State r;
  for (std::vector<Router::State>::iterator it = routes.begin(); it != routes.end(); ++it) {
    r = *it;
    if (r.url == key) return r;
  }
  return notFound;
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
