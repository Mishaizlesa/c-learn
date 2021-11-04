#include <stdio.h>
int main(int argc, const char * argv[]) {
    double matr[1000][1000];
    double mean[1000];
    int n,m;
    printf("введите кол-во строк: ");scanf("%d",&n);
    printf("введите кол-во столбцов: ");scanf("%d",&m);
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%lf",&matr[i][j]);
            mean[j]+=matr[i][j];
        }
    }
    for(int i=0;i<m;++i) mean[i]/=n;
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            matr[i][j]-=mean[j];
            printf("%.3lf ",matr[i][j]);
        }
        printf("\n");
    }
}
