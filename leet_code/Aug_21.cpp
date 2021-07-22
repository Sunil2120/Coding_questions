// sort by parity
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int odd = 0;
	int even = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i]&1)
		{
			odd+=1;
		}
		else
		{
			even+=1;
		}
	}
	// cout << odd << " " << even << endl;
	// first n number should contain even
	
	for(int i=0;i<n;i++)
	{
		if(i<even && (arr[i]%2)!=0)//odd and in even position
		{
			for(int j=even;j<n;j++)
			{
				if((arr[j]%2)==0)//even
				{
					swap(arr[i],arr[j]);
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}