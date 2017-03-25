#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "parser.hpp"

class ParserTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

// TO_KEYVALUE
TEST_F(ParserTest,to_keyvalue){
  List::KeyValue t = Parse::to_keyvalue("test=1", '=');
  EXPECT_STREQ(t.key.c_str(), "test");
  EXPECT_STREQ(t.value.c_str(), "1");
}

TEST_F(ParserTest,to_keyvalue_delim){
  List::KeyValue t = Parse::to_keyvalue("test.1", '.');
  EXPECT_STREQ(t.key.c_str(), "test");
  EXPECT_STREQ(t.value.c_str(), "1");
}

TEST_F(ParserTest,to_keyvalue_empty){
  List::KeyValue t = Parse::to_keyvalue("", '=');
  EXPECT_STREQ(t.key.c_str(), "");
  EXPECT_STREQ(t.value.c_str(), "");
}

TEST_F(ParserTest,to_keyvalue_numbers){
  List::KeyValue t = Parse::to_keyvalue("123:456", ':');
  EXPECT_STREQ(t.key.c_str(), "123");
  EXPECT_STREQ(t.value.c_str(), "456");
}

TEST_F(ParserTest,to_keyvalue_several_delims){
  List::KeyValue t = Parse::to_keyvalue("123:456:789", ':');
  EXPECT_STREQ(t.key.c_str(), "123");
  EXPECT_STREQ(t.value.c_str(), "456:789");
}


// TO_KEYVALUELIST
TEST_F(ParserTest,to_keyvaluelist){
  List::KeyValueList t = Parse::to_keyvaluelist("test=1&lol=2", '&', '=');
  EXPECT_STREQ(t[0].key.c_str(), "test");
  EXPECT_STREQ(t[0].value.c_str(), "1");
  EXPECT_STREQ(t[1].key.c_str(), "lol");
  EXPECT_STREQ(t[1].value.c_str(), "2");
  EXPECT_EQ(t.size(), 2);
}

TEST_F(ParserTest,to_keyvaluelist_corrupted){
  List::KeyValueList t = Parse::to_keyvaluelist("test=&lol=2", '&', '=');
  EXPECT_STREQ(t[0].key.c_str(), "lol");
  EXPECT_STREQ(t[0].value.c_str(), "2");
  EXPECT_EQ(t.size(), 1);
}

TEST_F(ParserTest,to_keyvaluelist_uncompleted){
  List::KeyValueList t = Parse::to_keyvaluelist("test=923&12&lol=2", '&', '=');
  EXPECT_STREQ(t[0].key.c_str(), "test");
  EXPECT_STREQ(t[0].value.c_str(), "923");
  EXPECT_STREQ(t[1].key.c_str(), "lol");
  EXPECT_STREQ(t[1].value.c_str(), "2");
  EXPECT_EQ(t.size(), 2);
}

TEST_F(ParserTest,to_keyvaluelist_several_delims){
  List::KeyValueList t = Parse::to_keyvaluelist("test=923=12&lol=2", '&', '=');
  EXPECT_STREQ(t[0].key.c_str(), "test");
  EXPECT_STREQ(t[0].value.c_str(), "923=12");
  EXPECT_STREQ(t[1].key.c_str(), "lol");
  EXPECT_STREQ(t[1].value.c_str(), "2");
  EXPECT_EQ(t.size(), 2);
}


// TO_CHUNKS
TEST_F(ParserTest,to_chunks){
  std::vector<std::string> t = Parse::to_chunks("a,aa,aaa", ',');
  EXPECT_STREQ(t[0].c_str(), "a");
  EXPECT_STREQ(t[1].c_str(), "aa");
  EXPECT_STREQ(t[2].c_str(), "aaa");
  EXPECT_EQ(t.size(), 3);
}

TEST_F(ParserTest,to_chunks_corrupted){
  std::vector<std::string> t = Parse::to_chunks("a,,,aa,,w,,,,aaa", ',');
  EXPECT_STREQ(t[0].c_str(), "a");
  EXPECT_STREQ(t[1].c_str(), "aa");
  EXPECT_STREQ(t[2].c_str(), "w");
  EXPECT_STREQ(t[3].c_str(), "aaa");
  EXPECT_EQ(t.size(), 4);
}
