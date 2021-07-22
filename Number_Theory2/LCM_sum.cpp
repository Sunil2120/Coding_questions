// lcm sum
// given n we should calculate s=lcm(1,n)+lcm(2,n)+lcm(3,n)+_ _  _ + lcm(n,n)
// s = n/2*(sumation d*phi(d)-1)

#include<bits/stdc++.h>
using namespace std;


long long gcd(long long a,long long b)
{
	if(b>a)
	{
		return gcd(b,a);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
long long  lcm_sum(long long n)
{
	long long sum = 0;
	for(int i=1;i<=(n-1);i++)
	{
		sum+= (n*n)/gcd(i,n);
	}
	sum = sum/2;
	sum = sum + n;
	return sum;
}




int main()
{
	long long n;
	cin >> n;
	cout << lcm_sum(n) << endl;
	return 0;

}