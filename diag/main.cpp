#include <iostream>
#include <algorithm>
using namespace std;
int mat[1000][1000];
//int mat1[1000][1000];
pair<int,int> mmax[1000];
bool f(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
int main(){
    int n,m;
    cout<<"введите кол-во строк: ";
    cin>>n;
    cout<<"введите кол-во столбцов: ";
    cin>>m;
    for(int i=0;i<m;++i){
        mmax[i].first=-1e7;
    }
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
            //mat1[i][j]=mat[i][j];
            mmax[j].second=j;
            if (mat[i][j]>mmax[j].first) mmax[j].first=mat[i][j];
        }
    }
    sort(mmax,mmax+m,f);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout<<mat[i][mmax[j].second]<<" ";
        }
        cout<<endl;
    }
    //for (int i=0;i<n;++i){
        //for (int j=0;j<m;++j){
            //cout<<mat[i][j]<<" ";
        //}
        //cout<<endl;
    //}
}
