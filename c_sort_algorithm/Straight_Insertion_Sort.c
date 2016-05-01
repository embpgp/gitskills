#include <stdio.h>
#define MAX_SIZE 100
typedef int KeyType;
typedef struct RecType
{
	KeyType key;       //关键字
	//infoType otherinfo;
}RecType;

typedef struct
{
	RecType R[MAX_SIZE];
	int length;
}Sqlist;

void InsertSort(Sqlist *L)
{
	int i,j;
	for(i = 2; i<=L->length; ++i)
	{
		L->R[0] = L->R[i];
		j = i-1;
		while(L->R[0].key<L->R[j].key)
		{
			L->R[j+1] = L->R[j];
			j--;
		}
		L->R[j+1] = L->R[0];
	}
}

int main(void)
{

	return 0;
}
