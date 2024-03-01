#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  PComparator comp;
  int m_;



};

// Add implementation of member functions here
template <class T, class PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : comp(c), m_(m) {

}


template <class T, class PComparator>
Heap<T, PComparator>::~Heap() {}



template <class T, class PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data_.push_back(item);

  // heapify up
  std::size_t index = data_.size() - 1;
  while (index != 0) {
      std::size_t parent_index = (index - 1) / m_;
      T& current = data_[index];
      T& parent = data_[parent_index];
      if (comp(current, parent)) { // if the current is 'better' than the parent
        std::swap(current, parent);
        index = parent_index;
      }
      else {
        break; // heap property is not violated so break out of loop
      }
  }

}



template <class T, class PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();
}

template <class T, class PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <class T, class PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: Empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <class T, class PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: Cannot pop from empty heap");

  }

  // Swap with the last element before removing
  std::size_t index = 0;
  std::swap(data_[index], data_.back());
  data_.pop_back();

  // heapify down
  while (index < data_.size()) {
      std::size_t best_child_index = index;
      std::size_t child_index;
      
      for (int i = 1; i <= m_; i++) {
          child_index = m_ * index + i;
          if (child_index < data_.size() && comp(data_[child_index], data_[best_child_index])) {
              best_child_index = child_index;
          }
      }

      T& current = data_[index];
      T& best_child = data_[best_child_index];
      if (index == best_child_index) { // this was greater than or equal to so might cause error
          break;
      }
      std::swap(current, best_child);
      index = best_child_index;
  }

}



#endif

