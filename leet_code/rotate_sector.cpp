#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	int* arr = new int[n+1]();
	int* input = new int[m];
	for(int i=0;i<m;i++)
	{
		cin >> input[i];
	}
	for(int i=0;i<m-1;i++)
	{
		int start = input[i];
		int end = input[i+1];
		int temp = start;
		if(i==0)
		{
			arr[start]+=1;
		}
		while(temp!=end)
		{
			if(temp!=start)
			{
				arr[temp]+=1;
			}
			temp+=1;
			if(temp > n)
			{
				temp = 1;
			}
		}
		arr[end]+=1;
		
	}
	for(int i=0;i<=n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}