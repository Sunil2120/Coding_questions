#include<bits/stdc++.h>
using namespace std;


void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* arr1 = new int[n];
	map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		arr1[i]=i+1;
		hash[arr[i]]=i;
	}
	// int i=n-1;
	// while(i >= 0 )
	// {
	// 	int pos=hash[arr1[i]];
	// 	if(i==pos)
	// 	{
	// 		i--;
	// 		continue;
	// 	}
	// 	int suni=i;
	// 	for(int j=0;j<2;j++)
	// 	{
	// 		if(suni!=pos)
	// 		{
	// 			swap(&arr1[suni],&arr1[suni-1]);
	// 			suni--;
	// 		}
	// 	}
	// 	if(suni!=pos)
	// 	{
	// 		cout << "NO" << endl;
	// 		return 0;
	// 	}
	// 	i=n-1;
	// }

	// cout  << "YES" << endl;
	int c=0;
	int count =0;
	for(int i=0;i<n;i++)
	{
		if(abs(arr[i]-1-i)<=2)
		{
			if(abs(arr[i]-1-i)!=0)
			{
				count+=abs(arr[i]-1-i);
			}
			c++;
		}
		
	}
	if(c==n)
	{
		cout << "YES" << endl << count <<  endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}