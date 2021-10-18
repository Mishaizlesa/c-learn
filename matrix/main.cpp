#include <iostream>

using namespace std;

int main(){
    double x,y,x1,y1,x2,y2,x3,y3;
    cout<<"x=";
    cin>>x;
    cout<<"y=";
    cin>>y;
    cout<<"x1=";
    cin>>x1;
    cout<<"y1=";
    cin>>y1;
    cout<<"x2=";
    cin>>x2;
    cout<<"y2=";
    cin>>y2;
    cout<<"x3=";
    cin>>x3;
    cout<<"y3=";
    cin>>y3;
    double res1,res2,res3;
    res1=(x1-x)*(y2-y1)-(x2-x1)*(y1-y);
    res2=(x2-x)*(y3-y2)-(x3-x2)*(y2-y);
    res3=(x3-x)*(y1-y3)-(x1-x3)*(y3-y);
    bool f1=((res1<0 && res2<0 && res3<0) ||(res1>0 && res2>0 && res3>0));
    if (f1){
        cout<<"точка лежит в треугольнике";
        return 0;
    }
    int a=((res1==0) + (res2==0) +(res3==0));
    if (a>=1){
        if (a==2){
            cout<<"точка лежит в треугольнике"<<endl;
            return 0;
        }
        if (res1==0){
            if ((res2<0 && res3<0) ||(res2>0 && res3>0)){
                cout<<"точка лежит в треугольнике"<<endl;
                return 0;
            }
        }
        if (res2==0){
            if ((res1<0 && res3<0) ||(res1>0 && res3>0)){
                cout<<"точка лежит в треугольнике"<<endl;
                return 0;
            }
        }
        if (res3==0){
            if ((res1<0 && res2<0) ||(res1>0 && res2>0)){
                cout<<"точка лежит в треугольнике"<<endl;
                return 0;
            }
        }
    }
    cout<<"точка не лежит в треугольнике"<<endl;
}

