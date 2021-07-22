#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	string output;
	for(int i=0;i<input.size();i++)
	{
		if(input[i] < 97)
		{
			input[i] = input[i] + 32;
		}
		if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || input[i]=='y')
		{
			continue;
		}
		else
		{
			output+=".";
			output.push_back(input[i]);
		}
	}
	cout << output << endl;
}