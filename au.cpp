#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int start=0;
		map<char,int> m;
		int* arr=new int[s.size()]();
		int start=0;
		for(int i=0;i<s.size();i++)
		{
			m[s[i]]++;
		}
		for(int i=1;i<s.size();i++)
		{
			if(arr[i]==arr[i-1])
			{
				start++;
			}
			if(m[s[i]]!=0)
			{
				arr[i]=start;
			}
		}
		for(int i=0;i<s.size();i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}