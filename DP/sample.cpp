#include<bits/stdc++.h>
using namespace std;



string solve(string a,string b,string output)
{
	if(a.size()==0 || b.size()==0)
	{
		return output;
	}

	if(a[0]==b[0])
	{
		output = output + a[0];
		return output;
	}

		string suni =  solve(a.substr(1),b,output);
		string ani =  solve(a,b.substr(1),output);
		if(suni.size() > ani.size())
		{
			return  suni + output;
		}
		else
		{
			return ani + output;
		}
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << solve(a,b,"") << endl;
	return 0;
}