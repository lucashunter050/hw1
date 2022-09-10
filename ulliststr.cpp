#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// push_back()
// runs in O(1)

// this implementation adds to the first available space on the tail_ item
void ULListStr::push_back(const std::string& val) {
  if (this->empty()) {
    // initialize the list
    Item* temp = new Item();
    head_ = temp;
    tail_ = temp;
    temp = nullptr;

    // put string in list
    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;

  } 
  else if (tail_->last == ARRSIZE) {
    // case where there's no room in the last item
    // create new item and append to list
    Item* temp = new Item();
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
    temp->next = nullptr;
    temp = nullptr;

    // put the string in the array
    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;

  } 
  else {
    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;
  }
}

void ULListStr::push_front(const std::string& val) {
  if (this->empty()) {
    // initialize the list
    // std::cerr << "empty list, pushing front " << val << std::endl;
    Item* temp = new Item();
    head_ = temp;
    tail_ = temp;
    temp = nullptr;
    
    // add to first slot
    head_->val[head_->first] = val;
    ++head_->last;
    ++size_;
  } 
  else if (!(head_->first) && (head_->last > 0)) {
    // triggers when head item has an item in its first position
    // make a new empty item the head of the list
    // std::cerr << "full node, pushing front " << val << std::endl;
    Item* temp = new Item();
    head_->prev = temp;
    temp->next = head_;
    head_ = temp;
    temp = nullptr;

    // put val in this item at the last index of its array
    // and update last/first
    head_->val[ARRSIZE - 1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
    ++size_;
  } 
  else {
    // trivial case - put val in the first available index of head item
    // std::cerr << "normal case, pushing front " << val << std::endl;
    head_->val[head_->first-1] = val;
    --head_->first;
    ++size_;
  }
}

// pop_back method
// runs in O(1)
void ULListStr::pop_back() {
  std::string err_messg = "invalid pop_back(), empty list\n";
  if (this->empty()) {
    throw std::invalid_argument(err_messg);
  } 

  // remove the string
  --tail_->last;
  --size_;

  // see if this made the tail_ item empty
  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    if (tail_->prev) {
      tail_->prev->next = nullptr;
    }
    
    tail_ = tail_->prev;
    delete temp;
    temp = nullptr;
  }

  // if the previous deletion deleted the last item in the list,
  // head_ will be a dangling pointer causing issues -- let's fix that
  if (size_ == 0) {
    head_ = nullptr;
  } 
  
}

// pop_front method
// runs in O(1)
void ULListStr::pop_front() {
  std::string err_messg = "invalid pop_front(), empty list\n";
  if (this->empty()) {
    throw std::invalid_argument(err_messg);
  } 

  // remove the string
  ++head_->first;
  --size_;

  // see if this made _head empty
  if (head_->first == head_->last) {
    Item* temp = head_;
    if (head_->next) {
      head_->next->prev = nullptr;
    }
    head_ = head_->next;
    delete temp;
  }

  // if the previous deletion deleted the last item in the list,
  // tail_ will be a dangling pointer causing issues -- let's fix that
  if (size_ == 0) {
    tail_ = nullptr;
  }
}

// back method
// runs in O(1)
std::string const & ULListStr::back() const 
{
  return tail_->val[tail_->last - 1];
}

// front method
// runs in O(1)
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}


// getValAtLoc method
// runs in O(n)
std::string* ULListStr::getValAtLoc(size_t loc) const 
{
  
  std::string err_messg = "item not in range [first, last)\n";
  if (loc >= size_) {
    throw std::invalid_argument(err_messg);
  }
  Item* curr_item = head_;

  // step 1: find correct item, point at it, and decrement 
  // the index appropriately
  while (loc >= (ARRSIZE - curr_item->first)) {
    loc -= (ARRSIZE - curr_item->first);
    curr_item = curr_item->next;
    // loc += curr_item->first;
  }

  // step 2: grab the appropriate item and return a pointer to it
  return &curr_item->val[loc + curr_item->first];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
} 

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
