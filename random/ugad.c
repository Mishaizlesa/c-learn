#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
    srand(time(NULL));
    int x;
    int ch=rand()%100+1;
    int count=0;
    while(1){
        printf("введите число: ");
        scanf("%d",&x);
        count++;
        if (x>ch) printf("число слишком большое\n");
        if (x<ch) printf("число слишком маленькое\n");
        if (x==ch){
            printf("Вы угадали!\n");
            break;
        }
    }
    printf("число попыток: %d\n",count);
}
