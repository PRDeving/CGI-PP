#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "keyvalue.hpp"

class KeyValueTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

// KEYVALUE
TEST_F(KeyValueTest,KeyValue_default){
  List::KeyValue t;
  EXPECT_STREQ(t.key.c_str(), "");
  EXPECT_STREQ(t.value.c_str(), "");
}

TEST_F(KeyValueTest,KeyValue_set){
  List::KeyValue t;
  t.key = "key";
  t.value = "value";
  EXPECT_STREQ(t.key.c_str(), "key");
  EXPECT_STREQ(t.value.c_str(), "value");
}


// KEYVALUETEST
TEST_F(KeyValueTest,KeyValueList_default){
  List::KeyValueList t;
  EXPECT_TRUE(t.empty());
}


// ADD
TEST_F(KeyValueTest,add){
  List::KeyValueList k;
  List::KeyValue t;
  t.key = "key";
  t.value = "value";

  List::add(&k, t);
  EXPECT_FALSE(k.empty());
  EXPECT_EQ(k.size(), 1);
}

TEST_F(KeyValueTest,add_corrupted){
  List::KeyValueList k;
  List::KeyValue t;
  t.key = "";
  t.value = "value";

  List::add(&k, t);
  EXPECT_TRUE(k.empty());
}


// ADD_KEYVALUE
TEST_F(KeyValueTest,add_keyvalue){
  List::KeyValueList k;
  List::add_keyvalue(&k, "key", "value");
  EXPECT_FALSE(k.empty());
  EXPECT_EQ(k.size(), 1);
}

TEST_F(KeyValueTest,add_keyvalue_corrupted){
  List::KeyValueList k;
  List::add_keyvalue(&k, "", "value");
  EXPECT_TRUE(k.empty());
}


// FIND
TEST_F(KeyValueTest,find){
  List::KeyValueList k;
  List::add_keyvalue(&k, "key1", "1");
  List::add_keyvalue(&k, "key2", "2");
  List::add_keyvalue(&k, "key3", "3");
  std::string t = List::find(&k, "key2");

  EXPECT_FALSE(k.empty());
  EXPECT_STREQ(t.c_str(), "2");
}

TEST_F(KeyValueTest,find_none){
  List::KeyValueList k;
  List::add_keyvalue(&k, "key1", "1");
  List::add_keyvalue(&k, "key2", "2");
  List::add_keyvalue(&k, "key3", "3");
  std::string t = List::find(&k, "key");

  EXPECT_FALSE(k.empty());
  EXPECT_STREQ(t.c_str(), "");
}

TEST_F(KeyValueTest,find_multiple){
  List::KeyValueList k;
  List::add_keyvalue(&k, "key1", "1");
  List::add_keyvalue(&k, "key2", "2");
  List::add_keyvalue(&k, "key3", "3");
  List::add_keyvalue(&k, "key2", "4");
  std::string t = List::find(&k, "key2");

  EXPECT_FALSE(k.empty());
  EXPECT_STREQ(t.c_str(), "2");
}


// EACH
std::string tot = "";
void foreach(List::KeyValue kv) {
  tot += kv.key + kv.value;
}

TEST_F(KeyValueTest,each){
  List::KeyValueList k;
  List::add_keyvalue(&k, "key1", "1");
  List::add_keyvalue(&k, "key2", "2");
  List::add_keyvalue(&k, "key3", "3");
  List::each(&k, &foreach);

  EXPECT_FALSE(k.empty());
  EXPECT_STREQ(tot.c_str(), "key11key22key33");
}
