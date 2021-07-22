#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* ptr;
	int a=10;
	sprintf(ptr,"%d",a);
	printf("%s",ptr);
	return 0;
}