#pragma once
#include<algorithm>
 
#include <cmath>
class stdvector {
private:
    unsigned int size = 0;
    double* data = nullptr;
    unsigned int capacity=0;
    const int ch_size=2;
public:
    stdvector(int num = 0,int val=0);
    stdvector(const stdvector& other);
    void resize(int n_size);
    void set_cap(int n_cap);
    stdvector& operator=(const stdvector& v1);
    unsigned int get_size();
    double& operator [](int i);
    void push_back(int val);
    int pop_back();
    ~stdvector();
};
