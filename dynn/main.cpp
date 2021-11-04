#include <stdio.h>
#include <stdlib.h>
int main() {
    char** w;
    char** tmp;
    w=(char**)malloc(2*sizeof(char*));
    tmp=(char**)malloc(2*sizeof(char*));
    for(int i=0;i<2;++i) w[i]=(char*)malloc(100*sizeof(char));
    for(int i=0;i<2;++i) tmp[i]=(char*)malloc(100*sizeof(char));
    int k=2;
    int c=0;
    while(1){
        if (c==k){
            printf("переполнение\n");
            tmp=w;
            w=(char**)malloc(k*2*sizeof(char*));
            for(int i=0;i<k*2;++i) w[i]=(char*)malloc(100*sizeof(char));
            for(int i=0;i<k;++i) w[i]=tmp[i];
            for(int i=0;i<k*2;++i) tmp[i]=(char*)malloc(100*sizeof(char));
            k=c*2;
        }
        scanf("%s",w[c]);
        c++;
    }
    return 0;
}
