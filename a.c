#include <stdio.h>
#include <string.h>

#define error 4


void wait(int minute)
{
    sleep minute;
}


int main()
{
    char key_1="花开富贵 客厅画";
    char par_1="牡丹";
    char key_2="北欧抽象壁画";

    search key_1;           // 搜索关键词1
    find par_1;             // 找到描述1
    wait(2);                // 等待两分钟
    add_shopping_cart(1);   // 加入购物车

    search key_2;
    wait(2);
    add_shopping_cart(2);   // 加入购物车两件

    if(amount >= 1000) {
        printf("有钱有钱！对喽！");
    }else{
        printf("好像有点问题！");
        return error;
    }

    add_coupon(50);         // 领取50优惠券

    BUY;                    // 买 买 买
    return 0;
}
