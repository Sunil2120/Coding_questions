#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n1,n2,n3;
		cin >> n1 >> n2 >> n3;
		unordered_set<int> suni;
		vector<int> output;
		for(int i=0;i<n1;i++)
		{
			int value ;
			cin >> value;
			if(suni.find(value)==suni.end())
			{
				suni.insert(value);
			}
			else
			{
				output.push_back(value);
			}
		}
		for(int i=0;i<n2;i++)
		{
			int value ;
			cin >> value;
			if(suni.find(value)==suni.end())
			{
				suni.insert(value);
			}
			else
			{
				output.push_back(value);
			}
		}
		suni.clear();
		for(int i=0;i<n3;i++)
		{
			int value ;
			cin >> value;
			if(suni.find(value)==suni.end())
			{
				suni.insert(value);
			}
			else
			{
				output.push_back(value);
			}
		}

		for(int i=0;i<output.size();i++)
		{
			if(suni.find(output[i])!=suni.end())
			{
				cout << output[i] << " ";
			}
		}
		cout << endl;

	}
}