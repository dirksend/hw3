#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {
public:
    Stack() {};
    ~Stack() {};
    bool empty() const {
        return std::vector<T>::size() == 0;
    }
    size_t size() const {
        return std::vector<T>::size();
    }
    void push(const T& item) {
        std::vector<T>::push_back(item);
    }
    void pop() {
        if (std::vector<T>::size() == 0) throw std::underflow_error("pop() called on empty stack");
        
        std::vector<T>::pop_back();
    }
    const T& top() const {
        if (std::vector<T>::size() == 0) throw std::underflow_error("top() called on empty stack");
        
        return std::vector<T>::back();
    }
};


#endif