#include<bits/stdc++.h>
using namespace std;


bool Ispalindrome(string temp)
{
	string temp2 = temp;
	reverse(temp2.begin(),temp2.end());
	if(temp==temp2)
	{
		return true;
	}
	return false;
}

int solve(string s,int start,int index,string prev)
{
	if(start > index)
	{
		return 99999;
	}
	if(index==s.size())
	{
		if(Ispalindrome(s.substr(start,index)))
		{
			return 0;
		}
		return 999999;
	}
	string temp = prev+s[index];
	int op1 = INT_MAX;
	int op2 = INT_MAX;
	if(Ispalindrome(temp))
	{
			op1 = min(solve(s,start,index+1,temp),solve(s,index+1,index+1,"")+1);
			
	}
	op2 = solve(s,start,index+1,temp);
	return min(op2,op1);
	
}



int main()
{
	string s;
	cin >> s;
	cout << solve(s,0,0,"") << endl;
	return 0;
}