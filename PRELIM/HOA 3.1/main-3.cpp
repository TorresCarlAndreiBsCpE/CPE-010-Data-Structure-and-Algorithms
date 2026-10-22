#include <iostream>
#include "doubly_ll.h"

int main() {
    song<std::string>* head = new_Node(std::string("Kung Wala ka by Hale"));
    song<std::string>* second = new_Node(std::string("Dating Tayo by Tj Monterde"));
    song<std::string>* third = new_Node(std::string("About You by The 1975"));

    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;

    third->next = head; // Circular Linked List
    head->prev = third; // Circular Linked List

// Display the playlist
       
    std::cout << "\n";
    std::cout << "\n---Sadboi Playlist---\n";
    dllplayAll(head);

// Inserting a new song after the second song
    std::cout << "\n";
    std::cout << "Inserting at the end: " << std::endl;
    dllInsertAfter(third, std::string("Mundo by IV of Spades"));
    dllplayAll(head);
    
//Deleting a node
       
    std::cout << "\n";
    std::cout << "\nDeleting a node:\n";
    song<std::string>* toDelete = nullptr;
    song<std::string>* current = head;
    do {
        if (current->data == "Dating Tayo by Tj Monterde") {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (toDelete != nullptr) {
        dllDeleteNode(&head, toDelete);
    }
    
    dllplayAll(head);

//Play Next Song
    std::cout << "\n";
    std::cout << "Play Next Song: " << std::endl;
    song<std::string>* currentSong = head;
    dllplayNext(&currentSong);
    dllplayAll(currentSong);
    
//Play Previous Song      
    std::cout << "\n";
    std::cout << "Play Previous Song: " << std::endl;
    song<std::string>* currentSongPrev = currentSong->prev;
    dllplayPrevious(&currentSongPrev);
    dllplayAll(currentSongPrev);

    return 0;
}