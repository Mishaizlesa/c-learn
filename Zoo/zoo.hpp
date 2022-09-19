#ifndef zoo_hpp
#define zoo_hpp

#include "Animal.hpp"
#include <vector>
class Zoo{
public:
    std::vector<Animal*>zoo_arr;
    void listen();
    void ins(Animal* x);
    void del (const int id_del);
    int num_birds();
};
#endif /* zoo_hpp */
