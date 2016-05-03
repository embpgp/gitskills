#include <stdio.h>

void Quit_sort(int *array, int start, int end)
{
	int i = start,j = end;
	int temp = array[i];    //restore the var
	while(i<j)            //find the pos
	{
		while(i<j && temp<=array[j])
			j--;
		array[i] = array[j];         //
		while(i<j && array[i]<=temp)
			i++;
		array[j] = array[i];
	}
	array[i] = temp;
	if(start < i-1)
		Quit_sort(array, start, i-1);
	if(i+1 < end)
		Quit_sort(array, i+1, end);
}

int main(void)
{
	int i;
	int a[] = {23,45,5,76,34,56,78,987,23,43};
	int length = 9;
	printf("排序之前:\n");
	for(i = 0; i<10; ++i)
	{
		printf("%d  ",a[i]); 
	}
	Quit_sort(a, 0, length);
	printf("\n排序之后:\n");
	for(i = 0; i<10; ++i)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
