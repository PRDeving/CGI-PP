#include "gtest/gtest.h"
#include "filesystem.hpp"

class FilesystemTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

// IMPORT
TEST_F(FilesystemTest,import){
  std::string f = File::import("file.txt");
  EXPECT_STREQ(f.substr(0,7).c_str(), "testing");
}
//
// TEST_F(FilesystemTest,import_doesnt_exists){
//   std::string f = File::import("nofile.txt");
//   EXPECT_STREQ(f.c_str(), "");
// }
//
// TEST_F(FilesystemTest,import_forbiden){
//   std::string f = File::import("/etc/sudoers");
//   EXPECT_STREQ(f.c_str(), "");
// }

TEST_F(FilesystemTest,import_characters){
  std::string f = File::import("characters.txt");
  EXPECT_STREQ(f.c_str(), "!·$%&/()=?¿¡'+`*^ç´Ç¨Ññ-_:.;,ªº|@#¢∞¬÷“”≠´‚][}{–…„\n");
}
