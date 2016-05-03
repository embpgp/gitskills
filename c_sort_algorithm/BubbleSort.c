#include <stdio.h>

void BubbleSort(int *array, int length)
{
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
					}
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
