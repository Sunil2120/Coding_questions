#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* intal_add(char* a,char* b)
{
	int x = atoi(a);
	int y = atoi(b);
	int res = x+y;
	int count = 0;
	while(res!=0)
	{
		res=res/10;
		count+=1;	}
	char *str=(char*)malloc(sizeof(char)*(count+1));
	itoa(x+y,str,10);
	return str;
}


int intal_compare(char* a,char* b)
{
	int x = atoi(a);
	int y = atoi(b);
	if(x==y)
	{
		return 0;
	}
	return (x>y)?1:-1;
}

char* intal_diff(char* a,char* b)
{
	int x = atoi(a);
	int y = atoi(b);
	int g = intal_compare(a,b);
	int count =0;
	
	int res = 0;
	if(g==1)
	{
		res = x - y;
	}
	else
	{
		res = y-x;
	}
	int temp= res;
	while(res!=0)
	{
		res=res/10;
		count+=1;	
	}
	char* str=(char*)malloc(sizeof(char)*count+1);
	itoa(temp,str,10);
	return str;
}



int main()
{
	char su=5+'0';
	char* str="anil";
	str = strcat(str)	
	return 0;
}