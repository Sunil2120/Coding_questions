#include<bits/stdc++.h>
using namespace std;


string solve(string input,vector<string>& keypad)
{
	string output;
	for(int i=0;i<input.size();i++)
	{
		if(input[i]==' ')
		{
			output= output + "0";
		}
		else
		{
			output = output + keypad[input[i]-'A'];
		}
	}
	return output;
}

int main()
{
	string input;
	getline(cin,input);
	
	vector<string> keypad = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666",
				"7","77","777","7777","8","88","888","9","99","999","9999"};
	cout << solve(input,keypad) << endl;
}