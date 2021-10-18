#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//int bin_ten(char *value);
char *ten_bin(int value){//перевод из десятичной в двоичную
    int c;
    char ans[100];
    c=0;
    if (value==0) ans[0]='0';
    while (value!=0){
        ans[c]=value%2+'0';
        value=value/2;
        c++;
    }
    char temp;
    for(int i=0;i<c/2;i++){
        temp=ans[i];
        ans[i]=ans[c-i-1];
        ans[c-i-1]=temp;
        printf("%s",ans);
    }
    return ans;
}
int bin_ten(char value[]){// перевод из двоичной в десятичную
    int num=0;
    int lenght=0;
    while(value[lenght]){
        lenght++;
    }
    for (int i=0;i<lenght;++i){
        if (value[i]!='0'){
            num=num+pow(2,lenght-i-1);
        }
    }
    return num;
}
char *add(char value1[],char value2[]){
    int v1=bin_ten(value1);
    int v2=bin_ten(value2);
    int res=v1+v2;
    return ten_bin(res);
}
char *sub(char value1[],char value2[]){
    int v1=bin_ten(value1);
    int v2=bin_ten(value2);
    int res=v1-v2;
    res=abs(res);
    return ten_bin(res);
}
char *mult(char value1[],char value2[]){
    int v1=bin_ten(value1);
    int v2=bin_ten(value2);
    int res=v1*v2;
    return ten_bin(res);
}
int main(){
    while (1){
        int m,n;
        printf("M= ");
        scanf("%d",&m);
        printf("N= ");
        scanf("%d",&n);
        printf("%d в двоичной = ",m);
        char *otw;
        otw=ten_bin(m);
        printf("%s\n",otw);
        printf("%d в двоичной = %s\n",n,ten_bin(n));
        printf("|m-n| в двоичной = %s\n",sub(ten_bin(m),ten_bin(n)));
        printf("m+n в двоичной = %s\n",add(ten_bin(m),ten_bin(n)));
        printf("|m*n| в двоичной = %s\n",mult(ten_bin(m),ten_bin(n)));
        char *per;
        per = (char*)malloc(32 * sizeof(char));
        printf("введите число в двоичной системе для перевода: ");
        scanf("%s",&*per);
        printf("число в десятичной системе: %d\n",bin_ten(per));
        int f;
        printf("введите 1, если хотите продолжить, иначе - 0: ");
        scanf("%d",&f);
        if (f==0) break;
    }
}
