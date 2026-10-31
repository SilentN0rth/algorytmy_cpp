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


#include <time.h>
#include <iostream>

int main() {
    clock_t t1 = clock();
    clock_t t2 = clock();
    double time = (t2 - t1) / (double)CLOCKS_PER_SEC;
    std::cout << time << std::endl;
    return 0;
}