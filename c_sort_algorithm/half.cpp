#include <iostream>
using namespace std;

//为了方便我就直接用数组了啊
int Binary_delete(int array[],int len,int data)
{
	int low,high,mid;
	int count = 0;
	low = 1;
	high = len - 1;
	while(low <= high)
	{
		++count;
		mid = (low + high) / 2;
		if(data == array[mid])
			{
				break;
			}	
		else if(data < array[mid])
			{
				high = mid - 1;
			}
		else
			{
				low = mid + 1;
			}
	}
		for(int j = mid; j<len-1; j++)
		{
			array[j] = array[j+1];
		}
	return count;
}


int main(void)
{

	int array[10] = {4,5,7,12,23,34,45,56,67,78};
	cout<<"比较次数"<<Binary_delete(array, 10, 56)<<endl;
	for(int i = 0; i<10-1; ++i)
	{
		cout<<array[i]<<",";
	}
	cout<<endl;
	return 0;
}
