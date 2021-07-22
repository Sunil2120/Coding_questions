#include<bits/stdc++.h>
using namespace std;


string lottery(int n,int value)
{
	// we need minimum value so first digit should be minimum so let it be 1
	string num ="";
	int key = value - 1;
	for(int i=1;i<n;i++)
	{
		if(key > 9)
		{
			key = key - 9;
			num.push_back('9');
		}
		else
		{
			num.push_back((key + '0'));
			key = 0;
		}
	}
	num.push_back((key + 1 + '0'));
	string num2="";
	for(int i=n-1;i>=0;i--)
	{
		num2.push_back(num[i]);
	}
	return num2;
}



int main()
{
	int n;
	cin >> n;
	int value;
	cin >> value;
	cout << lottery(n,value) << endl;
	return 0;
}