#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(int n,int k)
{
	long long* same = new long long[n+1]();
	long long* diff = new long long[n+1]();
	long long* total = new long long[n+1]();
	same[0]=0;
	diff[0]=0;
	total[0]=same[0]+diff[0];
	same[1]=0;
	diff[1]=k;
	total[1]=same[1]+diff[1];
	same[2]=k;
	diff[2]=k*(k-1);
	total[2]=same[2]+diff[2];
	for(int i=3;i<=n;i++)
	{
		//same
		same[i]=diff[i-1]*1;
		same[i]=same[i]%MOD;
		//diff
		diff[i]=(total[i-1]*(k-1))%MOD;// expect last color we can put any colors.
		total[i]=same[i]+diff[i];
		total[i]=(total[i])%MOD;
	}
	int ans  = total[n];
	delete[] diff,same,total;
	return ans;
}

int main()
{
	int n,k;
	cin >> n >> k;// n fences and k colors
	cout << solve(n,k) << endl;
	return 0;

}