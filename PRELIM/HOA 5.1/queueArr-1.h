#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class Queue_Arr {
private:
    T* queue_Arr; // Pointer to dynamically allocated array for queue elements
    int front;    // Index of the front element in the queue 
    int back;     // Index of the back element in the queue
    int capacity; // Maximum number of elements the queue array can hold
    int size;     // Current number of elements in the queue

public:
    // Prototypes:
    Queue_Arr(size_t cap);
    bool Empty() const;
    bool Full() const;

    size_t Size() const;
    void Clear();

    T Front() const;
    T Back() const;

    void Enqueue(T newData);
    void Dequeue();
    void Display() const;

    // Rule of Three
    ~Queue_Arr();
    Queue_Arr(const Queue_Arr& other);
    Queue_Arr& operator=(const Queue_Arr& other);
};

// --- Method Definitions ---

//Constructor
template <typename T>
Queue_Arr<T>::Queue_Arr(size_t cap) { // Initializes the queue with a specified capacity
    capacity = static_cast<int>(cap); // Allocates memory for the queue array based on the specified capacity
    queue_Arr = new T[capacity]; // Dynamically allocates an array of type T with the specified capacity
    front = 0;
    back = -1;
    size = 0;
    std::cout << "Constructor was called" << std::endl;
}

// Size Method
template <typename T>
size_t Queue_Arr<T>::Size() const {
    return static_cast<size_t>(size); // Returns the current number of elements in the queue
}

// Empty Method
template <typename T>
bool Queue_Arr<T>::Empty() const {
    return size == 0;
}

// Full Method
template <typename T>
bool Queue_Arr<T>::Full() const {
    return size == capacity;
}

// Clear Method
template <typename T>
void Queue_Arr<T>::Clear() {
    front = 0;
    back = -1;
    size = 0;
}

// Front Accessor
template <typename T>
T Queue_Arr<T>::Front() const {
    if (Empty()) {
        std::cout << "Queue is empty\n";
        return T{};
    }
    return queue_Arr[front];
}

// Back Accessor
template <typename T>
T Queue_Arr<T>::Back() const {
    if (Empty()) {
        std::cout << "Queue is empty\n";
        return T{};
    }
    return queue_Arr[back];
}

// Enqueue Method
template <typename T>
void Queue_Arr<T>::Enqueue(T newData) {
    if (Full()) {
        std::cout << "Queue is full\n";
        return;
    }
    back = (back + 1) % capacity; //Circular Modulo
    queue_Arr[back] = newData; //Assign the back of the array to the new allocated data.
    size++; //Increment the size of the array
}

// Dequeue Method
template <typename T>
void Queue_Arr<T>::Dequeue() {
    if (Empty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    front = (front + 1) % capacity;
    size--;
}

// Display Method
template <typename T>
void Queue_Arr<T>::Display() const {
    if (Empty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << queue_Arr[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

// Copy Constructor
template <typename T>
Queue_Arr<T>::Queue_Arr(const Queue_Arr& other) {
    capacity = other.capacity;
    size = other.size;
    front = 0; // Initializes front index to 0 for the new queue
    back = (size == 0) ? -1 : size - 1; // Initializes back index based on size
    queue_Arr = new T[capacity];
    
    // Copies elements from the other queue to this queue, maintaining the correct order
    for (int i = 0; i < size; i++) {
        queue_Arr[i] = other.queue_Arr[(other.front + i) % other.capacity];
    }
    std::cout << "Copy Constructor was called" << std::endl;
}

// Copy Assignment Operator
template <typename T>
Queue_Arr<T>& Queue_Arr<T>::operator=(const Queue_Arr& other) {
    if (this == &other) {
        return *this;
    }
    delete[] queue_Arr; // Deallocates existing memory to prevent memory leaks
    
    // Allocates new memory and copies the elements from the other queue
    capacity = other.capacity;
    size = other.size;
    queue_Arr = new T[capacity];
    
    // Copies elements from the other queue to this queue, maintaining the correct order
    for (int i = 0; i < size; i++) {
        queue_Arr[i] = other.queue_Arr[(other.front + i) % other.capacity];
    }
    front = 0; // Initializes front index to 0 for the new queue
    back = (size == 0) ? -1 : size - 1; // Initializes back index based on size

    std::cout << "Copy Assignment Operator was called" << std::endl;
    return *this; // Returns the current object to allow for chained assignments
}

// Destructor
template <typename T>
Queue_Arr<T>::~Queue_Arr() { // Destructor to clean up dynamically allocated memory
    delete[] queue_Arr; // Deallocates the dynamically allocated memory for the queue array
    std::cout << "Destructor was called" << std::endl;
}

#endif