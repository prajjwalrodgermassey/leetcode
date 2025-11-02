#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <iostream>
#include <vector>

template <typename T>
class Array_Queue
{
    // We've to manage the capacity manually in C++ as the arrays or vectors can access memory outside their limit as well, vectors via (pushback) and arrays directly through index
protected:
    int front = -1, rear = -1, capacity;
    std::vector<T> arr;

public:
    // Constructor
    Array_Queue(int size) : arr(size), capacity(size)
    {
        std::cout << "Initalizing normal Queue using array" << std::endl;
        return;
    }

    virtual ~Array_Queue()
    {
        std::cout << "Calling virtual destructor of Array_Queue base class" << std::endl;
    }

    // check if the queue is empty
    virtual bool isEmpty()
    {
        if (this->front == -1 && this->rear == -1)
        {
            return true;
        }
        return false;
    }

    // Check if the queue is full
    virtual bool isFull()
    {
        if (rear == this->capacity - 1)
        {
            return true;
        }
        return false;
    }

    virtual void enqueue(const T &elem)
    {
        if (isFull())
        {
            std::cout << "The Queue is already full" << std::endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = elem;
        }
        else
        {
            rear++;
            arr[rear] = elem;
        }

        std::cout << "Enqueuing element: " << arr[rear] << std::endl;

        return;
    }

    virtual void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "The Queue is already empty" << std::endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                auto elem = arr[front];
                front = rear = -1;
                std::cout << "Dequeuing element: " << elem << std::endl;
            }
            else
            {
                auto elem = arr[front];
                front++;
                std::cout << "Dequeuing element: " << elem << std::endl;
            }

            return;
        }
    }

    virtual void display()
    {
        for (auto i = front; i <= rear; i++)
        {
            std::cout << arr[i] << "\n"
                      << std::endl;
        }
    }

    void showFront()
    {
        if (isEmpty())
        {
            std::cout << "The Queue is already empty" << std::endl;
            return;
        }
        std::cout << arr[front] << std::endl;
    }

    void showRear()
    {
        if (isEmpty())
        {
            std::cout << "The Queue is already empty" << std::endl;
            return;
        }
        std::cout << arr[rear] << std::endl;
        return;
    }
};

template <typename T>
class Circular_Array_Queue : public Array_Queue<T>
{
public:
    Circular_Array_Queue(int size) : Array_Queue<T>::Array_Queue(size)
    {
        std::cout << "Initalizing Circular Queue using array" << std::endl;
        return;
    }

    // Check if the queue is full
    virtual bool isFull() override
    {
        if ((this->rear + 1) % this->capacity == this->front)
        {
            return true;
        }
        return false;
    }

    virtual void enqueue(const T &elem) override
    {
        if (isFull())
        {
            std::cout << "The Queue is already full, please delete an element from the queue first" << std::endl;
            return;
        }
        else if (this->isEmpty())
        {
            this->front = 0;
        }
        this->rear = (this->rear + 1) % this->capacity;
        this->arr[this->rear] = elem;
        std::cout << "Enqueuing element in circular queue: " << this->arr[this->rear] << std::endl;
        return;
    }

    virtual void dequeue() override
    {
        if (this->isEmpty())
        {
            std::cout << "The Circular Queue is already empty" << std::endl;
            return;
        }
        else if (this->front == this->rear)
        {
            auto elem = this->arr[this->front];
            this->front = this->rear = -1;
            std::cout << "Dequeuing from the circular queue: " << elem << std::endl;
            return;
        }
        else
        {
            auto elem = this->arr[this->front];
            this->front = (this->front + 1) % this->capacity;
            std::cout << "Dequeuing from the circular queue: " << elem << std::endl;
            return;
        }
    }

    virtual void display() override
    {
        if (this->isEmpty())
        {
            std::cout << "The Circular Queue is already empty" << std::endl;
            return;
        }
        else if (this->front < this->rear)
        {
            Array_Queue<T>::display();
            return;
        }
        else
        {
            int i = this->front;
            while (i < this->capacity)
            {
                std::cout << this->arr[i] << "\n"
                          << std::endl;
                i++;
            }
            i = 0;
            while (i < this->rear)
            {
                std::cout << this->arr[i] << "\n"
                          << std::endl;
                i++;
            }
        }
    }
};

#endif