//leetcode question
#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	string temp ="";
	int i=0;
	while(i<input.length())
	{
		char check = input[i];
		int j = i+1;
		int count = 1;
		while(input[j]==check && j<input.length())
		{
			j++;
			count+=1;
		}
		if(count>1)
		{
			char c = (char) count + '0';
			temp.push_back(check);
			temp.push_back(c);
			i=j;
		}
		else
		{
			temp.push_back(check);
			i+=1;
		}
	}
	cout << temp << endl;
}