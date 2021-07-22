#include<bits/stdc++.h>
using namespace std;


void solve(string a,string b,int m,int n,char* temp,int index)
{
	if(m==0 && n==0)
	{
		cout << temp << endl;
	}
	if(m!=0)
	{
		temp[index]=a[0];
		solve(a.substr(1),b,m-1,n,temp,index+1);
	}
	if(n!=0)
	{
		temp[index]=b[0];
		solve(a,b.substr(1),m,n-1,temp,index+1);
	}
	return ;
}


int main()
{
	string a,b;
	cin >> a >> b;
	char* temp = new char[a.size()+b.size()+1];
	temp[a.size()+b.size()]='\0';

	solve(a,b,a.size(),b.size(),temp,0);
	return 0;
}