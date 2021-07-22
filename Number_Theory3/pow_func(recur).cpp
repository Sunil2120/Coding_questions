// power(a,b)
#include<bits/stdc++.h>
using namespace std;


// normal approach o(b)
int power1(int a,int b)
{
	//base case
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	return a*power1(a,b-1);
}

// optimized solution-1 
//o(log(b))
int power2(int a,int b)
{
	//base case
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	int value = power2(a,b/2);
	int ans;
	if((b%2)==0)// b is even
	{
		ans = value*value;
	}
	else // b is odd
	{
		ans = value*value*a;

	}
	return ans;

}

//optimized solution-2 
// b can be very large a**b can go beyond long long so we need to take mod of some integer
// o(log(b))

int power3(int a,int b,int c)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	long long value = power3(a,b/2,c);
	long long ans;
	if((b%2)==0)// b is even
	{
		ans = value*value;
		ans = ans%c;
	}
	else // b is odd
	{
		ans = value*value;
		// a can be large too
		ans = ans*(a%c);
		ans = ans%c;
	}
	// ans can be negative
	return (int)(ans+c)%c;
}
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << power3(a,b,c) << endl;
	cout << power2(a,b) << endl;
	cout << power1(a,b) << endl;
	return 0;
}