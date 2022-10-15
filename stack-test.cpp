#include "stack.h"
#include <iostream>

int main() {
    Stack<int>* stack = new Stack<int>();
    std::cout << "Size: " << stack->size() << std::endl;
    std::cout << "Adding 4,2,0.\n";
    stack->push(4);
    stack->push(2);
    stack->push(0);
    std::cout << "Size: " << stack->size() << std::endl;
    std::cout << "Top: " << stack->top() << std::endl;
    std::cout << "Popping.\n";
    stack->pop();
    std::cout << "Top: " << stack->top() << std::endl;
    std::cout << "Popping.\n";
    stack->pop();
    std::cout << "Popping.\n";
    stack->pop();
    // std::cout << "Top: " << stack->top() << std::endl;
    std::cout << "Popping. This should throw an error\n";
    stack->pop();
}