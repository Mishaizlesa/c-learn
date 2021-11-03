#include <stdio.h>
#include <stdlib.h>
int main() {
    char** w;
    w=new char*[30];
    int k=2;
    for (int i=0;i<k;i++) w[i]= new char[30];
    int c=0;
    while(1){
        if (c==k){
            printf("переполнение\n");
            for (int i=k;i<2*k;i++) w[i]= new char[30];
            k=c*2;
        }
        scanf("%s",w[c]);
        c++;
    }
    return 0;
}
