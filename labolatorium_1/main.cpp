// #include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "linked_list.h"
#include "some_object.h"

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


void report(const char * name, clock_t t1, clock_t t2, int operations){
    double total = (t2 - t1) / (double)CLOCKS_PER_SEC;
    cout << " " << name << ": total " << total << " s, average " << total / operations * 1e6 << " us/op (mikrosekund na operacje) " << endl;
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
    ll.removeLastElement(true);
    cout << ll.toString(10, someObjectToString) << endl;
    ll.clearList(true);
    cout << "list after clear: " << ll.toString() << endl;

}

int main() {
    srand((unsigned)time(nullptr));
    main_tests();

    const int MAX = 7;
    
    LinkedList<some_object *> * ll = new LinkedList<some_object *>();
    for (int i = 1; i <= MAX; i++) {
        const int n = (int)pow(10, i);
        cout << "n = " << n << endl;

        clock_t t1 = clock();
        for(int j= 0; j < n; j++){
            ll -> addEnd(randomObject());
        }
        clock_t t2 = clock();
        report("add", t1, t2, n);
        cout << "  " << ll -> toString(5, someObjectToString) << endl;

        const int m = (int)pow(10,4);
        t1 = clock();
        for(int j = 0; j < m; j++){
            some_object * so = randomObject();
            ll -> findAndRemove(so, someObjectsCmp, true);
            delete so;
        }
        t2 = clock();
        report("findAndRemove", t1, t2, m);
        cout << "  " << ll->toString(5, someObjectToString) << endl;
        ll -> clearList(true);
    }
    delete ll;
}