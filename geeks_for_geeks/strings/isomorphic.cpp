#include<bits/stdc++.h>
using namespace std;




//O(n) and auxillary space O(n)
bool solve(string a,string b)
{
	if(a.size()!=b.size())
	{
		return false;
	}
	char arr[26];
	for(int i=0;i<26;i++)
	{
		arr[i]='#';
	}
	for(int i=0;i<a.size();i++)
	{
		//case 1 a[i] is occuring for the first time
		if(arr[a[i]-'a']=='#')
		{
			//if corresponding b[i] is also occuring for the first time
			if(arr[b[i]-'a']=='#')
			{
				arr[a[i]-'a']=b[i];
				arr[b[i]-'a']=a[i];
			}
			// if corresponding b[i] is not occuring for the first time
			else
			{
				return false;
			}
		}
		// case 2 a[i] is not occuring for the first time
		else
		{
			if(arr[a[i]-'a']!=b[i])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << solve(a,b) << endl;
	return 0;
}