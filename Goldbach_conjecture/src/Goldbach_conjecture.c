#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,i,j,count1,count2,m,n;
    for(a=4;a<=100;a=a+2) {
        
        for(i=2;i<=a/2;i++) {
            count1=0;
            for(m=2;m<=i-1;m++) {
                if(i%m==0) {
                    count1++;
                    break;
                }
            }
            if(count1==0){
                j=a-i;
                count2=0;
                for(n=2;n<=j-1;n++) {
                    if(j%n==0) {
                        count2++;
                        break;
                    }
                }
                if(count2==0) {
                        printf("%d=%d+%d\n",a,i,j);
                        break;
                }
            }
        }
    }

    return 0;
}


