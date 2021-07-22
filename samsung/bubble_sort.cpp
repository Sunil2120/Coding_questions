#include<bits/stdc++.h>
using namespace std;

// O(n2) and O(1) space
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int i=1;
	while(i<=n-1)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		i+=1;
	}
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}