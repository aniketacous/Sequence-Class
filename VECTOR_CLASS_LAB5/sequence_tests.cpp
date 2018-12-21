#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sequence.h"
#include <iostream>




using namespace csis3700;
using namespace std;

TEST_CASE("constructor used should be zero" ," sequence")
{
  sequence s;
  REQUIRE(s.size()==0);
}
TEST_CASE("add function must add the value to the sequence", "sequence")
{
 sequence s;
 s.add(4);
 s.add(5);
 s.add(6);
 s.add(7);
 s.add(8);
 s.add(9);
 REQUIRE(s.size() == 6);
 REQUIRE(s.at(0) == 4);
}
TEST_CASE("at function will give the correct position", "sequence")
{
 sequence s;
 s.add(1);
 s.add(2);
 s.add(3);
 REQUIRE(s.at(0) == 1);
 REQUIRE(s.at(1) == 2);
 REQUIRE(s.at(2) == 3);
}
TEST_CASE("Insert function works properly","sequence")
{
 sequence s;
 s.add(1);
 s.add(2);
 s.add(3);
 s.add(4);
 REQUIRE(s.size() == 4);
 s.insert(3,5);
 REQUIRE(s.at(3)  == 5);
 REQUIRE(s.size() == 5);
 REQUIRE(s.at(0)  == 1);
 REQUIRE(s.at(4)  == 4);
}
TEST_CASE("Remove funtion works perfectly", "sequence")
{
 sequence s;
 s.add(0);
 s.add(1);
 s.add(2);
 s.add(3);
 REQUIRE(s.size() == 4);
 s.remove(2);
 REQUIRE(s.at(2)  == 3);
 REQUIRE(s.size() == 3);
}
TEST_CASE("The + operator works pretty well","sequence")
{
 sequence s1;
 s1.add(0);
 s1.add(1);
 s1.add(2);
 s1.add(3);
 s1.add(4);
 s1.add(5);
 s1.add(6);
 sequence s2;
 s2.add(7);
 s2.add(8);
 s2.add(9);
 s2.add(10);
 s2.add(11);
 s2.add(12);
 s2.add(14);
 sequence a = s1 + s2;
 REQUIRE(a.at(7) == 7);
 REQUIRE(a.at(13)== 14);
}
TEST_CASE("The += operator works pretty well","sequence")
{
 sequence s1;
 s1.add(0);
 s1.add(1);
 s1.add(2);
 s1.add(3);
 s1.add(4);
 s1.add(5);
 s1.add(6);
 sequence s2;
 s2.add(7);
 s2.add(8);
 s2.add(9);
 s2.add(10);
 s2.add(11);
 s2.add(12);
 s2.add(14);
 s1+=s2;;
 REQUIRE(s1.at(7) == 7);
 REQUIRE(s1.at(13)== 14);
}
TEST_CASE("CAPACITY can be filled from the beginning")
{
sequence s;
s.insert(0,0);
REQUIRE(s.at(0) == 0);
s.remove(0);
REQUIRE(s.size()==0);

}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


