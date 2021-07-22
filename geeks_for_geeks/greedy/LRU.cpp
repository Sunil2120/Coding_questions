#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pd;



int solve(vector<int>& input,int n,int capacity)
{

	unordered_set<int> s;
	unordered_map<int,int> hash;
	int page_faults = 0;
	for(int i=0;i<n;i++)
	{
		if(s.size() < capacity)
		{
			if(s.find(input[i])==s.end())//not present
			{
				s.insert(input[i]);
				page_faults+=1;
				hash[input[i]]=i;
			}
			else
			{
				//present
				hash[input[i]]=i;
			}
		}
		else
		{

			if(s.find(input[i])!=s.end())//capacity full and element is already present
			{
				hash[input[i]]=i;
			}
			else
			{
				//capacity full and not present
				// remove the least recently use or which is far from cur
				int req_index = INT_MAX;
				int req_val = 0 ;
				unordered_set<int> :: iterator it;
				for(it=s.begin();it!=s.end();it++)
				{
					if(hash[*it] < req_index)
					{
						req_index =hash[*it];
						req_val = *it;
					}
				}
				s.erase(req_val);
				s.insert(input[i]);
				hash[input[i]]=i;
				page_faults+=1;
			}
		}

	}
	return page_faults;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	int k;
	cin >> k;
	cout << solve(input,n,k) << endl;
	return 0;


}