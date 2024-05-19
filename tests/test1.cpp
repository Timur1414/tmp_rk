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
    girl->setName("A");
    Proxy* proxy = new Proxy(girl);
    proxy->GiveFlowers();
    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "A: give you flowers\n");
}

TEST(tests, test3) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    SchoolGirl* girl = new SchoolGirl();
    girl->setName("B");
    Proxy* proxy = new Proxy(girl);
    proxy->GiveDolls();
    proxy->GiveFlowers();
    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "B: give you a doll\nB: give you flowers\n");
}
