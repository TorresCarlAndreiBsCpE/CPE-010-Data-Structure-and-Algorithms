#ifndef STACK_LIST_H
#define STACK_LIST_H

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
void push(T newData){
    //create a new node ad the assign the new data
    Node<T>* newNode = new Node<T>;
    newNode -> data = newData;
    //new node points to current top, then becomes the new top
    newNode -> next = head<T>;
    head<T> = newNode;

}
//pop
template<typename T>
T pop(){
    //check if the stack is empty 
    if(head<T> == nullptr){
    std :: cout << "Stack Overflow";
    }

    //save the current top node 
    Node<T>* temp = head<T>;
    //store its data
    T tempVal = temp->data;

    //move the head to next node
    head<T> = head<T> -> next;
    //free the removed node
    delete temp;
    //return the removed node
    return tempVal;

}


//isEmpty
template<typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

//top
template<typename T>
void Top(){
     // create a error catching:
     if (head<T> == nullptr) {
        std::cout << "stack Underflow" << std::endl;
     }
     //display the top node
     std::cout << "The Current Top of the stack is: " << head <T> -> data << std::endl;
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