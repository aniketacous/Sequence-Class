#include "sequence.h"
#include "catch.hpp"
#include <ostream>
#include <iostream>
#include <math.h>
#include <string>
#include <assert.h>

using namespace std;
namespace csis3700
{
     std::size_t sequence::size() const
     {
      return used;
     }
      sequence::value_type sequence::at(std::size_t i) const
     {
          assert(i<size());
          return items[i];
     }

     void sequence::add(const value_type& value)
     {
       assert(size()<CAPACITY);
       items[used] = value;
       used++;  
     }
     void sequence::insert(std::size_t index, const value_type& value)
     {
         assert(index <=size() && size() < CAPACITY);
         if ( index == size())
         {
		add(value);
	    }
	    else
	    {
      
          for(int i=int(size()-1); i >= int(index); i--)
          {
               items[i+1]=items[i];
          }
               items[index]=value;
               used++;
          }           
     }
     void sequence::remove(std::size_t index)
     {
          assert(index<size());
          for(int i=index; i<=used; i++)
          {
               items[i]=items[i+1];
          }
          used--;
     }
     sequence operator +(const sequence& s1, const sequence& s2) 
     {
         assert(s1.size() + s2.size() <= sequence::CAPACITY);
         sequence a;
         for(int i=0; i < int(s1.size()); i++)
         {
             //s1.at(i);
            a.add(s1.at(i));
         }
         for(int i=0; i < int(s2.size()); i++)
         { 
            //s2.at(i);
           a.add(s2.at(i));
         }
          return a;   
      }
    void sequence::operator +=(const sequence& other) 
     {
         assert(size() + other.size() <= sequence::CAPACITY);
         for(int i=0; i < int(other.size()); i++)
          {
             //other.at(i);
            add(other.at(i));
          }
         
     }
     void demo()
     {
       using namespace std;
       sequence s1;
       s1.add(5);
       s1.add(9);
       s1.add(2);
       s1.insert(1,15);
       s1.remove(0);
       cout << s1.at(0) << endl;
       cout << s1.size() << endl;
       s1.insert(0,3);
       s1.insert(0,22);
       for (int i =0; i < int(s1.size()); i++)
       {
	  cout << s1.at(i) << " ";
       }
       cout << " " << endl;
       sequence s2;
       s2.add(7);
       s2.add(5);
       sequence s3 = s1 + s2;
       for (int i =0; i < int(s3.size()); i++)
       {
	  cout << s3.at(i) << " ";
       }
       cout << " " <<endl;
       sequence s4;
       s4.add(1);
       s4 += s2;
       for (int i =0; i < int(s4.size()); i++)
       {
	  cout << s4.at(i) << " ";
       }
       cout << " " << endl;
      }
     





}
