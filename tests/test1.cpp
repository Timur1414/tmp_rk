#include <proxy.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>


TEST(tests, test1) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    SchoolGirl* girl = new SchoolGirl();
    girl->setName("A");
    Proxy* proxy = new Proxy(girl);
    proxy->GiveDolls();
    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "A: give you a doll\n");
}

TEST(tests, test2) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    SchoolGirl* girl = new SchoolGirl();
    girl->setName("jiaojiao");
    Proxy* proxy = new Proxy(girl);
    proxy->GiveFlowers();
    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "A: give you you flowers\n");
}

TEST(tests, test3) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    SchoolGirl* girl = new SchoolGirl();
    girl->setName("jiaojiao");
    Proxy* proxy = new Proxy(girl);
    proxy->GiveDolls();
    proxy->GiveFlowers();
    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "A: give you a doll\nA: give you you flowers\n");
}
