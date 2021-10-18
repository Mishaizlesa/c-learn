#include <iostream>
#include "mymath.h"
int main() {
    int choose=0;
    int n=0;
    double x,eps;
    x=-10000;
    while(!(choose>0 && choose<6)){
        printf("select the function\n1 exp(x)\n2 cos(x)\n3 sin(x)\n4 arcsin(x)\n5 arccos(x)\n");
        scanf("%d",&choose);
    }
    printf("x=");scanf("%lf",&x);
    printf("eps=");scanf("%lf",&eps);
    if (choose==1) printf("exp(x)=%lf\nnumberrrr of iterations=%d\n",my_exp(x, eps, n),n);
    if (choose==2) printf("cos(x)=%lf\nnumber of iterations=%d\n",my_cos(x, eps, n),n);
    if (choose==3) printf("sin(x)=%lf\nnumber of iterations=%d\n",my_sin(x, eps, n),n);
    if (choose==4) {
        while(abs(x)>1){
            if (abs(x)>1) printf("incorrect value of x\n");
            printf("x=");scanf("%lf",&x);
            printf("eps=");scanf("%lf",&eps);
        }
        printf("arcsin(x)=%lf\nnumber of iterations=%d\n",my_arcsin(x, eps, n),n);
    }
    if (choose==5){
        while(abs(x)>1){
            if (abs(x)>1) printf("incorrect value of x\n");
            printf("x=");scanf("%lf",&x);
            printf("eps=");scanf("%lf",&eps);
        }
        printf("arccos(x)=%lf\nnumber of iterations=%d\n",my_arccos(x, eps, n),n);
    }
}
