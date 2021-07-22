#include<bits/stdc++.h>
using namespace std;

string solve(int n)
{
	if(n==0)
	{
		return "";
	}
	if(n==1)
	{
		return "1";
	}
	string output = solve(n-1);
	string result = "";
	int i=0;
	while(i<output.size())
	{
		char cur = output[i];
		int count = 0;
		for(int j=i;j<output.size();j++)
		{
			if(output[j]==cur)
			{
				count+=1;
			}
			else
			{
				break;
			}
		}
		result.push_back(count+'0');
		result.push_back(cur);
		i+=count;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}