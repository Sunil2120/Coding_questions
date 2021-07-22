#include<bits/stdc++.h>
using namespace std;

string tostring(int val)
{
	string temp = "";
	while(val!=0)
	{
		int suni = val%10;
		temp.push_back(suni+'0');
		val = val/10;
	}
	reverse(temp.begin(),temp.end());
	if(temp=="")
	{
		return "0";
	}
	return temp;
}

string solve(int number)
{
	string output = "";
	int temp = 1000;
	while(number!=0)
	{
		int val = number%temp;
		string suni = tostring(val);
		output  = "."+suni + output;
		number = number/temp;
	}
	output = output.substr(1);
	return output ;
}



int main()
{
	int number ;
	cin >> number;
	if(number <= 999)
	{
		cout << tostring(number) << endl;
		return 0;
	}
	cout << solve(number) << endl;
	return 0;
}