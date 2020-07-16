#include <stdio.h>
#include <stdlib.h>

typedef struct linelist {
	int start;
	int end;
	int len;
}List;

List *create_list(int len)
{
	List *pList = (List*)malloc(sizeof(List)*len);
	pList->len = len;
	return pList;
}

int del_node(List *pList, int number)
{
	int n = number;
	if (n < 0 || n > pList->len)
		return -1;
	for (int i = n; i < pList->len; i++) {
		pList[i]->start = pList[i+1]->start;
		pList[i]->end = pList[i+1]->end;
	}
	pList->len--;
	return pList->len;
}

int repeat(Interval a, Interval b)
{
	if (a.start <= b.start && a.end >= b.start)
		return 1;
	return 0;
}


int Combine(Interval *p, int len)
{
    int cnt=0;//cnt记录区间数量

    if (len == 1)
		return 1;//如果只有一个区间，直接返回
    for (int i = 0; i < len-1;) {
        if (repeat(p[i], p[i+1]))//如果重合
        {
            p[cnt].start=in[i].start;
            output[cnt].end=(in[i+1].end>in[i].end)?in[i+1].end:in[i].end;//对于2种情况进行分类
            i+=2;
            cnt++;
            if(i==len-1)//如果合并后i指向最后一个区间
            {
                output[cnt].start=in[i].start;
                output[cnt].end=in[i].end;
                i++;
                cnt++;
            }
        }
        else//如果不重合
        {
            if(i==len-2)//如果倒数第二个和倒数第一个不能重合
            {
                output[cnt].start=in[i].start;
                output[cnt].end=in[i].end;
                output[cnt+1].start=in[i+1].start;
                output[cnt+1].end=in[i+1].end;
                i++;
                cnt+=2;
            }
            else
            {
                output[cnt].start=in[i].start;
                output[cnt].end=in[i].end;
                i++;
                cnt++;
            }
        }
    }
    Print_Result(cnt);
    return cnt;
}

int main()
{
	int len;
	scanf("%d", &len);
	List *input = create_list(len);

	int i;
	for (i = 0; i < len; i++)
		scanf("%d %d", &input[i].start, &input[i].end);

	List *sum = create_list(len);
	for (i = 0; i < len; i++) {
		sum[i].start = input[i].start;
		sum[i].end = input[i].end;
	}

	for (i = 0; i < len; i++)
		printf("%d %d\n", sum[i].start, sum[i].end);
/*
	int last_n = LEN;
	int n = LEN;
	do {
		last_n = n;
		n = Combine(sum, last_n);
	}while(n != last_n);
*/


	return 0;
}
