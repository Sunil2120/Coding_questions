#include<bits/stdc++.h>
using namespace std;



bool compare( pair< string,int> p1 , pair<string ,int> p2)
{
	return p1.second > p2.second;
}
int main()
{
	int n;
	cin >> n;
	vector< pair< string,vector<int>> > v;
	vector< pair < string , int> > result;
	while(n--)
	{
		string name;
		int sub1;
		int sub2;
		int sub3;
		cin >> name >> sub1 >> sub2 >> sub3;
		result.push_back(make_pair(name,sub1+sub2+sub3));

	}

	sort(result.begin(),result.end(),compare);

	int count =1;
	int j = 0;
	int start = 0;
	int end=0;
	int c = 0;

	for(int i=0;i<result.size();)
	{
		cout << result[i].first << " " << result[i].second << " " << count << endl;
		 count ++;
	}

	return 0;
}