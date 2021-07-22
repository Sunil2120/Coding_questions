#include<bits/stdc++.h>
using namespace std;



int length(char input[])
{
	if(input[0]=='\0')
	{
		return 0;
	}
	return length(input + 1) + 1;
}


void remove_char(char input[],char a)
{
	if(input[0]=='\0')
	{
		return ;
	}
	if(input[0]!=a)
	{
		remove_char(input+1,a);
	}
	else
	{
		int i=1;
		for(;input[i]!='\0';i++)
		{
			input[i-1]=input[i];
		}
		input[i-1]=input[i];
		//cout << input << endl;
		remove_char(input,a);
	}
}


void replace(char input[],char a,char b)
{
	if(input[0]=='\0')
	{
		return ;
	}
	if(input[0]!=a)
	{
		replace(input+1,a,b);
	}
	else
	{
		input[0]=b;
		replace(input+1,a,b);
	}
	return ;
}

void remove_duplicate(char input[])
{
	if(input[0]=='\0')
	{
		return ;
	}
	if(input[1]!=input[0])
	{
		remove_duplicate(input+1);
	}
	else
	{
		int i=1;
		for(;input[i]!='\0';i++)
		{
			input[i-1]=input[i];
		}
		input[i-1]=input[i];
		remove_duplicate(input);
	}
	return ;
}

int main()
{
	char input[100];
	cin >> input;
	cout << length(input) << endl;
	//remove_char(input,'x');
	//replace(input,'x','y');
	remove_duplicate(input);
	cout << input << endl;
	return 0;
}