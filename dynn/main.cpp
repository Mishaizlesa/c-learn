#include <stdio.h>
#include <stdlib.h>
int main() {
    char** w=(char**)malloc(2*sizeof(char*));for(int i=0;i<2;++i) w[i]=(char*)malloc(100*sizeof(char));
    int k=2;
    int c=0;
    while(1){
        if (c==k){
            printf("переполнение\n");
            char** tmp=(char**)malloc(k*2*sizeof(char*));for(int i=0;i<k*2;++i) tmp[i]=(char*)malloc(100*sizeof(char));
            for (int i=0;i<k;++i)for(int j=0;j<100;++j)tmp[i][j]=w[i][j];
            for(int i=0;i<k;++i) free(w[i]);
            free(w);
            w=tmp;
            k=c*2;
        }
        scanf("%s",w[c]);
        c++;
    }
    return 0;
}
