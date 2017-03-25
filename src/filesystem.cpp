#include "filesystem.hpp"

std::string File::import(std::string path) {
  FILE * file = std::fopen(path.c_str(), "r");
  if (!file) {
    fclose(file);
    return "";
  }

  fseek (file , 0 , SEEK_END);
  long lSize = ftell(file);
  rewind (file);

  size_t r;
  char *buffer = (char*)malloc(sizeof(char) * lSize);
  r = fread(buffer, 1, lSize, file);
  fclose(file);

  std::string content = "";
  if (r == lSize) {
    content = std::string(buffer);
  }

  free(buffer);
  return content;
}
