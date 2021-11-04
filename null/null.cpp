#include <stdio.h>
int main() {
    int n;
    int ch[10000];
    printf("введите количество чисел: ");scanf("%d",&n);
    int x;
    int count=0;
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if(x==0) continue;
        ch[count]=x;
        count++;
    }
    for (int i=0;i<count;++i){
        printf("%d ",ch[i]);
    }
    printf("\n");
    return 0;
}
