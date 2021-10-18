#include <stdio.h>
int main() {
    char c,p;
    printf("символ: ");
    scanf("%c\n",&p);
    int count=0;
    int count_char=0;
    while((c=getchar())!='.'){
        if (c!='\n') count++;
        if (c==p) count_char++;
    }
    printf("всего символов: %d\nсимвол %c встречается %d раз\n",count,p,count_char);
}
