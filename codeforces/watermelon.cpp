#include<bits/stdc++.h>
using namespace std;

bool solve(int w)
{
	vector<int> even;
	for(int i=2;i<=w;i+=2)
	{
		even.push_back(i);
	}
	for(int i=0;i<even.size();i++)
	{
		if(w%even[i] == 0 && (w/even[i]) == 2)
		{
			return true;
		}
		for(int j=i+1;j<even.size();j++)
		{
			if(even[i]+even[j] == w)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int w;
	cin >> w;
	if(solve(w))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}