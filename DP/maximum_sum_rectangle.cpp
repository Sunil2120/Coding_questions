#include<bits/stdc++.h>
using namespace std;


// naive method o(n power of 4)
int maximum_rect(int** input,int m,int n)
{
	int sum = 0;
	int max = INT_MIN;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=i;k<m;k++)
			{
				for(int h=j;h<n;h++)
				{
					sum+=input[k][h];
				}
			}
			if(sum > max)
			{
				max = sum;
			}
			sum = 0;
		}
	}
	return max;
}

// using kadane's algorithm

int kadane(int* arr,int n)
{
	int max = 0;
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		cur+=arr[i];
		if(cur < 0)
		{
			cur = 0;
		}
		if(cur  > max)
		{
			max = cur;
		}
	}
	return max;
}

int maximum_rect2(int** input,int m,int n)
{
	int* output = new int[m]();
	int max_ = 0;
	for(int j=0;j<n;j++)
	{
		for(int k=j;k<n;k++)
		{

			for(int i=0;i<m;i++)
			{
				output[i]+=input[i][k];
			}
			int kd = kadane(output,m);
			//cout << k << endl;
			if(kd > max_)
			{
				max_ = kd;
			}
		}
		for(int ii=0;ii<m;ii++)
		{
			output[ii]=0;
		}
		
		// for(int i=0;i<m;i++)
		// {
		// 	 cout << output[i] << " ";
		// }
		// cout << endl;

		
	}

	delete []output;

	return max_;

}


int main()
{
	int m,n;
	cin >> m >> n;
	int** input = new int*[m];
	for(int i=0;i<m;i++)
	{
		input[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> input[i][j];
		}
	}

	if(maximum_rect2(input,m,n)==0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << maximum_rect2(input,m,n) << endl;
	}
	delete []input;
	return 0;
}