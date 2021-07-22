#include<bits/stdc++.h>
using namespace std;


int max_cost(int* input,int n)
{
	int* output = new int[n]();
	output[n-1]=input[n-1];
	output[n-2]=input[n-2];
	int max_ = (output[n-1] > output[n-2])?output[n-1]:output[n-2];
	int temp = 0;
	for(int i=n-3;i>=0;i--)
	{
		for(int j = i+2; j<n;j++)
		{
			if(output[j] > temp)
			{
				temp = output[j];
			}
		}
		output[i]= temp + input[i];
		if(output[i] > max_)
		{
			max_ = output[i];
		}
		temp = 0;
	}
	delete []output;
	return max_;
}

int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << max_cost(input,n) << endl;
	delete []input;
	return 0;
}