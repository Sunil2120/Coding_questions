#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			cout << 9 << endl;
		}
		else if(n==2)
		{
			cout << 98 << endl;
		}
		else if(n==3)
		{
			cout << 989 << endl;
		}
		else
		{
			cout << 989 ;
			for(int i=0;i<n-3;i++)
			{
				cout << i%10;
			}
			cout << endl;
		}
	}
	return 0;
}