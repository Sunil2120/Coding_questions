#include<bits/stdc++.h>
using namespace std;


void update(int index,int value,int* BIT,int n)
{
	for(int i= index;i<=n;i+=(i&(-i)))// we are going to next one
	{
		BIT[i]+=value;
	}
	return ;	
}


int query(int index,int* BIT)
{
	int sum = 0;
	for(int i=index;i>0;i-=(i&(-i)))// we are going to previous one(parent)(flip the right most set bit)
	{
		sum+=BIT[i];
	}
	return sum;
}



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n+1]();// we are starting from 1
	int* BIT = new int[n+1]();
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		update(i,arr[i],BIT,n);
	}
	for(int i=1;i<=n;i++)
	{
		cout << BIT[i] << " ";
	}
	cout << endl;
	cout << "sum of first 2 elements " << query(2,BIT) << endl;
	cout << "sum within the range 2 to 5 " << query(5,BIT)-query(1,BIT) << endl;
	return 0;
}