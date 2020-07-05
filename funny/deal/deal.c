/*
明明想在学校中请一些同学一起做一项问卷调查，
为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
对于其中重复的数字，只保留一个，把其余相同的数去掉，
不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
按照排好的顺序去找同学做调查。
请你协助明明完成“去重”与“排序”的工作
(同一个测试用例里可能会有多组数据，希望大家能正确处理)。
*/

#include <stdio.h>


int a[1000] = {0};
int b[1000] = {0};

int inarray()
{
	int n;
	int i = 0;
	while (~scanf("%d",&n) && n != 0) {
		a[i] = n;
//		printf("%d\n", a[i]);
//		printf("%d\n", i);
		i++;
	}
	return 0;
}

int deal()
{
	int j = 0;
	while (a[j] && j < 1000) {
		b[a[j]]++;
//		printf("%d\n", a[j]);
		j++;
	}
	return 0;
}

int outarray()
{
	int k;
	for (k=0; k<1000; k++) {
		if (b[k] != 0)
		printf("%d\n", k);
	}
	return 0;
}

int main()
{
	inarray();

	deal();

	outarray();

	return 0;
}
