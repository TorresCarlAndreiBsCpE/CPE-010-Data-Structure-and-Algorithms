#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template<typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

template<typename T>
doubleList<T>* new_Node (T newData) {

    doubleList<T>* newNode = new doubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

template<typename T>
void dllTraverse(doubleList<T>* currentNode) {
    doubleList<T>* last = nullptr;

    std::cout << "Forward\n";
    while (currentNode != nullptr) {
        std::cout << currentNode->data << "->";
        last = currentNode;            // keep track of tail
        currentNode = currentNode->next;
    }
    std::cout << "NULL\n\n";

    if (last == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "Reverse\n";
    while (last != nullptr) {
    std::cout << last->data << "->";
    last = last->prev;
    }
    std::cout << "NULL\n";
}

template<typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {
    doubleList<T>* newNode = new_Node(newData);
    newNode->next = *currentHead;
    if (*currentHead != nullptr) {
        (*currentHead)->prev = newNode;
    }
    *currentHead = newNode;
}

template<typename T>
void dllInsertTail(T newData, doubleList<T>** currentHead) {
    doubleList<T>* newNode = new_Node(newData);

    if (*currentHead == nullptr) {
        *currentHead = newNode;
        return;
    }

    doubleList<T>* currentNode = *currentHead;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
}

// GENERAL INSERTION
template<typename T>
void dllInsertAny(doubleList<T>* prevNode, T newData) {
     //Check if it is the head node (previous node is null)
     if (prevNode == nullptr) {
        std::cout << "The previous node cannot be NULL.\n";
        return;
    }
    
    //Allocate a new node
    doubleList<T>* newNode = new_Node(newData);

    // Link new node with next node
    newNode->next = prevNode->next;
    
    // Link new node with previous node
    newNode->prev = prevNode;

    // Link previous node with new node
    prevNode->next = newNode;

    // Fix the backward link of the next node
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

//DELETION
template<typename T>
void dllDeleteNode(doubleList<T>** head, doubleList<T>* delNode) {
     // If list is empty or node to delete is NULL, do nothing
     if (*head == nullptr || delNode == nullptr)
        return;
     // If the node to delete is the head, move head to the next node
     if (*head == delNode)
        *head = delNode->next;
     // If there is a next node, update its prev pointer
     if (delNode->next != nullptr)
        delNode->next->prev = delNode->prev;
     // If there is a previous node, update its next pointer
     if (delNode->prev != nullptr)
        delNode->prev->next = delNode->next;
     // Delete the node and clear pointer
     delete delNode;
     delNode = nullptr;
}

#endif