#include "stdvector.hpp"
stdvector::stdvector(int num,int val) {
    size = num;
    capacity = num+1;
    data= new double[capacity];
    for (int i = 0; i < size; ++i) data[i] = val;
}
unsigned int stdvector::get_size() {
    return this->size;
}
stdvector::stdvector(const stdvector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new double[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}
void stdvector::resize(int n_size) {
    size = n_size;
    set_cap(n_size+1);
}
void stdvector::set_cap(int n_cap) {
    double* n_s = new double[n_cap];
    for (int i = 0; i < std::min(n_cap, int(this->size)); ++i) {
        n_s[i] = this->data[i];
    }
    for (int i = this->size + 1; i < n_cap; ++i) {
        n_s[i] = 0;
    }
    capacity = n_cap;
    delete[] this->data;
    this->data = n_s;
     
}
stdvector& stdvector::operator=(const stdvector& v1) {
    if (this == &v1) return *this;
    this->size = v1.size;
    this->capacity = v1.capacity;
    delete[]this->data;
    data = new double[v1.capacity];
    for (int i = 0; i < size; ++i) {
        this->data[i] = v1.data[i];
    }
    return *this;
}
double& stdvector::operator [](int i) {
    return this->data[i];
}
void stdvector::push_back(int val) {
    if (capacity < size + 1) {
        this->set_cap((size + 1) * ch_size);
    }
    this->data[size] = val;
    size++;
}
double stdvector::pop_back(){
    size--;
    return data[size];
}
void stdvector::erase(int id){
    for(int i=id;i<size-1;++i){
        std::swap(data[i], data[i+1]);
    }
    size--;
}
void stdvector::insert(int id,int val){
    if (capacity < size + 1) {
        this->set_cap((size + 1) * ch_size);
    }
    double tmp=data[id];
    data[id]=val;
    for (int i=id+1;i<size+1;++i){
        std::swap(data[i], tmp);
    }
    size++;
}
void stdvector::push_front(int val){
    insert(0, val);
}
double stdvector::pop_front(){
    double tmp=a[0];
    erase(0);
    return tmp;
}
stdvector::~stdvector() {
    delete[] data;
}
