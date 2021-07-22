#include<bits/stdc++.h>
using namespace std;




vector<int> voter_list(vector<int> l1,vector<int> l2,vector<int> l3)
{
	vector<int> total;
	vector<int> result;
	total=l1;
	for(int i=0;i<l2.size();i++)
	{
		total.push_back(l2[i]);
	}
	for(int i=0;i<l3.size();i++)
	{
		total.push_back(l3[i]);
	}
	sort(total.begin(),total.end());
	int prev=-1;
	int cur =0;
	int next =-1;
	set<int> s;
	for(int i=0;i<total.size();i++)
	{
		cur = total[i];
		if(cur==prev)
		{
			if(s.find(cur)==s.end())
			{
				s.insert(cur);
				result.push_back(cur);
			}
		}
		prev=cur;
	}
	return result;

}


vector<int> voter_list2(vector<int> l1,vector<int> l2,vector<int> l3)
{
	vector<int> total;
	vector<int> result;
	total=l1;
	for(int i=0;i<l2.size();i++)
	{
		total.push_back(l2[i]);
	}
	for(int i=0;i<l3.size();i++)
	{
		total.push_back(l3[i]);
	}
	sort(total.begin(),total.end());
	for(int i=0;i<total.size();)
	{
		int count = 0;
		int j = i;
		while(j< total.size() && total[j]==total[i])
		{
			count++;
			j++;
		}
		if(count >=2)
		{
			result.push_back(total[i]);
		}
		i=j;
	}
	return result;

}
int main()
{
	vector<int> l1={1,3,3,5,7};
	vector<int> l2={1,5,6,7,9};
	vector<int> l3={1,3,5,7,8};
	vector<int> result;
	result = voter_list2(l1,l2,l3);
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}