#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

#include "linked_list.h"

#pragma once

struct some_object
{
    int field_1;
    char field_2;
};

// ide krzyczy inline
inline std::string someObjectToString(some_object * so){
    return "(" + std::to_string(so->field_1) + "," + so->field_2 + ")";
}

// ide krzyczy inline
inline some_object * randomObject() {
    some_object * so = new some_object;

    so->field_1 = rand() % 2137;
    so->field_2 = 'a' + rand() % 26;
    return so;
}

inline int someObjectsCmp(some_object* so1, some_object* so2){
    int diff = so1 -> field_1 - so2->field_1;
    if(diff != 0)
        return diff;
    return so1->field_2 - so2->field_2;
}

inline void main_tests() {
    LinkedList<some_object *> ll;
    ll.addEnd(new some_object{5, 'a'});
    ll.addBegin(new some_object{1, 'i'});
    ll.addSorted(new some_object{0, 'b'}, someObjectsCmp);
    ll.addSorted(new some_object{3, 'z'}, someObjectsCmp);
    ll.addSorted(new some_object{2, 'y'}, someObjectsCmp);
    cout << ll.toString(10, someObjectToString) << endl;

    some_object * p = *ll.getAt(1);
    cout << "getAt(1) : " << someObjectToString(p) << endl << "getAt(99) : " << (ll.getAt(99) ? "found" : "nullptr") << endl;
    ll.setAt(0, new some_object{9, 'q'}, true);

    some_object search = {3, 'z'};
    cout << "find " << (ll.find(&search, someObjectsCmp) ? "yes" : "no") << endl;  
    
    cout << "findAndRemove: " << ll.findAndRemove(&search, someObjectsCmp, true) << ", again: " << ll.findAndRemove(&search, someObjectsCmp, true) << endl;
    ll.removeBeginElement(true);
    ll.removeLastElement(false);
    cout << ll.toString(10, someObjectToString) << endl;
    ll.clearList();
    cout << "list after clear: " << ll.toString() << endl;

}