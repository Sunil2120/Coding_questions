#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int,double> a,pair<int,double> b)
{
	return a.second > b.second;
}


double knapsack(int n,int W,int* weight,int* value)
{
	if(n==0 || W==0)
	{
		return 0;
	}
	double* temp = new double[n];
	for(int i=0;i<n;i++)
	{
		temp[i]=(double)value[i]/weight[i];
	}
	vector<pair<int,double>> temp2(n);
	for(int i=0;i<n;i++)
	{
		temp2[i]=make_pair(weight[i],temp[i]);
	}
	sort(temp2.begin(),temp2.end(),compare);
	double total = 0;
	for(int i=0;i<n;i++)
	{
		if(temp2[i].first <= W)
		{
			double ani = temp2[i].first*temp2[i].second;
			W = W - temp2[i].first;
			total+=ani;
		}
		else
		{
			double ani = temp2[i].second*W;
			W=0;
			total+=ani;
			break;

		}
	}
	return total;
}


int main()
{
	int n,W;
	cin >> n;
	int* value  = new int[n];
	int* weight = new int[n];
	cin >> W;
	for(int i=0;i<n;i++)
	{
		cin >> weight[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> value[i];
	}

	cout << knapsack(n,W,weight,value) << endl;


}