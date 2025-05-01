#include <iostream>
#include "arrayInt.h"

int main(){
    ArrayInt arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    
    ArrayInt new_array(2);
    new_array.add_element(44); 
    new_array.add_element(34);
    
    arr = new_array;
}
