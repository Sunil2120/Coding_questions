#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


// int F(int root,int n)
// {
// 	return G(root-1)*G(n - root);
// }

// int G(int n)
// {
// 	if(n==0 || n==1)
// 	{
// 		return 1;
// 	}

// 	int sum = 0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		sum += (G(i-1)*G(n-i));
// 	}
// 	return sum;
// }

int G(int n)
{
	int* arr = new int[n+1]();
	arr[0]=1;
	arr[1]=1;

	long long sum = 0;

	for(int i=2;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=i;j++)
		{
			//G(2) = F(1,2) + F(2,2)
			//F(i,n) = G(i-1)*G(n-i)
			sum+= arr[j-1]*arr[i-j];
			sum = sum%MOD;
		}

		arr[i]=sum;
	}
	int ans = arr[n];// G(n)
	delete[] arr;
	return ans;
}


int main()
{
	int n;
	cin >> n;
	cout << G(n) << endl;
	return 0;
}