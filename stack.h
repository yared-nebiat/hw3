#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() {}
    ~Stack() {}
    bool empty() const {
        return std::vector<T>::empty();
    }
    size_t size() const {
        return std::vector<T>::size();
    }
    void push(const T& item) {
        std::vector<T>::push_back(item);
    }
    void pop() {
        if(empty()) {
            throw std::underflow_error("Error: Cannot pop from empty stack");
        }
        else {
            std::vector<T>::pop_back();
        }
    }
    const T& top() const {
        if(empty()) {
            throw std::underflow_error("Error: Stack is empty");
        }
        else {
            return std::vector<T>::back();
        }
    }
};


#endif