/*Filename:Merge_sort.cpp
 *
 *Author:rutk1t0r
 *
 *Date:2016.9.20
 *
 *GPL
 *
 *method:`g++ -o Merge_sort Merge_sort.cpp`
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include <iostream>

/*
temp数组提前申请的目的在于在程序运行期间一直可用,而不用每次都去申请造成时间的浪费
而本函数的目的就是比较两个值大小再排序
*/
void MegerArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;
	int m = mid;
	int n = last;
	int k = 0;
	while(i <= m && j <= n)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{	
			temp[k++] = a[j++];
		}
	}
	while(i <= m)
	{
		temp[k++] = a[i++];	
	}
	while(j <= n)
	{
		temp[k++] = a[j++];
	}

	for(i = 0; i<k; ++i)
	{
		a[first+i] = temp[i]; 
	}
}

void mergesort(int a[], int first, int last, int temp[])
{
	if(first < last)
	{
		int mid = (first+last)/2;
		mergesort(a, first, mid, temp);
		mergesort(a, mid+1, last, temp);
		MegerArray(a, first, mid, last, temp);
	}
}

bool Merge_Sort(int a[], int n)
{
	int *pTempArray = new int[n];
	if(pTempArray == NULL)
	{
		return false;
	}
	mergesort(a, 0, n-1, pTempArray);
	delete[] pTempArray;
	return true;
}
int main(int argc, char *argv[])
{

	int array[] = {1,55,46,24,56,78,44,21,100,98};
	for(int i = 0; i < sizeof(array)/sizeof(int); ++i)//每次传递参数的时候总是忘记除以类型大小
	{
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
	if(!Merge_Sort(array, sizeof(array)/sizeof(int)))
	{
		return -1;
	}
	for(int i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
