#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void fill(int **matr,int n,int m){
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            matr[i][j]=rand()%1000;
        }
    }
}
void nill(int **matr,int n,int m){
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            matr[i][j]=0;
        }
    }
}
void fr(int **matr,int n){
    for (int i=0;i<n;++i) free(matr[i]);
    free(matr);
}
void solve(int n1,int m1,int n2,int m2){
    int **matr1,**matr2,**res;
    matr1=(int**)malloc(n1*sizeof(int*));
    for (int i=0;i<n1;++i) matr1[i]=(int*)malloc(m1*sizeof(int));
    matr2=(int**)malloc(n2*sizeof(int*));
    for (int i=0;i<n2;++i) matr2[i]=(int*)malloc(m2*sizeof(int));
    res=(int**)malloc(n1*sizeof(int*));
    for (int i=0;i<n1;++i) res[i]=(int*)malloc(m2*sizeof(int));
    fill(matr1, n1, m1);
    fill(matr2, n2, m2);
    double a=clock();
    for (int i=0;i<n1;++i){
        for (int j=0;j<m2;++j){
            for(int k=0;k<m1;++k){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("1 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    nill(res,n1,m1);
    a=clock();
    for (int j=0;j<m2;++j){
        for (int i=0;i<n1;++i){
            for(int k=0;k<m1;++k){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("2 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    nill(res,n1,m1);
    a=clock();
    for (int i=0;i<n1;++i){
        for (int k=0;k<m1;++k){
            for(int j=0;j<m2;++j){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("3 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    nill(res,n1,m1);
    a=clock();
    for (int k=0;k<m1;++k){
        for (int i=0;i<n1;++i){
            for(int j=0;j<m2;++j){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("4 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    nill(res,n1,m1);
    a=clock();
    for (int k=0;k<m1;++k){
        for (int j=0;j<m2;++j){
            for(int i=0;i<n1;++i){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("5 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    nill(res,n1,m1);
    a=clock();
    for (int j=0;j<m2;++j){
        for (int k=0;k<m1;++k){
            for(int i=0;i<n1;++i){
                res[i][j]+=matr1[i][k]*matr2[k][j];
            }
        }
    }
    printf("6 order %d size - %.3lfs\n",n1,(clock()-a)/1e6);
    fr(matr1,m1);
    fr(matr2,m1);
    fr(res,m1);
}
int main() {
    srand(time(NULL));
    for (int i=1000;i<=3000;i+=1000) {
        solve(i,i,i,i);
        printf("\n-------------------------------\n\n");
    }
}
