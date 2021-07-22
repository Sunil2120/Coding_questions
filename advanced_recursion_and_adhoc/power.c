#include<stdio.h>
#include<string.h>



char* power(char* x,unsigned int y)
{
	if(y==0)
	{
		return "1";
	}
	char* temp = (char*)malloc(sizeof(char)*1001);
	strcpy(temp,power(x,y/2));
	return y%2 ? x*t*t : t*t;
}
int main()
{
	printf("%lld\n",power(2,20));
	return 0;
}