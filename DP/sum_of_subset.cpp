#include<bits/stdc++.h>
using namespace std;


bool sum_of_subset(int n,int value,int* input)
{
	// base case
	if(n==0)
	{
		if(value!=0)
		{
			return false;
		}
		return true;
	}

	if(value==0)
	{
		return true;
	}
	if(input[n-1] <= value)
	{
		return (sum_of_subset(n-1,value,input) || sum_of_subset(n-1,value-input[n-1],input));

	}
	return sum_of_subset(n-1,value,input);

}

// iterative
bool sum_of_subset2(int n,int value,int* input)
{
	bool** output = new bool*[n+1];// rows(no of items)
	for(int i=0;i<=n;i++)
	{
		output[i]=new bool[value+1];// col(value)
	}
	// base case

	// if n==0 and value ==0 
	output[0][0]=true;
	// if n==0
	for(int i=1;i<=value;i++)
	{
		output[0][i]=false;
	}
	// every set has a empty subset
	for(int i=1;i<=n;i++)
	{
		output[i][0]=true;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=value;j++)
		{
			if(input[i-1] <= j)
			{
				output[i][j]= output[i-1][j] || output[i-1][j-input[i-1]];
			}
			else
			{
				// don't include
				output[i][j]= output[i-1][j];
			}
		}
	}
	bool ans = output[n][value];
	for(int i=0;i<=n;i++)
	{
		delete[] output[i];
	}
	delete[] output;
	return ans;


}

int main()
{

	int n,value;
	cin >> n >> value;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout  << sum_of_subset(n,value,input) << endl;
	cout  << sum_of_subset2(n,value,input) << endl;
	return 0;
}