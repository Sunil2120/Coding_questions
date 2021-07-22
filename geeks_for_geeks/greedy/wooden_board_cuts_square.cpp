#include<bits/stdc++.h>
using namespace std;



bool compare(int a,int b)
{
	return a > b;
}
int solve(vector<int>& x,vector<int>& y,int m,int n)
{
	sort(x.begin(),x.end(),compare);
	sort(y.begin(),y.end(),compare);
	int i=0;
	int j=0;
	int horizontal = 1;
	int vertical = 1;
	int total = 0;
	while(i<m && j<n)
	{
		if(x[i] > y[j])
		{
			// make horizontal cut
			total+=(x[i]*vertical);
			horizontal+=1;
			i+=1;
		}
		else
		{
			// make vertical cut
			total+=(y[j]*horizontal);
			vertical+=1;
			j+=1;
		}
	}
	while(i<m)
	{
		total+=(x[i]*vertical);
		i++;
	}
	while(j<n)
	{
		total+=(y[j]*horizontal);
		j++;
	}
	return total;
}

int main()
{
	int m,n;
	cin >> m >> n;
	vector<int> x(m);
	vector<int> y(n);
	for(int i=0;i<m;i++)
	{
		cin >> x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> y[i];
	}
	cout << solve(x,y,m,n) << endl;
	return 0;
}