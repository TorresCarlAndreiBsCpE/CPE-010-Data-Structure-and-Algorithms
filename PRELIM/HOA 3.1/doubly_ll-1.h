#ifndef DOUBLE_LL_PLAYL_H
#define DOUBLE_LL_PLAYL_H

template<typename T>
class song {
public:
    T data;
    song<T>* next = nullptr;
    song<T>* prev = nullptr;
};

template<typename T>
song<T>* new_Node (T newData) {

    song<T>* newSong = new song<T>;

    newSong->data = newData;
    newSong->next = newSong; //Circular Linked List
    newSong->prev = newSong;

    return newSong;
}

template<typename T>
void dllplayAll(song<T>* currentNode) {
    
    if (currentNode == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    song<T>* current = currentNode;
    do {
        std::cout << current->data << "->";
        current = current->next;
    }while (current != currentNode);
    std::cout << "END\n";
}


// GENERAL INSERTION
template<typename T>
void dllInsertAfter(song<T>* prevNode, T newData) {
     //Check if it is the head node (previous node is null)
     if (prevNode == nullptr) return;
     song<T>* newSong = new_Node(newData);
     newSong->next = prevNode->next;
     newSong->prev = prevNode;
     prevNode->next->prev = newSong;
     prevNode->next = newSong;
    }
    

//DELETION
template<typename T>
void dllDeleteNode(song<T>** head, song<T>* delNode) {
     // If list is empty or node to delete is NULL, do nothing
    if (*head == nullptr || delNode == nullptr)
        return;
     // Case: only one node in the list
    if (delNode->next == delNode && delNode->prev == delNode) {
        *head = nullptr;
    } else {
        // Update the next and prev pointers of neighboring nodes
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;

        // If the node to be deleted is the head, update the head pointer
        if (*head == delNode) {
            *head = delNode->next;
        }
    }   
     delete delNode;
     delNode = nullptr;
}

//Play Next Song
template<typename T>
void dllplayNext(song<T>** currentNode) {
    if (*currentNode == nullptr) {
        std::cout << "No song is currently playing.\n";
        return;
    }
    *currentNode = (*currentNode)->next;
    std::cout << "Now playing from the Playlist: " << (*currentNode)->data << std::endl;
}

//Play Previous Song
template<typename T>
void dllplayPrevious(song<T>** currentNode) {
    if (*currentNode == nullptr) {
        std::cout << "No song is currently playing.\n";
        return;
    }
    *currentNode = (*currentNode)->prev;
    std::cout << "Now playing from the Playlist: " << (*currentNode)->data << std::endl;
}

#endif