#include<bits/stdc++.h>
using namespace std;

//space efficient method
int n = 15;
int k=3;
int* arr = new int[n]();
int* next_arr = new int[n];
int* top = new int[k];
int free_variable = 0;


bool isEmpty(int sn)
{
	if(top[sn]==-1)
	{
		return true;
	}
	return false;
}

bool isFull()
{
	if(free_variable==-1)
	{
		return true;
	}
	return false;
}
void push(int item,int sn)
{
	if(isFull())
	{
		return ;
	}
	int i=free_variable;
	arr[i]=item;
	// element inserted into the stack will become the top of the stack
	free_variable = next_arr[i];
	next_arr[i]=top[sn];
	top[sn]=i;
	return ;
}

int pop(int sn)
{
	if(isEmpty(sn))
	{
		return -1;
	}
	int output = top[sn];
	// now next_arr of top of sn will become top of the stack
	top[sn]=next_arr[output];
	next_arr[output]=free_variable;
	free_variable=output;
	return arr[output];
}
int main()
{
	

	
	for(int i=0;i<n;i++)
	{
		next_arr[i]=i+1;
	}
	next_arr[n-1]=-1;
	for(int i=0;i<k;i++)
	{
		top[i]=-1;
	}
	int q;
	cin >> q;
	while(q--)
	{
		string input;
		cin >> input;
		if(input=="push")
		{
			int sn,item;
			cin >> item >> sn;
			push(item,sn);
		}
		else
		{
			int sn;
			cin >> sn;
			cout << pop(sn) << endl;
		}
	}
	delete[] arr,next_arr,top;
	return 0;


}