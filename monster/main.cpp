#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
    int x;
    srand(time(NULL));
    int ch=rand()%100+1;
    while(1){
        printf("введите число: ");
        scanf("%d",&x);
        if (x>ch) printf("число слишком большое\n");
        if (x<ch) printf("число слишком маленькое\n");
        if (x==ch){
            printf("Вы угадали!\n");
            return 0;
        }
    }
}
