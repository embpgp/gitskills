/*
* hello.cpp
*/

#include "hello.h"
#include <stdio.h>

void sayHello()
{
	printf("Hello World\n");
	printf("product info:%s\n", PRODUCT_INFO);
#if ENABLE_TALKING==1
	printf("product feature:%s\n","TALKING is enabled");
#else
	printf("product feature:%s\n","TALKING is disabled");
#endif
}
