#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <functional>

// Node class template

//where abstraction is happening
template<typename T>
class Node {
private:
    T data;
    Node<T>* next;

    // Grant LinkedList access to private members
    template<typename> friend class LinkedList;

public: //constructor, take the value coming in, assign it to data, make sure next pointer is
    //null pointer
    Node(T val) : data(val), next(nullptr) {}
};


template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) { //checks if head is nullptr
            head = newNode;
        }
        else {
            Node<T>* current = head;
            //moves through linked list until curr is the final node in the list
            while (current->next) { //checks if current is pointing to a null ptr so it is last node
                current = current->next; //assigns current to the next node in the linked list
            }

            //makes current pointer point to newNode
            current->next = newNode;
        }
    }

    void addFirst(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }

    }

    void deleteFirst() {
        if (!head) {
            return;
        }

            Node<T>* current = head->next;
            delete head;
            head = current;

    }

    void deleteLast() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;

    }
    void deleteAtIndex(int index) {

        // Else index was out of bounds, do nothing
    }
    void forEach(std::function<void(const T&, bool)> callback) {
        Node<T>* current = head;
        while (current) {
            bool isLast = (current->next == nullptr);
            callback(current->data, isLast);
            current = current->next;
        }
    }

    ~LinkedList() { //destructor
        while (head) {
            Node<T>* current = head;
            head = head->next;
            delete current;
        }

    }
};

#endif // LINKEDLIST_H