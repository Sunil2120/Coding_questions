#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> input(n);
		for(int i=0;i<n;i++)
		{
			cin >> input[i];
		}
		sort(input.begin(),input.end());
		int count = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(input[i]-input[0] > k)
			{
				count+=((input[i]-input[0])-k);
			}
		}
		cout << count << endl;
	}
	
	return 0;
}