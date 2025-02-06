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
void ULListStr::push_back(const std::string& val)
{
  // If list is empty, initialize as head and tail
  if (tail_ == NULL)
  {
  
    tail_ = new Item();
    head_ = tail_;
    tail_->first = 0;
    tail_->last = 0;
  }
  // If tail is full, allocate a new item, and update pointers
  if (tail_ -> last == ARRSIZE)
  {
    Item* newItem = new Item();
    newItem -> prev = tail_;
    // tail_->first = 0;
    // tail_->last = 0;
    newItem->first = 0;
    newItem->last = 0;
    tail_ -> next = newItem;
    tail_ = newItem;
  }
  // Insert new value
  tail_ -> val[tail_ -> last] = val;
  tail_ -> last++;
  size_++;
}
void ULListStr::pop_back()
{
  // Checks if list is empty, if not, it updates the back
  if (empty())
  {
    return;
  }
  tail_->last--;
  size_--;
  // If the tail node is empty, remove it from list
  if(tail_->first == tail_->last)
  {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL)
    {
      tail_->next = NULL;
    }
    else
    {
      head_ = NULL; // reset head
    }
    delete temp;
  }
}
void ULListStr::push_front(const std::string& val)
{
  // Initialize new item
  if (head_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  // ALlocate a new item if head is full
  if (head_ -> first == 0)
  {
    Item* newItem = new Item();
    newItem -> next = head_;
    head_ -> prev = newItem;
    head_ = newItem;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  // Update the list
  head_ -> first--;
  head_ -> val[head_ -> first] = val;
  size_++;
}
void ULListStr::pop_front()
{
  // Checks if list is empty
  if (empty())
  {
    return;
  }
  head_->first++;
  size_--;
  // Remove empty node if necessary
  if (head_->first == head_->last)
  {
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL)
    {
      head_->prev = NULL;
    }
    else
    {
      tail_ = NULL; // Reset tail
    }
    delete temp;
  }
}
std::string const & ULListStr::back() const
{
  // Checks for range error, and then returns proper indexed value
  if (empty())
  {
    throw std::out_of_range("Empty list");
  }
  return tail_->val[(tail_ -> last) -1];
}
std::string const & ULListStr::front() const
{
  // Checks for range error, and then returns proper indexed value
  if (empty())
  {
    throw std::out_of_range("Empty list");
  }
  return head_->val[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // Checks if out of bounds
  if (loc >= size_)
  {
    return NULL;
  }
  Item* temp = head_;
  size_t index = loc;
  // Loops through to find proper element, then indexes accordingly
  while (temp != NULL)
  {
    size_t block = temp -> last - temp -> first;
    if (index < block)
    {
      return &(temp -> val[temp->first + index]);
    }
    index -= block;
    temp = temp -> next;
  }
  return NULL;
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
