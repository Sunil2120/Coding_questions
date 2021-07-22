#include<bits/stdc++.h>
using namespace std;


int grundy2(int n)
{
	if(n==0)
	{
		return 0;
	}
	int f = grundy2(n/2);
	int s = grundy2(n/3);
	int t = grundy2(n/6);
	unordered_set<int> suni;
	int max_ = INT_MIN;
	suni.insert(f);
	suni.insert(s);
	suni.insert(t);
	max_ = max(f,max(s,t));
	for(int i=0;i<=max_+1;i++)
	{
		if(suni.find(i)==suni.end())// not present in given set
		{
			return i;
		}
	}
	return 0;
}

int grundy(int n,int* arr)
{
	if(n==0)
	{
		return 0;
	}
	if(arr[n]!=-1)
	{
		return arr[n];
	}
	int f = grundy(n/2,arr);
	int s = grundy(n/3,arr);
	int t = grundy(n/6,arr);
	unordered_set<int> suni;
	int max_ = INT_MIN;
	suni.insert(f);
	suni.insert(s);
	suni.insert(t);
	max_ = max(f,max(s,t));
	for(int i=0;i<=max_+1;i++)
	{
		if(suni.find(i)==suni.end())// not present in given set
		{
			arr[n]=i;
			break;
		}
	}
	return arr[n];
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		arr[i]=-1;
	}
	cout << grundy(n,arr) << endl;
	delete[] arr;
	return 0;
}