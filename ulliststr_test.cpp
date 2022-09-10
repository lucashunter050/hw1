/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;


int main(int argc, char* argv[])
{
  ULListStr* list1 = new ULListStr();

  // calling push_front on the empty list1
  list1->push_front("1");

  // full node case, will put 2 in end of new node
  list1->push_front("2");

  // default case, will put pushed value in available slots 
  list1->push_front("3");
  list1->push_front("4");
  list1->push_front("5");
  list1->push_front("6");
  list1->push_front("7");
  list1->push_front("8");
  list1->push_front("9");
  list1->push_front("10");
  list1->push_front("11");

  std::cout << "The list now has " << list1->size() << " strings in 2 items" << std::endl;
  std::cout << "looping through the list:" << std::endl;
  for (unsigned long i = 0; i < list1->size(); ++i) {
    std::cout << "position: " << i << "    value: " << list1->get(i) << std::endl;
  }
  std::cout << std::endl;
  std::cout << "testing front() and back()" << std::endl;
  std::cout << "front: " << list1->front() << "    back: " << list1->back() << std::endl;

  std::cout << "clearing the list: " << std::endl;
  list1->clear();

  std::cout << "  " << list1->size() << " strings in list" << std::endl << std::endl;

  std::cout << "calling push_back() 11 times:" << std::endl << std::endl;

  // calling push_back on empty list1
  list1->push_back("push-1");

  // default case--will fill item created on push-1 line
  list1->push_back("push-2");
  list1->push_back("push-3");
  list1->push_back("push-4");
  list1->push_back("push-5");
  list1->push_back("push-6");
  list1->push_back("push-7");
  list1->push_back("push-8");
  list1->push_back("push-9");
  list1->push_back("push-10");

  // full item case--will create new item and put push-11 in the first slot
  
  list1->push_back("push-11");

  // see the contents of the list
  std::cout << "contents of list after calling push_back() 11 times: " << std::endl;
  for (size_t i = 0; i < list1->size(); ++i) {
    std::cout << "position: " << i << "   value: " << list1->get(i) << std::endl;
  }

  // calling get on an index outside of our value range
  std::cout << std::endl;
  std::cout << "attempting to call get on value out of range" << std::endl;

  try {
    std::cout << "value at 150: " << list1->get(150);
  } 
  catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }

  // test pop_back() on an item with only 1 string in it
  std::cout << "calling pop_back with one string in tail_" << std::endl;
  std::cout << "calling pop_back() once" << std::endl;
  std::cout << "strings before pop_back = " << list1->size() << std::endl;
  std::cout << "last string before pop_back = " << list1->back() << std::endl;
  list1->pop_back();
  std::cout << "strings after pop_back = " << list1->size() << std::endl;
  std::cout << "last string after pop_back = " << list1->back() << std::endl;
  std::cout << std::endl;

  // testing pop_back when it shouldn't delete the item
  std::cout << "calling pop_back() on full item" << std::endl;
  std::cout << "calling pop_back() once" << std::endl;
  std::cout << "strings before pop_back = " << list1->size() << std::endl;
  std::cout << "last string before pop_back = " << list1->back() << std::endl;
  list1->pop_back();
  std::cout << "strings after pop_back = " << list1->size() << std::endl;
  std::cout << "last string after pop_back = " << list1->back() << std::endl << std::endl;
  std::cout << std::endl;

  // testing pop_front when it shouldn't delete the item
  std::cout << "calling pop_front() once" << std::endl;
  std::cout << "strings before pop_front() = " << list1->size() << std::endl;
  std::cout << "first string before pop_front() = " << list1->front() << std::endl;
  list1->pop_front();
  std::cout << "strings after pop_front() = " << list1->size() << std::endl;
  std::cout << "first string after pop_front() = " << list1->front() << std::endl << std::endl;

  // calling pop_front() enough times to delete all items
  std::cout << "calling pop_front() " << list1->size() << " times" << std::endl;
  std::cout << "strings before pop_front = " << list1->size() << std::endl;
  std::cout << "first string before pop_front = " << list1->front() << std::endl;

  unsigned long deletions = 0;

  while (!list1->empty()) {
    list1->pop_front();
    ++deletions;
  }
  
  std::cout << "strings remaining after: " << list1->size();
  std::cout << ", deleted " << deletions << " values" << std::endl;
  std::cout << std::endl;

  if (list1->empty()) {
    std::cout << "list1 is empty" << std::endl;
  }
  // attempting to pop_back on empty list - should throw exception
  std::cout << "attemping pop_back() on empty list" << std::endl;
  try {
    list1->pop_back();
  } 
  catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }

  // attempting to pop_front on empty list - should throw exception
  std::cout << "attempting pop_front() on empty list" << std::endl;
  try {
    list1->pop_front();
  } 
  catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }

  // to be thorough, let's make sure pop_back() can also delete the whole list
  list1->push_back("push-1");
  list1->push_back("push-2");
  list1->push_back("push-3");
  list1->push_back("push-4");
  list1->push_back("push-5");
  list1->push_back("push-6");
  list1->push_back("push-7");
  list1->push_back("push-8");
  list1->push_back("push-9");
  list1->push_back("push-10");  
  list1->push_back("push-11");
  list1->push_front("i");
  list1->push_front("h");
  list1->push_front("g");
  list1->push_front("f");
  list1->push_front("e");
  list1->push_front("d");
  list1->push_front("c");
  list1->push_front("b");
  list1->push_front("a");

  // list before deletion
  for (unsigned long i = 0; i < list1->size(); ++i) {
    std::cout << "position: " << i << "    value: " << list1->get(i) << std::endl;
  }

  // delete list
  while (!list1->empty()) {
    list1->pop_back();
  }

  if (list1->empty()) {
    std::cout << "pop_back() deleted the whole list" << std::endl;
  }

  delete list1;
  list1 = nullptr;

  return 0;
}