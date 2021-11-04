#include <stdio.h>
struct w{
    char str[30];
    int len;
};
char post[1000][5];
char text1[1000][1000];
int podr=0;
w text[1000];
int count=0;
int i=0;
int sum=0;
char c,prev;
int cnt=0;
void process_word(){
    if (i==0){
        podr++;
        post[count-1][podr]=c;
        return;
    }
    podr=0;
    post[count][0]=c;
    text[count].len=i;
    sum+=i;
    i=0;
    count++;
}
void print_text(){
    double mean = double(sum)/double(count);
    for (int i=0;i<count;++i){
        if (text[i].len>mean) printf("(%s)%s",text[i].str,post[i]);
        else printf("%s%s",text[i].str,post[i]);
    }
}
int check_char(char c){
    return c=='\n'|| c=='.'|| c=='!'|| c=='?'|| c==' '||c=='\t'||c==','||c==':'||c=='\"';
}
int main(){
    while(1){
        char *txt=text1[cnt];
        gets(txt);
        if (!txt[0])break;
        for(int j=0;txt[j];j++){
            c=txt[j];
            if (check_char(c)){
                process_word();
                continue;
            }
            text[count].str[i]=c;
            i++;
        }
        c='\n';
        process_word();
    }
    print_text();
}
