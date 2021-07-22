//arrays triplet problem
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int count =0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i]%3==0)
		{
			count+=1;
		}
	}
	
	if(count==0)
	{
		cout << "nothing" << endl;
	}
	else
	{
		cout << count << endl;
		for(int i=0;i<n;i++)
		{
			if(arr[i]%3==0)
			{
				cout << i << endl;
			}
		}
	}
	return 0;
}




