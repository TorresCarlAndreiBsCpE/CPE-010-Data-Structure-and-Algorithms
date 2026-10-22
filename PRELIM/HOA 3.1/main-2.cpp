#include <iostream>
#include "doubly_ll.h"

int main() {
    doubleList<char>* head = new_Node('C');
    doubleList<char>* second = new_Node('P');
    doubleList<char>* third = new_Node('E');

    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal: \n";
    dllTraverse(head);

    std::cout << "\n";
    std::cout << "Inserting at the head: " << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "\n";
    std::cout << "Inserting at the end: " << std::endl;
    dllInsertTail('1', &head);
    dllTraverse(head);
    
    std::cout << "\n";
    std::cout << "General Insertion: " << std::endl;
    doubleList<char>* current = head;

    while (current != nullptr && current->data != 'P'){
        current = current->next;
    }

    if(current != nullptr){
        dllInsertAny(current, 'X');
    }

    dllTraverse(head);
    
    std::cout << "\n";
    std::cout << "Deleting a node: " << std::endl;
    dllDeleteNode(&head, second);
    dllTraverse(head);

    return 0;
}