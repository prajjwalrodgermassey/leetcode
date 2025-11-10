/* NOTE :- Using size and top variables to manage the size of the stack and top variable is enough to access and delete the elements in the stack as both of these functions are
performed on the same side of the array in stack implementation*/

#ifndef ARRAY_STACK
#define ARRAY_STACK

#include <iostream>
#include <vector>

template <typename T>
class Array_Stack
{
private:
    std::vector<T> arr;
    int size, top = -1;

public:
    Array_Stack<T>(int capacity) : size(capacity), arr(capacity) {}

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top == this->size - 1;
    }

    void push(T elem)
    {
        if (this->isFull())
        {
            std::cout << "The Stack is already full" << std::endl;
            return;
        }
        this->arr[++this->top] = elem;
        std::cout << "Element pushed at the top of the stack: " << this->arr[this->top] << std::endl;
        return;
    }

    void pop()
    {
        if (this->isEmpty())
        {
            std::cout << "The stack is already empty" << std::endl;
            return;
        }
        std::cout << "Popping an element from top of the stack: " << this->arr[this->top] << std::endl;
        this->top--;
        return;
    }

    void showTop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty, therefore nothing at top" << std::endl;
        }
        std::cout << "The element at the top is: " << this->arr[this->top] << std::endl;
    }
};

#endif