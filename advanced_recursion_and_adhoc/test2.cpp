#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	int count = 0;
	int check = 0;
	for(int i=0;i<input.length();i++)
	{
		if(input[i]==check)
		{
			continue;
		}
		else
		{
			check = check^1;
			count+=1;
		}
	}
	cout << count << endl;
}