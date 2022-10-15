#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap {
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
  size_t ary_;
  PComparator comp_;
  std::vector<T> data_;

  size_t parentOf_(size_t index) const {
    if (index == 0) throw std::underflow_error("Node does not exist");
    if (index == 1) throw std::underflow_error("Cannot get parent of top");
    return ((int)index - 2) / (int)ary_ + 1;
  }

  size_t childOf_(size_t index) const {
    if (index == 0) throw std::underflow_error("Node does not exist");
    return index * ary_;
  }

  void swap_(size_t index1, size_t index2) {
    T temp = data_[index1];
    data_[index1] = data_[index2];
    data_[index2] = temp;
  }

  void trickleUp_(size_t index) {
    if (index == 1) return;
    size_t parent = parentOf_(index);
    if (comp_(data_[index], data_[parent])) {
      
      swap_(index, parent);
      trickleUp_(parent);
    }
  }

  void trickleDown_(size_t index) {
    size_t firstChild = childOf_(index);
    if (firstChild >= data_.size()) return;
    size_t lastChild = std::min(firstChild + ary_ - 1, data_.size() - 1);

    size_t bestChild = firstChild;

    for (size_t sibling = firstChild + 1; sibling <= lastChild; ++sibling) {
			if (comp_(data_[sibling], data_[bestChild])) {
        bestChild = sibling;
      }
    }
    if (comp_(data_[bestChild], data_[index])) {
      swap_(bestChild, index);
      // tickle down from the previou position of the best child, where the worse
      // parent now sits
      trickleDown_(bestChild);
    }
  }
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : ary_(m), comp_(c) {
  data_.push_back(0);
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap<T, PComparator>() {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data_.push_back(item);
  trickleUp_(size());
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
  if(empty()){
    throw std::underflow_error("Cannot get the top element from empty queue.");
  }
  return data_[1];
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Cannot pop from empty queue.");
  }
  data_[1] = data_.back();
  data_.pop_back();
  trickleDown_(1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return (size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size() - 1;
}

#endif






