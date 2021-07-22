#include<bits/stdc++.h>
using namespace std;


void update(int* BIT,int index,int n)
{
	for(int i=index;i<=n;i+=(i&(-i)))
	{
		BIT[i]+=1;
	}
	return ;
}

int query(int* BIT,int index)
{
	int sum = 0;
	for(int i=index;i>0;i-=(i&(-i)))
	{
		sum+=BIT[i];
	}
	return sum;
}

void insert(int* BIT,int* arr,map<int,int> hash,int value)
{
	
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	int count = 1;
	map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		hash[arr[i]]=count;
		count+=1;
	}
	int* BIT = new int[count]();
	// for(int i=1;i<count;i++)
	// {
	// 	update(BIT,i,count);
	// }

	int q;
	cin >> q;
	// 1 insert,2 delete,3 kth smallest element,4 smallest elements less than x
	for(int i=0;i<q;i++)
	{
		int choice;
		cin >> choice;
		if(choice==1)
		{
			hash[arr[k]]
			if()
		}
	}
	return 0;
}