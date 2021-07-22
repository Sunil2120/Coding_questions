#include<bits/stdc++.h>
using namespace std;




void FindTriplet(int arr[],int n,int x)
{
	//cout << " hello " << endl;
	map <pair<int , pair<int,int> >, int> m;
	//int* a = new int[n];
	// for(int i=0;i<n;i++)
	// {
	// 	a[i]=0;
	// }
	int suni =0;
	if(n < 3)
	{
		return ;
	}
	for(int i=0;i<=n-3;i++)
	{
		for(int j=i+1;j<=n-2;j++)
		{
			for(int k=j+1;k<=n-1;k++)
			{
				//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				if(arr[i]+arr[j]+arr[k] == x)
				{
					m[make_pair(arr[i],make_pair(arr[j],arr[k]))]++;

					//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				}
			}
		}
	}
	//cout << endl ;

	map <pair<int , pair<int,int> >, int> :: iterator it;
	for( it=m.begin();it!=m.end();it++)
	{
		cout << it->first.first << " " << it->first.second.first << " " << it->first.second.second <<  endl;
	}

	// for(int i=0;i<n;i++)
	// {
	// 	cout << a[i] << endl;
	// }

	return ;
}
int main()
{
	int n;
	int x;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	FindTriplet(arr,n,x);
	return 0;
}