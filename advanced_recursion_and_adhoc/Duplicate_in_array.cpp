#include<bits/stdc++.h>
using namespace std;

void solve_(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		
			if(arr[abs(arr[i])] > 0)
			{
				arr[abs(arr[i])] = -1*arr[abs(arr[i])];
			}
			else
			{
				cout << abs(arr[i]) << " " ;
			}	
		
	}
	return ;

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
	//cout << solve_(arr,n) << endl;
	solve_(arr,n);
	return 0;
}