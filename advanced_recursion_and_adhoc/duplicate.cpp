#include<bits/stdc++.h>

using namespace std;


vector<int> removeDuplicate(vector<int> a)
{
	set<int> s;
	vector<int> result;
	vector<int> :: iterator it;
	for(it=a.begin();it!=a.end();it++)
	{
		s.insert(*it);
	}
	set<int> :: iterator t;
	for(t=s.begin();t!=s.end();t++)
	{
		result.push_back(*t);
	}
	return result;

}

vector<int> dup2(vector<int> a)
{
	set<int> s;
	vector<int> v;
	for(int i=0;i<a.size();i++)
	{
		if(s.find(a[i])==s.end())
		{
			s.insert(a[i]);
			v.push_back(a[i]);
		}
	}
	return v;
}

vector<int> dup3(vector<int> a)
{
	vector<int> result;
	sort(a.begin(),a.end());
	int prev=-1;
	int cur =0;
	for(int i=0;i<a.size();i++)
	{
		cur = a[i];
		if(cur!=prev)
		{
			result.push_back(a[i]);
		}
		prev=a[i];
		
	}
	return result;
}

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int v;
		cin >> v;
		arr.push_back(v);
	}
	vector<int> result = dup3(arr);
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	return 0;

	
	return 0;




}