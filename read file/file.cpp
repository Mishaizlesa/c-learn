#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class files{
    public:
    vector<int>x;
    vector<int>y;
    vector<int>z;
    int minx,miny,minz,idx,idy,idz;
    void readx(){
        ifstream file;
        file.open("\\Users\\mihailkozlov\\Desktop\\learn\\c++ learn\\read file\\en.lproj\\xfile.txt");
        if (!file) cout<<"!";
        int xi;
        while(file>>xi){
            x.push_back(xi);
            cout<<xi<<endl;
        }
    }
};
int main() {
    files a;
    a.readx();
    return 0;
}
