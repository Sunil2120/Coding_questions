#include<bits/stdc++.h>
using namespace std;
int n = 100;
int* arr = new int[n];
int top = -1;

void push(int key)
{
	if(top==n)
	{
		cout << "stack is full" << endl;
		return ;
	}
	top+=1;
	arr[top]=key;
	return ;
}

int pop()
{
	if(top==-1)
	{
		return -1;
	}
	int output = arr[top];
	top-=1;
	return output;
}


int main()
{
	int count;
	cin >> count;
	while(count--)
	{
		string check;
		int value;
		cin >> check;
		if(check=="push")
		{
			cin >> value;
			push(value);
		}
		else
		{
			cout << pop() << endl;
		}
	}

	

	return 0;
}