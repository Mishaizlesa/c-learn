#include <iostream>
#include "MyVector.h"
int main(){
    Vector a({1,2,3});
    Vector b({3,4,6});
    Vector c=a+b;
    std::cout<<c[1];
}
