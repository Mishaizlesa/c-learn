#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
char text[1000][1000];
void process_char(char c,int *arr,int &mmax){
   c=tolower(c);
   if(c-'a'>-1 && c-'a'<26){
       arr[c-'a']++;
       if (arr[c-'a']>mmax) mmax=arr[c-'a'];
   }
}
void print_b(){
    for(int i=0;i<26;++i) printf("%c ",'a'+i);
}
void print_hist(int *kol,int mmax){
    for(int i=mmax;i>0;--i){
        for(int j=0;j<26;++j){
            if (kol[j]>=i) printf("| ");
            else printf("  ");
        }
        printf("\n");
    }
}
int main(){
    int kol[26]={0};
    int mmax=-1000;
    char c,prev;
    prev='b';
    printf("введите текст:\n");
    int count=0;
    while(1){
        char *txt=text[count];
        gets(txt);
        if (!txt[0])break;
        else process_char(txt[0], kol, mmax);
        prev=txt[0];
        for(int i=0;txt[i];i++){
            c=txt[i];
            if (prev==' ' ||prev=='\n'|| prev=='\"'||prev=='\t' || prev=='('){
                process_char(c,kol,mmax);
            }
            prev=c;
        }
        count++;
    }
    print_hist(kol,mmax);
    print_b();
    return 0;
}
