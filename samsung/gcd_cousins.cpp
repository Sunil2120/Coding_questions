#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b > a)
	{
		gcd(b,a);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[2];
		int f,s;
		cin >> f >> s;
		arr[i][0]=f;
		arr[i][1]=s;
	}

	int max_gcd = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i][0]==arr[j][0])
			{
				max_gcd = max(max_gcd,gcd(arr[i][1],arr[j][1]));
			}
		}
	}
	cout << max_gcd << endl;
}