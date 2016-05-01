#include <stdio.h>

void InsertSort(int *array, int length )
{
	int i = 0,j = 0;
	int temp;
	int low,high;
	int mid;
	for(i = 1; i<length; ++i)
	{
		temp = array[i];
		low = 0;
		high = i-1;
		while(low <= high)    //查找插入的位置
		{
			mid = (low + high)/2;
			if(temp < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for(j=i-1;j >=high+1;--j)
		{
			array[j+1] = array[j];
		}
		array[high+1] = temp;
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
	InsertSort(a, length);
	printf("\n排序之后:\n");
	for(i = 0; i<10; ++i)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
