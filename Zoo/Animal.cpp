#include "Animal.hpp"
Animal::Animal(const std::string& x){
    name=x;
    id=nn++;
}
std::string Animal::get_name(){
    return name;
}
int Animal::get_id(){
    return id;
}
void Dog::say(){std::cout<<"Dog says 'woof-woof!'\n";}
void Cat::say(){std::cout<<"Cat says 'meow'\n";}
void Fox::say(){std::cout<<"Dog says 'what does the fox say?'\n";}
void Cock::say(){std::cout<<"Cock says 'cook a rook a roo'\n";}
void Sparrow::say(){std::cout<<"Sparrow is tweeting\n";}
