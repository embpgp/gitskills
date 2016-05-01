#include <stdio.h>

void InsertSort(int *array, int length )
{
	int i = 0,j = 0;
	int temp;
	for(i = 1; i<length; ++i)
	{
		temp = array[i];
		j = i-1;
		while(temp < array[j])
		{
				array[j+1] = array[j];
				--j;
		}
		array[j+1] = temp;
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
