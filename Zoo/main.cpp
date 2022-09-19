#include <iostream>
#include "Animal.hpp"
#include "zoo.hpp"
int Animal::nn=0;
int main() {
    Cock a("petuch");
    Dog  b("sharik");
    Zoo new_zoo;
    new_zoo.ins(&a);
    new_zoo.ins(&b);
    new_zoo.listen();
    std::cout<<new_zoo.num_birds();
    
}
