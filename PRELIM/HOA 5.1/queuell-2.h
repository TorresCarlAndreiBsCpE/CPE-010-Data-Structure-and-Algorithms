#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode{
    public:
    T data;
    qNode *next;
};

//creating a new node
template <typename T>
qNode<T>* new_node(T newData){
     qNode<T>* newNode = new qNode <T>;
     newNode -> data = newData;
     newNode -> next = nullptr;
     return newNode;
}

template<typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){
    //Create a new node
    qNode<T>* newNode = new_node(newData);

    //Inserting to an empty queue
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
    (*frontPtr) = newNode;
    (*backPtr) = newNode;
    }

    //Inserting an item into a non empty queue
    //Point the backPtr next to the newNode
    (*backPtr) -> next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
     //create a temporary node to store the node to be deleted
     qNode<T>* deleteNode = nullptr;
     deleteNode = (*frontPtr);
     //check if the queue is only one node
     if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
     }
     //deleting of the node
     (*frontPtr) = deleteNode -> next;
     deleteNode -> next = nullptr;
     delete deleteNode;
}

//display all the elements in the list
template <typename T>
void display(qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* temp = (*frontPtr);

    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        std::cout<<"The Queue is Empty!\n";
        return;
    }

    do {
        std::cout<< temp -> data << " ";
        temp = temp->next;
    }while(temp!= nullptr);
    std::cout << "\n";
}

//return the front variable
template <typename T>
T FrontQ(qNode<T>* frontPtr){
    if  (frontPtr == nullptr) {
        throw std::runtime_error("The Queue is Empty");
    }
    return frontPtr->data;
}



#endif