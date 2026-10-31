// #include <iostream>
// #include "some_object.h"

// int some_objects_cmp(some_object* so1, some_object* so2){
//     int diff = so1 -> field_1 - so2->field_1;
//     if(diff != 0)
//         return diff;
//     return so1->field_2 - so2->field_2;
// }
// int main(){
//     return 0;
// }


// #include <time.h>
// #include <iostream>

// int main() {
//     clock_t t1 = clock();
//     clock_t t2 = clock();
//     double time = (t2 - t1) / (double)CLOCKS_PER_SEC;
//     std::cout << time << std::endl;
//     return 0;
// }




/*
...
linked_list<some_object>* ll = new linked_list<some_object>();
some_object so;
so.field_1 = 123;
so.field_2 = 'a';
ll->add(so);
...
delete ll;
...
*/


/*
linked_list<some_object>* ll1 = new linked_list<some_object>();
linked_list<some_object*>* ll2 = new linked_list<some_object*>();
*/

// int main()
//     {
//     const int MAX_ORDER = 6; // maksymalny rzad wielkosci rozmiaru dodawanych danych
//     linked_list <some_object *>* ll = new linked_list <some_object *>(); // stworzenie listy
//     for (int o = 1; o <= MAX_ORDER; o++) // petla po kolejnych rzedach wielkosci
//     {
//     const int n = pow(10, o); // rozmiar danych
//     // dodawanie do listy
//     clock_t t1 = clock();
//     for (int i = 0; i < n; i++) {
//     some_object* so = ... // losowe dane
//     ll->add(so);
//     }
//     clock_t t2 = clock();
//     ... // wypis na ekran aktualnej postaci listy (skrotowej ) i pomiarow czasowych
//     // wyszukiwanie i usuwanie z listy
//     const int m = pow(10, 4); // liczba prob wyszukania
//     t1 = clock();
//     for (int i = 0; i < m; i++) {
//     some_object* so = ... // losowe dane jako wzorzec do wyszukiwania (obiekt chwilowy)
//     ll->find_and_remove(so, some_objects_cmp);
//     delete so;
//     }
//     t2 = clock();
//     ... // wypis na ekran aktualnej postaci listy (skrotowej ) i pomiarow czasowych
//     ll->clear(true); // czyszczenie listy wraz z uwalnianiem pamieci danych
//     }
//     delete ll;
//     return 0;
// }

#include "./linked_list.h"
#include <string>

std::string intToString(int whatever){
    return std::to_string(whatever);
} 

int main() {


    LinkedList<int> * ll = new LinkedList<int>();

    ll->addBegin(5);
    ll->addBegin(8);
    ll->addBegin(10);
    ll->addBegin(101);

    ll->showFromBegin();
    cout << ll ->toString(intToString) << endl;
    ll->removeBeginElement();
    cout << ll ->toString(intToString) << endl;
    ll->removeLastElement();
    cout << ll ->toString(intToString) << endl;

    delete ll;

}