#include <iostream>
#include "stackList.h"

int main() {
    std::cout << "--- PUSHING 'c' 'p' 'e' ONTO THE STACK --- \n";

    push<char>('c');
    push<char>('p');
    push<char>('e');

    // Display the current top
    Top<char>();// Should display 'e'
    
    
    displayAll<char>();

    std::cout << "\n --- Popping all the elements --- \n";

    // Fixed: Loop while the stack is NOT empty
    while (!isEmpty<char>()) {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n--- Testing the Underflow --- \n";
    pop<char>();


    return 0;
}