#include<bits/stdc++.h>
using namespace std;


int check(vector<int> input,int n,int k)
{
	// for(int i=0;i<n;i++)
	// {
	// 	cout << input[i] << " ";
	// }
	// cout << endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(input[i] > input[j])
			{
				if(j-i > k)
				{
					//cout << "pos: " << i << endl;
					return i;
				}
				break;
			}
		}
	}
	return -1;
}
bool solve(vector<int> input,int n,int k)
{
	
	if(check(input,n,k)==-1)
	{
		return true;
	}
	int pos = check(input,n,k);
	int nearest = -1;
	for(int i=pos+1;i<=n;i++)
	{
		if(input[pos] > input[i]&& (i-pos)>k)
		{
			nearest = i;
			break;
		}
	}
	// cout << nearest << endl;
	if(nearest==n)
	{
		return false;
	}
	for(int i=1;i<= k;i++)
	{
		if(input[i+pos] > input[nearest])
		{
			int temp1 = input[i+pos];
			input[i+pos]=input[nearest];
			input[nearest]=temp1;
			int temp = check(input,n,k);
			if(temp==-1)
			{
				return true;
			}
			temp1 = input[i+pos];
			input[i+pos]=input[nearest];
			input[nearest]=temp1;
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> input(n+1);
		for(int i=0;i<n;i++)
		{
			cin >> input[i];
		}
		input.push_back(0);
		bool output = solve(input,n,k);
		if(output==true)
		{
			cout << "Bazzinga" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}