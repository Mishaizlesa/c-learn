#include "zoo.hpp"
void Zoo::listen(){
    for(auto el: zoo_arr) el->say();
}
void Zoo::ins(Animal* x){zoo_arr.push_back(x);}
void Zoo::del(const int id_del){
    for(int i=0;i<zoo_arr.size();++i){
        if (zoo_arr[i]->get_id()==id_del){
            zoo_arr.erase(zoo_arr.begin()+i);
        }
    }
}
int Zoo::num_birds(){
    int res=0;
    for(int i=0;i<zoo_arr.size();++i){
        Animal* p=dynamic_cast<Bird*>(zoo_arr[i]);
        if (p) res++;
    }
    return res;
}
