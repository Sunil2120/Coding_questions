#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& a,vector<int>& b,int n,int m)
{
	int total = n+m;
	int req1 = 0;
	int req2 = 0;
	int i=0;
	int j=0;
	int count = 0;
	int value = 0;
	while(i<n && j<m)
	{
		if(a[i] < b[j])
		{

			value = a[i];
			i++;
			count+=1;
		}
		else
		{
			value = b[j];
			j++;
			count+=1;
		}
		cout << count << " " << value << endl;
		if(count==(total/2))
		{
			req1 = value;
		}
		else if(count==(total/2)+1)
		{
			req2 = value;
			break;
		}
	}
	while(i<n)
	{
		count+=1;
		value = a[i];
		cout << count << " " << value << endl;
		i++;
		if(count==(total/2))
		{
			req1 = value;
		}
		else if(count==(total/2)+1)
		{
			req2 = value;
			break;
		}
	}
	while(j<m)
	{
		count+=1;
		value = b[j];
		cout << count << " " << value << endl;
		j++;
		if(count==(total/2))
		{
			req1 = value;
		}
		else if(count==(total/2)+1)
		{
			req2 = value;
			break;
		}

	}
	cout << req1 << " " << req2 << endl;
	if(total%2 == 0)
	{
		return (req1+req2)/2;
	}
	
	else
	{
		return (req2);
	}
	return -1;
	
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> b[i];
	}
	cout << solve(a,b,n,m) << endl;
	return 0;
}