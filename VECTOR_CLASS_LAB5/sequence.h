#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<cstdlib>
#include<ostream>
#include<assert.h>


namespace csis3700
{

class sequence 
{
   
   public:
   typedef int value_type;
   typedef std::size_t size_type;
   
   static const size_type CAPACITY=100;
   sequence()  
   { 
   used = 0;
   }
   std::size_t size() const;
   value_type at(std::size_t i) const;
   void add(const value_type& value);
   void insert(std::size_t index, const value_type& value);
   void remove(std::size_t index);
   void operator +=(const sequence& other);
   
   
   
   private:
   value_type items[CAPACITY];
   std::size_t used;

};
void demo();
sequence operator +(const sequence& s1, const sequence& s2);



}


#endif // SEQUENCE_H
