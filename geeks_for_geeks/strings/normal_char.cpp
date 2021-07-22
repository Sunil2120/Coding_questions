#include<bits/stdc++.h>
using namespace std;


int solve(string a,string b,int k)
{
	if(a.size()==0)
	{
		return 0;
	}
	unordered_set<int> s;
	for(int i=0;i<26;i++)
	{
		if(b[i]=='0')
		{
			s.insert(i);
		}
	}
	int left = 0;
	int right = 0;
	int count = 0;
	int max_value = INT_MIN;
	while(right < a.size())
	{
		if(count <= k)
		{
			max_value = max(max_value,(right-left+1));
			if(s.find(a[right]-'a')!=s.end())
			{
				count+=1;
			}
		}
		if(count > k)
		{
			while(count > k && left <= right)
			{
				if(s.find(a[left]-'a')!=s.end())
				{
					count-=1;
					left+=1;
				}
			}
			if(count <= k)
			{
				max_value = max(max_value,(right-left+1));
			}
		}
		right+=1;
	}
	return max_value;
}

int main()
{
	string a,b;
	int k;
	cin >> a >> b;
	cin >> k;
	cout << solve(a,b,k) << endl;
	return 0;
}