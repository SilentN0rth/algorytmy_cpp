#include <iostream>
#include <string>
#include <type_traits>
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
    typedef int (*DataCompare)(T,T);
    typedef string (*DataToString)(T);

    Node<T> * head;
    Node<T> * tail;
    int size;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    LinkedList(const LinkedList &) = delete;
    LinkedList & operator=(const LinkedList &) = delete;

    ~LinkedList() {
        clearList();
    }
    // zad a)
    void addEnd(T value) {
        Node<T> * newNode = new Node<T>(value);
        if(tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }

        size++;
    }

    // zad b)
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
    // zad c)
    bool removeLastElement(bool isOk = false){
        if (tail == nullptr) return false;
        
        killNode(tail, isOk);
        return true;
    }
    
    // zad d)
    bool removeBeginElement(bool isOk = false) {
        if (head == nullptr) return false;

        killNode(head, isOk);
        return true;
    }
    // zad e)
    T * getAt(int index){
        Node<T> * node = nodeAt(index);
        if(node == nullptr) return nullptr;
        return &node -> value;
    }

    // zad f)
    bool setAt(int index, T value, bool freeOldData = false){
        Node<T> * node = nodeAt(index);  
        if(node == nullptr) return false;
        if(freeOldData) deleteValue(node -> value);
        node -> value = value;
        return true;
    }
    // zad g)
    Node<T> * find(T target, DataCompare compare){
        Node<T> * traversal = head;
        while(traversal != nullptr) {
            if (compare(traversal->value, target) == 0) { 
                return traversal;
            }

            traversal = traversal->next;
        }
        return nullptr;
    }

    // zad h)
    bool findAndRemove(T target, DataCompare compare, bool free = false){
        Node<T> * node = find(target, compare);
        if(node == nullptr) return false;
        killNode(node, free);
        return true;

    }
    // zad i)

    void addSorted(T value, DataCompare compare){
        Node<T> * traversal = head;
        while(traversal != nullptr && compare(traversal->value, value) <= 0){
            traversal = traversal -> next;
        }

        if(traversal == nullptr){
            // sprwadz czy dodaje na koniec
            addEnd(value);
        } else if (traversal -> prev == nullptr){
            addBegin(value);
            // czy na poczatek
        } else {
            Node<T> * newNode = new Node<T>(value);
            newNode->prev = traversal->prev;
            newNode->next = traversal;
            traversal->prev->next = newNode;
            traversal->prev = newNode;

            size++;
        }
    }

    // zad j)
    void clearList(bool isOk = false){
        while (head != nullptr) killNode(head, isOk);
    }

    // zad k)
    string toString(int maxItems = 10, DataToString printer = nullptr) {
        string res = "(list, list_size=" + to_string(size) + "): ";
        
        Node<T> * traversal = head;
        int ind = 0;

        while(traversal != nullptr && ind < maxItems){
            if(ind > 0) res += ", ";
            res += printer(traversal->value);
            traversal = traversal->next;
            ind++;
        }
        if(size > maxItems) res += ", ...";
        return res;
    }
private:
    void deleteValue(T & value){
        if constexpr (is_pointer<T>::value) delete value;
    }

    void killNode(Node<T> * node, bool isOk){
        (node->prev != nullptr) ? (node -> prev -> next = node->next) : (head = node -> next);

        (node -> next != nullptr) ? (node->next->prev = node->prev) : (tail = node->prev);

        if(isOk) deleteValue(node->value);
        delete node;
        size--;
    }
    Node<T> * nodeAt(int index){
        if(index < 0 || index > size) return nullptr;
        Node<T> * traversal;
        if(index < size / 2){
            traversal = head;
            for(int i = 0; i < index; i++){
                traversal = traversal->next;
            }
        } else {
            traversal = tail;
            for(int i = size - 1; i > index; i--){
                traversal = traversal -> prev;
            }
        }
        return traversal;
    }
};


