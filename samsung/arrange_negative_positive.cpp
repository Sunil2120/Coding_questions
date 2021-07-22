#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>& input,int n)
{
	int i = 0;
	int j = n-1;
	while(i<j && i< n && j>=0)
	{
		if(input[i] > 0 && input[j] < 0)
		{
			int temp = input[i];
			input[i]=input[j];
			input[j]=temp;
			i++;
			j--;
		}
		else
		{
			if(input[i] < 0)
			{
				i+=1;
			}
			if(input[j] > 0)
			{
				j-=1;
			}
		}
	}
	return ;
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
	solve(input,n);
	for(int i=0;i<n;i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}