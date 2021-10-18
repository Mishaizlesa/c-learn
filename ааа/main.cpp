#include <iostream>
using namespace std;
class BaseMonster {
public:
     BaseMonster(){
         cout<<"Атакуют все монстры"<<endl;
    }
     ~BaseMonster(){
         cout<<"Переместились все монстры"<<endl;
    }
};
class MonsterA : public BaseMonster{
public:
    MonsterA(){
        cout<<"Монстр A атакует"<<endl;
    }
    ~MonsterA(){
        cout<<"Монстр A двигается"<<endl;
    }

};
class MonsterB : public MonsterA{
public:
    MonsterB(){
        cout<<"Монстр B атакует"<<endl;
    }
    ~MonsterB(){
        cout<<"Монстр B двигается"<<endl;
    }
};
class MonsterC : public MonsterB{
public:
    MonsterC(){
        cout<<"Монстр C атакует"<<endl;
    }
    ~MonsterC(){
        cout<<"Монстр C двигается"<<endl;
    }
};
int main(){
    setlocale(LC_ALL, "Russian");
    MonsterC C;
    return 0;
}
