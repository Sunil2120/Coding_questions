// permutation coefficient is the number of ways k can elements can be arranged from a set of n elements
// 1-method p(n,k)=p(n-1,k)+k*p(n-1,k-1)
// 2-method p(n,k)=n!/(n-k)!
// compute all factorial from 1 to n
// and get the p(n,k) in constant time
#include<bits/stdc++.h>
using namespace std;

// o(n) and o(n) time and space
int solve(int n,int k)
{
	if(k > n)
	{
		return 0;
	}
	int* fact = new int[n+1];
	fact[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=i*fact[i-1];
	}
	int ans = (fact[n])/(fact[n-k]);
	delete[] fact;
	return ans;
}
// o(k) time and o(1) space
int solve2(int n,int k)
{
	if(k > n)
	{
		return 0;
	}
	int ans = 1;
	for(int i=0;i<k;i++)
	{
		ans = ans*(n-i);
	}
	return ans;
}

int main()
{
	int n,k;
	cin >> n >> k;
	//cout << solve(n,k) << endl;
	cout << solve2(n,k) << endl;

	return 0;

}