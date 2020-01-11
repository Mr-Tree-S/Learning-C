#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,sum;
    sum=4;
    srand((unsigned)time(NULL));
    a=rand()%100;
    while(1) {
        sum--;
        printf("猜猜我的数字吧，0~100\n");

        scanf("%d",&b);
        if(a>b)
            printf("小了，还剩%d次机会\n",sum);
        if(a<b)
            printf("大了，还剩%d次机会\n",sum);
        if(a==b) {
            printf("恭喜，答对了\n");
            break;
        }
        
        if(sum==0) {
            printf("真不幸，机会用尽\n系统将在10秒后关机\n");
//            system("shutdown -s -t 10");
            break;
        }
    }
    return 0;
}



