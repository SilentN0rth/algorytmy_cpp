#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {

public:
    Node<T> * next;
    Node<T> * prev;
    T value;

    Node(T value) {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = value;
    }
};

template <typename T>
class LinkedList {

public:
    typedef int (*DataCmp)(T,T);
    typedef string (*DataToString)(T);

    Node<T> * head;
    Node<T> * tail;
    int size;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~LinkedList() {
        //clearList
    }

    void addBegin(T value) {

        Node<T> * newNode = new Node<T>(value);

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

        Node<T> * traversal = head;

        while (traversal != nullptr) {

            cout << traversal->value << endl;
            traversal = traversal->next;
        }
    }

    // zad k)
    string toString(DataToString printer = nullptr) {
        string res = "(list, list_size=" + to_string(size) + "): ";
        
        Node<T> * traversal = head;
        int ind = 0;

        while(traversal != nullptr){
            if(ind > 0) res += ", ";
            res += printer(traversal->value);
            traversal = traversal->next;
            ind++;
        }

        return res;
    }


};


