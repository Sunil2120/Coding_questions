#include<bits/stdc++.h>
using namespace std;

// time o(1)
// Auxillary space o(n)


void push(int* arr,int* top,int* next,int& free,int x,int stack)
{
	if(free==-1)
	{
		cout << "no space" << endl;
		return ;
	}
	int temp = free;
	arr[temp]=x;
	free= next[temp];
	next[temp]=top[stack];
	top[stack]=temp;
	return ;
}

int pop(int* arr,int* top,int* next,int& free,int stack)
{
	if(top[stack]==-1)
	{
		return -1;
	}
	int temp = top[stack];
	int value = arr[temp];
	top[stack]=next[temp];
	next[temp]=free;
	free=temp;
	return value;
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n]();
	int k;
	cin >> k;
	int* top = new int[k];
	for(int i=0;i<k;i++)
	{
		top[i]=-1;
	}
	int* next = new int[n];
	for(int i=0;i<n;i++)
	{
		next[i]=i+1;
	}
	next[n-1]=-1;
	int free = 0;
	int q;
	cin >> q;
	while(q--)
	{
		string input;
		cin >> input;
		if(input=="push")
		{
			int stack,x;
			cin >> stack >> x;
			push(arr,top,next,free,x,stack-1);
		}
		else
		{
			int stack;
			cin >> stack;
			cout << pop(arr,top,next,free,stack-1) << endl;
		}
	}
	return 0;
}