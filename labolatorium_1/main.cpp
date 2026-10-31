#include <iostream>
#include "some_object.h"

int some_objects_cmp(some_object* so1, some_object* so2){
    int diff = so1 -> field_1 - so2->field_1;
    if(diff != 0)
        return diff;
    return so1->field_2 - so2->field_2;
}
int main(){
    return 0;
}