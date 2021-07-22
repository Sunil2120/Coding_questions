#include<bits/stdc++.h>
using namespace std;


int solve(string input,unordered_set<string> s)
{
	if(input.size()==0)
	{
		return 0;
	}
	int n = input.size();
	int max_ = INT_MIN;
	for(int i=1;i<=n;i++)
	{	
		string temp = input.substr(0,i);
		if(s.find(temp)==s.end())
		{
			s.insert(temp);
			int option1 = solve(input.substr(i),s)+1;
			s.erase(temp);
			max_ = max(max_,option1);
		}
	}
	return max_;
	

}

int main()
{
	string input;
	cin >> input;
	unordered_set<string> s;
	cout << solve(input,s) << endl;
	return 0;
}