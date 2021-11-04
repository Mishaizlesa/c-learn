#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string x;
    int x1;
    int mmax=0;
    bool f=false;
    bool f1;
    while(!f){
        cout<<"введите кол-во чисел в последовательности: "; cin>>n;
        f1=true;
        for(int i=0;i<n;++i){
            cin>>x;
            for (auto v:x){
                if(!isdigit(v)){
                    f1=false;
                    break;
                }
            }
            
            if (f1){
                x1=stoi(x);
                if (x1>mmax) mmax=x1;
            }
            if (i==n-1 && f1) f=true;
        }
    }
    cout<<mmax<<endl;
}
