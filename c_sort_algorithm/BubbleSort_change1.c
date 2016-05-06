#include <stdio.h>

/*
*理论依据在于冒泡排序中，一旦发现某一趟排序没有进行交换，就说明此时待排序记录序列已经
*成为有序序列，再进行冒泡排序没有必要，应当立即结束整个排序过程
*
*/
void BubbleSort(int *array, int length)
{
	int exchange = 0;
	int i = 0,j = 0;
	int temp;
	for(i = length-1; i>0; --i)
	{
		for(j = 0; j<=i-1; ++j)
			{
				if(array[j+1] < array[j])
					{
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
						exchange = 1;
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
