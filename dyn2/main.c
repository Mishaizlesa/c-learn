#include <stdio.h>
#include <stdlib.h>
int main() {
    char** w;
    char **tmp;
    int k=2;
    for (int i=0;i<k;i++) w[i]= new char[30];
    int c=0;
    while(1){
        if (c==k){
            printf("переполнение\n");
            tmp=w;
            //w=(char*)malloc(30*2*k*sizeof(char));
            k=c*2;
            for (int i=0;i<k;++i) for(int j=0;j<30;++j) w[i][j]=tmp[i][j];
        }
        scanf("%s",w[c]);
        c++;
    }
    return 0;
}
