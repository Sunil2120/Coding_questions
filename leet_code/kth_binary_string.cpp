#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	if((k%2)==0)
	{
		cout << "1" << endl;
		return 0;
	}
	if(k==0)
	{
		cout << "0" << endl;
		return 0;
	}
	string temp ="0";
	int i=2;
	while(i<=n)
	{
		cout << "hello" << endl;
		cout << temp << endl;
		string suni = temp;
		temp=temp+"1";
		reverse(suni.begin(),suni.end());
		for(int i=0;i<suni.size();i++)
		{
			if(suni[i]=='0')
			{
				suni[i]='1';
			}
			else
			{
				suni[i]='0';
			}
		}
		temp = temp+suni;
		i++;
	}
	cout << temp << endl;
	cout << temp[k-1] << endl;
	return 0;
}