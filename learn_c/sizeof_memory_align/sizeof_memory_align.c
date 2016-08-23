#include <stdio.h>
#include <stdlib.h>


#pragma pack(push, 1)

struct memroy_algin_first
{
	char a;
	int  b;
}stData1;
#pragma pack(pop)

#pragma pack(push, 2)

struct memroy_algin_second
{
	char a;
	int  b;
}stData2;
#pragma pack(pop)
struct f
{
	int length;
	int array[];
}f;
struct f Foo = {5, {2, 4, 5, 5}};
int main(int argc, char *argv[])
{
	printf("sizeof(stData1): %ld\n", sizeof(stData1));
	printf("sizeof(stData2): %ld\n", sizeof(stData2));
	printf("f: %ld ,Foo:%ld\n", sizeof(f), sizeof(Foo));
	return 0;
}
