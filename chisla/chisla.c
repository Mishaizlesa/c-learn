#include <stdio.h>
int main() {
    float sum=0;
    float count=0;
    double x;
    while(1){
        scanf("%lf",&x);
        if (x==0) break;
        sum+=x;
        count++;
    }
    printf("количество чисел: %d\nсумма чисел: %d\nсреднее арифметическое: %.3f\n",(int)count,(int)sum,sum/count);
}
