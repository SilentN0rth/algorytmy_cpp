#include <iostream>

using namespace std;

class Node {

public:
    Node * next;
    Node * prev;
    int value;

    Node(int value) {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = value;
    }
};

class LinkedList {

public:
    Node * head;
    Node * tail;
    int size;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~LinkedList() {
        //clearList
    }

    void addBegin(int value) {

        Node * newNode = new Node(value);

        if (head == nullptr) {
            // nie ma elementów w liście
            head = tail = newNode;

        }else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;

    }

    void showFromBegin() {

        Node * traversal = head;

        while (traversal != nullptr) {

            cout << traversal->value << endl;
            traversal = traversal->next;
        }


    }

};


