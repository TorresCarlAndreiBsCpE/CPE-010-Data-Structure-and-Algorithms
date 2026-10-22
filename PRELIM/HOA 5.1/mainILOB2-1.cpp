#include <iostream>
#include "queueArr.h"

int main() {
    std::cout << "=== 1. Creating Queue Instance (Capacity: 5) ===" << std::endl;
    Queue_Arr<std::string> q1(5);

    std::cout << "\n=== 2. Checking Initial State ===" << std::endl;
    std::cout << "Is the queue empty? " << q1.Empty() << std::endl;
    std::cout << "Size of the queue: " << q1.Size() << std::endl;

    std::cout << "\n=== 3. Enqueuing Elements ===" << std::endl;
    q1.Enqueue("C");
    q1.Enqueue("A");
    q1.Enqueue("R");
    q1.Enqueue("L");
    q1.Enqueue("T");
    
    // Attempting to push beyond capacity
    q1.Enqueue("R");
    std::cout << "Attempted to enqueue beyond capacity." << std::endl;

    std::cout << "\n=== 4. Displaying Queue Content ===" << std::endl;
    std::cout << "Queue elements: " << std::endl;
    std::cout << "Front of the queue: " << q1.Front() << std::endl;
    std::cout << "Back of the queue: " << q1.Back() << std::endl;
    std::cout << "Size of the queue: " << q1.Size() << std::endl;

    std::cout << "\n=== 5. Testing Copy Constructor ===" << std::endl;
    Queue_Arr<std::string> q2(5); // Create a new queue with the same capacity
    std::cout << "The Copy Constructor was called" << std::endl;
    
    std::cout << "\n=== 6. Testing Copy Assignment Operator ===" << std::endl;
    q2 = q1; // Triggers Copy Assignment Operator
    std::cout << "The Copy Assignment Operator was called" << std::endl;

    std::cout << "\n=== 7. Dequeuing Elements from Original Queue ===" << std::endl;
    q1.Dequeue();
    q1.Dequeue();
    std::cout << "Queue elements after 2 dequeues: " << std::endl;
    std::cout << "The front element is: " << q1.Front() << std::endl;
    std::cout << "The back element is: " << q1.Back() << std::endl;
    
    std::cout << "\n=== 8. Circular Enqueue Behavior ===" << std::endl;
    q1.Enqueue("T");
    q1.Enqueue("RRS");
    std::cout << "Queue elements after wrap-around enqueue: " << std::endl;
    std::cout << "The front element is: " << q1.Front() << std::endl;
    std::cout << "The back element is: " << q1.Back() << std::endl;
    
    std::cout << "\n=== 9. Testing Clear Method ===" << std::endl;
    std::cout << "Clearing the queue..." << std::endl;
    q1.Clear();
    std::cout << "Is the queue empty after clear? " << q1.Empty() << std::endl;
    std::cout << "Size of the queue after clear: " << q1.Size() << std::endl;

    std::cout << "\n=== 10. Exiting Scope (Destructors Auto-Called) ===" << std::endl;
    return 0;
}