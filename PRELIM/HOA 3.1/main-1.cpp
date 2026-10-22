#include <iostream>
#include "singly_ll.h"



int main(){
    //this line creates a empty linked list
   SingleList<std::string> *head = new SingleList<std::string>;
   SingleList<std::string> *second = new SingleList<std::string>;
   SingleList<std::string> *third = new SingleList<std::string>;
   SingleList<std::string> *fourth = new SingleList<std::string>;
   SingleList<std::string> *fifth = new SingleList<std::string>;
   SingleList<std::string> *sixth = new SingleList<std::string>;
   
   head -> data = 'C';
   head -> next = second;

   second -> data = 'P';
   second -> next = third;

   third -> data = 'E';
   third -> next = fourth;

   fourth -> data = '0';
   fourth -> next = fifth;

   fifth -> data = '1';
   fifth -> next = sixth;

   sixth -> data = '0';
   sixth -> next = nullptr;

   
   std::cout << "Linked List Traversal: ";
   listTraversal(head);
   
   std::cout << "Newly-Inserted head of Linked List: ";
   sllinsertHead(std::string("G"), &head);
   listTraversal(head);
   

   std::cout << "After inserting E after P: \n";
   sllGeneralinsertion(std::string("E"), second);
   listTraversal(head);

   //Deleting the node with data C
   std::cout << "deleting a node: \n";
   std::cout << "Before deleting C: \n";
   listTraversal(head);

   sllDelete(std::string("C"), &head);

   std::cout << "After deleting C: \n";
   listTraversal(head);
   
   //Deleting the node with data P
   std::cout << "deleting a node: \n";
   std::cout << "Before deleting P: \n";
   listTraversal(head);

   sllDelete(std::string("P"), &head);

   std::cout << "After deleting P: " <<std::endl;
   listTraversal(head);

   //Display the current linked list
    std::cout << "Current Linked List: \n";
    listTraversal(head);

}