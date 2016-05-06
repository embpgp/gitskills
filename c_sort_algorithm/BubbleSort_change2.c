/*
*冒泡排序优化版2，记录每次交换的位置j-1,下一次排序直接从0~j-1开始 (树莓派 gcc)
*
*Copyright (C) 2016 
*
*2016 5 6
*
*GPL
*/

#include <stdio.h>

/*
*理论依据在于冒泡排序中，一旦发现某一趟排序没有进行交换，就说明此时待排序记录序列已经
*成为有序序列，再进行冒泡排序没有必要，应当立即结束整个排序过程,还有，同时记录第i趟冒泡排序随后一次
*发生交换的位置m(m<=n-i)，就会发现从此位置以后的记录均为有序序列，因此无序区缩小到了a[0]~a[m-1],然后
*再次进行排序时将尽可能优化算法
*/
void BubbleSort(int *array, int length)
{
	int exchange = 0;
	int i = 0,j = 0;
	int temp;
	int last = length-1;//下标
	int m;
	for(i = length-1; i>0; --i)
	{
		exchange = 0;
		m = last;
		for(j = 0; j<=m; ++j)
			{
				if(array[j+1] < array[j])
					{
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
						exchange = 1;
						last = j;
					}
			}
		if(exchange == 0)
			{
				break;    //直接退出整个排序过程
			}
	}
	
}

int main(void)
{
	int i;
	int a[] = {23,45,5,76,34,56,78,987,23,43};
	int length = 10;
	printf("排序之前:\n");
	for(i = 0; i<10; ++i)
	{
		printf("%d  ",a[i]); 
	}
	BubbleSort(a, length);
	printf("\n排序之后:\n");
	for(i = 0; i<10; ++i)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
