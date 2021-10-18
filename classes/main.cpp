//
//  main.cpp
//  classes
//
//  Created by Михаил Козлов on 07.10.2021.
//

#include <iostream>
#include <string>
using namespace std;
struct aaa{
    int first;
    int second;
};
/*template <typename t>
void my_swap(t &a,t &b){
    t temp=b;
    b=a;
    a=temp;
}
template <class u,class f>
struct my_pair{
    u first;
    f second;
};*/
class Work{
    public:
    int hours;
    string name;
    virtual char* fff(){ return "aaa";}
    void set_name(string a){
        name=a;
    }
    void set_hours(int b){
        hours=b;
    }
    void print(){
        cout<<name<<" "<<hours<<endl;
    }
};
class Abc:public Work{
    public:
    char* fff(){ return "abcde";}
};
int main() {
    string name,name2;
    Abc ppp;
    Work &aabb=ppp;
    cout<<aabb.fff()<<endl;
}
