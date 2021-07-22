#include<iostream>
#include<string>

using namespace std;

int solve(string a,string b)
{
	if(a.size()!=b.size())
	{
		return -1;
	}
	int count[26]={0};
	for(int i=0;i<a.size();i++)
	{
		count[a[i]-'a']+=1;
	}
	for(int i=0;i<b.size();i++)
	{
		count[b[i]-'a']-=1;
	}
	for(int i=0;i<26;i++)
	{
		if(count[i]!=0)
		{
			return -1;
		}
	}
	int result = 0;
	// both strings have same characters and characters are in same number
	for(int i=a.size()-1,j=b.size()-1;j>=0 && i>=0;)
	{
		while(i>=0 && a[i]!=b[j])
		{
			i--;
			result+=1;
		}
		if(i>=0 && a[i]==b[j])
		{
			i--;
			j--;
		}
	}
	return result;
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << solve(a,b) << endl;
}