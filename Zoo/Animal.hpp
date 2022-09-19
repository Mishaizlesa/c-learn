#ifndef Animal_hpp
#define Animal_hpp
#include <iostream>
#include <string>
class Animal{
public:
    static int nn;
    Animal(const std::string& x);
    virtual void say()=0;
    std::string get_name();
    int get_id();
protected:
    std::string name;
    int id;
};
class Mammal: public Animal{
public:
    Mammal(const std::string& x):Animal(x){};
};
class Bird:public Animal{
public:
    Bird(const std::string& x):Animal(x){};
};
class Dog:public Mammal{
public:
    Dog(const std::string& x): Mammal(x){};
    void say();
};
class Cat:public Mammal{
public:
    Cat(const std::string& x): Mammal(x){};
    void say();
};
class Fox:public Mammal{
public:
    Fox(const std::string& x): Mammal(x){};
    void say();
};
class Cock:public Bird{
public:
    Cock(const std::string& x): Bird(x){};
    void say();
};
class Sparrow:public Bird{
public:
    Sparrow(const std::string& x): Bird(x){};
    void say();
};
#endif /* Animal_hpp */
