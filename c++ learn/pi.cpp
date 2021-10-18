#include <stdio.h>
#include <math.h>
/*void p4(){
    double eps;
    printf("введите eps для pi/4: ");
    scanf("%lf",&eps);
    double ans=0;
    for (int n=0;n<1/eps;n++){
        if (n%2==1) ans-=(1/(2*(double)n+1));
        else ans+=(1/(2*(double)n+1));
    }
    printf("pi/4 ~ %lf\n",ans);
}
void p2(){
    double eps;
    printf("введите eps для pi/2: ");
    scanf("%lf",&eps);
    double ans=1;
    for (int n=1;n<1/eps+1;n++){
        ans*=(double)(n*n)*4/(double)((2*n-1)*(2*n+1));
    }
    printf("pi/2 ~ %lf\n",ans);
}
int main() {
    while(1){
        p4();
        p2();
        int f;
        printf("введите 1, если хотите продолжить, иначе - 0: ");
        scanf("%d",&f);
        if (!f) break;
    }
}
int main(){
    int i=0;
    for (int i=0;i<50;i++){
        if (i%2==1) continue;
        printf("%d\n",i);
    }
}*/
#include <stdio.h>
#include <math.h>
#include<locale.h>
void p4()
{
    setlocale(LC_ALL,"Rus");
    double eps;
    printf("‚‚Â‰ËÚÂ eps ‰Îˇ pi/4: ");
    scanf("%lf", &eps);
    double ans = 0;
    for (int n = 0; n < 1 / eps; n++)
    {
        if (n % 2 == 1) ans -= (1 / (2 * (double)n + 1));
        else ans += (1 / (2 * (double)n + 1));
    }
    printf("pi/4 ~ %lf\n", ans);
}
void p2() {
    double eps;
    printf("‚‚Â‰ËÚÂ eps ‰Îˇ pi/2: ");
    scanf("%lf", &eps);
    double ans = 1;
    for (double n = 1; n < 1 / eps + 1; n++)
    {
        ans *= (double)(n * n) * 4 / (double)((2 * n - 1) * (2 * n + 1));
    }
    printf("pi/2 ~ %lf\n", ans);
}
int main()
{
    while (1)
    {
        p4();
        p2();
        int f;
        printf("‚‚Â‰ËÚÂ 1, ÂÒÎË ıÓÚËÚÂ ÔÓ‰ÓÎÊËÚ¸, ËÌ‡˜Â - 0: ");
        scanf("%d", &f);
        if (!f) break;
    }
}
