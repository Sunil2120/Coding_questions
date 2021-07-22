#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin >> n;
	vector< pair<int,int> > intervals;
	while(n--)
	{
		int start,end;
		cin >> start >> end;
		
		intervals.push_back(make_pair(start,end));
	}
	sort(intervals.begin(),intervals.end());
	cin >> m;
	while(m--)
	{
		int check;
		cin >> check;
		vector< pair< int,int > >:: iterator it;
		it = lower_bound(intervals.begin(),intervals.end(),make_pair(check,0));
		// int position = lower_bound(intervals.begin(),intervals.end(),make_pair(check,0)) - intervals.begin() we will get index
		if(it==intervals.end())
		{
			cout << -1 << endl;
			continue;
		}
		//cout << (*it).first << endl;
		if((*it).first==check)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			if(it== intervals.begin())
			{
				cout << (*it).first-check << endl;
				continue;
			}
			int p= (*it).first;
			it--;
			
			if((*it).second > check)
			{
				cout << 0 << endl;
				continue;
			}
			else
			{
				cout << p-check << endl;
				continue;
			}
		}
	}
	return 0;


}