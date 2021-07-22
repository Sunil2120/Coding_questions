#include<bits/stdc++.h>
using namespace std;



int Modulo(string b,int a)
{
	int n = b.size();
	int mod = 0;
	for(int i=0;i<n;i++)
	{
		mod = (mod*10 + (b[i]-'0'))%a;
	}
	return mod;
}

int expo(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
	int value = expo(a,b/2);
	if(b%2 == 0)
	{
		return value*value;
	}
	return value*value*a;
}

int solve(string a,string b)
{
	if(a.size() == 1 && a=="0")
	{
		return 0;
	}
	 if(b.size() == 1 && b == "0")
     {
        return 1;
     }
	if(Modulo(b,4)==0)
	{
		return expo(a[a.length()-1]-'0',4)%10;
	}
	return expo(a[a.length()-1]-'0',Modulo(b,4))%10;
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << solve(a,b) << endl;
	return 0;
}