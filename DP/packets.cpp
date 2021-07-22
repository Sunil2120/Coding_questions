#include<bits/stdc++.h>
using namespace std;


void solve(int n,int k,int* children)
{
	int value = 0;
	int count  = children[0];
	int mi = INT_MAX;

	for(int i=1;i<k;i++)
	{
		count+=children[i];
		value = value + i*(children[i]) - (count - children[i]);
	}
	if(value < mi)
	{
		mi = value;
	}
	count = 0;

	for(int i=1;i<=n-k;i++)
	{
	// 	for(int j=i;j<i+k-1;j++)
	// 	{
	// 		count+= children[j];
	// 	}

	// 	value = value - 2*(count) +  (k-1)*children[i-1] + children[k+1]*(k-1);



		// int suni = 0;
		// for(int j=i;j<i+k-1;j++)
		// {
		// 	suni+=(children[j]-children[i-1]);
		// }

		// int ani = 0;
		// for(int j=i;j<i+k-1;j++)
		// {
		// 	ani+=(children[i+k-1]-children[j]);
		// }


		//value = value - suni + ani;

			// for(int j=i;j<i+k-1;j++)
			// {
			// 	count+=children[j];
			// }
		count = count - children[i-1];
		value = value - 2*count + (k-1)*children[i-1] + (k-1)*children[i+k-1];
		if(value < mi)
		{
			mi = value;
		}
		count = count + children[i];

	}

	cout << mi << endl;

	return ;
}


int main()
{
	int n,k;
	cin >> n >> k;
	int* children = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> children[i];
	}
	sort(children,children+n);
	solve(n,k,children);
	return 0;
}