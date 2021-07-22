// to find the max consecutive sequence present in a given array

#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}


vector<int> longestConsecutiveIncreasingSequence(int* arr,int n)
{
	unordered_set<int> s;
	map< int , vector<int> > m;
	int k=0;
	int ma = -1;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	for(int i=0;i<n;i++)
	{

		if(s.find(arr[i]-1)==s.end())
		{
			int j = arr[i];
			while(s.find(j)!=s.end())
			{
				//cout << j << " ";
				m[i].push_back(j);
				// cout << v[k].back() << " ";
				j++;
			}

			//cout << j-arr[i] << endl;
			//cout << m[i].size() << endl;
			ma = max(ma,m[i].size());
			// for(int h=0;h<m[i].size();h++)
			// {
			// 	cout << m[i][h] <<" ";
			// }
			// k++;
			//cout << endl;
		}
	}

	//cout << ma << endl;

	map<int , vector<int> > :: iterator it;
	for(it = m.begin();it!=m.end();it++)
	{
		if(it->second.size() == ma)
		{
			return it->second;
		}
	}

	// for(int i=0;i<v.size();i++)
	// {
	// 	if(v[i].size() == max)
	// 	{
	// 		for(int j=0;j<v[i].size();j++)
	// 		{
	// 			cout  << v[i][j] << " ";
	// 		}
	// 	}
	// 	cout << endl;
	// }
	return ;
}
	

int main()
{
	int arr[13]={2,12,9,16,10,5,3,20,25,11,1,8,6}; 
	solve_(arr,13);
	return 0;
}