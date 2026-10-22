#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

template <typename T>
class Node{

public:
    T data;
    Node* next;

};

//Global Pointer for the top of the stack
template<typename T>
Node<T> *head = nullptr;

//operations for the stack

//push
template<typename T>
void push(T newData) {
    // Only push the opening symbols onto the stack
    if (newData == '(' || newData == '[' || newData == '{') {
        //Allocate memory for a new node and assign the new data
        Node<T>* newNode = new Node<T>;
        // Assign the new data to the new node
        newNode->data = newData;
        // Make the new node point to the current top of the stack
        newNode->next = head<T>;
        // Update the head to point to the new node
        head<T> = newNode;
    } else {
        // Ignore non-opening symbols
        std::cout << "Ignores non-opening symbol: " << newData << "\n";
    }
}
//pop
template<typename T>
bool pop(T closingSymbol){
    //check if the stack is empty
    if(head<T> == nullptr){
        std::cout << "Stack Underflow" << std::endl;
        return false;
    }

    //save the current top node
    Node<T>* temp = head<T>;
    //store its data
    T topChar = temp->data;
    //Check if the Top Character matches the closing symbol
    bool match = (topChar == '(' && closingSymbol == ')') ||
                 (topChar == '[' && closingSymbol == ']') ||
                 (topChar == '{' && closingSymbol == '}');
    //If the symbols do not match, report an error and return false
    if (!match) {
        std::cout << "ERROR: expected matching symbol for: " << topChar << ", but found: " << closingSymbol << ".\n";
        return false;
    }
    //move the head to next node
    head<T> = head<T> -> next;
    //free the removed node
    delete temp;
    //return the removed node
    return true;

}


//isEmpty
template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

//top
template<typename T>
void Top(){
    // error catching
    if (head<T> == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    // display the top node
    std::cout << "The Current Top of the stack is: " << head<T>->data << std::endl;
}

//displayAll
template<typename T>
void displayAll(){
    if (isEmpty<T>()){
        std::cout<< "Stack is Empty! \n";
        return;
    }

    std::cout << "Stack (top to bottom) : ";
    Node<T>* current = head<T>;
    while (current != nullptr) {
        std::cout << current -> data;
        if (current -> next != nullptr) std::cout << " -> ";
        current = current -> next;
    }
    std::cout << std::endl;
}


#endif