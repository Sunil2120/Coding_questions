#include<bits/stdc++.h>
using namespace std;

int main()
{
	string input;
	cin >> input;
	sort(input.begin(),input.end());
	if(input[0]!='0')
	{
		cout << input << endl;
		return 0;
	}
	int i=0;
	while( i < input.size() && input[i]=='0')
	{
		i++;
	}
	if(i<input.size())
	{
		input[0]=input[i];
		input[i]='0';
	}
	
	cout << input << endl;
	return 0;

}