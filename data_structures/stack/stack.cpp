#include <iostream>
#include "array_stack.hpp"

int main()
{

    Array_Stack<int> stack(5);

    stack.push(5);
    stack.push(10);
    stack.push(2);
    stack.push(24);
    stack.push(54);
    stack.push(65);
    std::cout << "Now Popping from the stack" << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.push(32);

    return 0;
}