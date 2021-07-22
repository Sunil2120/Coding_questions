#include<bits/stdc++.h>
using namespace std;


int findciel(string input,char first,int start,int end)
{
	char small_char = input[start];
	int small_i = start;
	for(int i=start+1;i<=end;i++)
	{
		if(input[i] > first)
		{
			if(input[i] < small_char)
			{
				small_char = input[i];
				small_i = i;
			}
		}
	}
	return small_i;
}

// time complexity o(n!*n) if we use reverse
// time complexity o(n!*n^2) if we use sort
void solve(string input)
{
	// sort the given string
	sort(input.begin(),input.end());
	bool isfinished = false;
	int n = input.size();
	while(isfinished==false)
	{
		cout << input  << endl;
		//step1 : find the right most  character which is smaller than it's next character
		int i;
		for(i=n-2;i>=0;i--)
		{
			if(input[i] < input[i+1])
			{
				break;
			}
		}
		if(i==-1)// there is no right most character (sorted in decending order)
		{
			isfinished = true;// while loop breaks
		}
		else
		{
			//step2 : smallest character on the  right of first character which is greater than first
			int index = i;
			// second character
			int ciel_index = findciel(input,input[i],i+1,n-1);
			//step3 : swapp first character and second character
			swap(input[index],input[ciel_index]);
			// step4 : sort everything after the index of first character
			string temp = input.substr(index+1);
			// optimized solution is instead of sort just reverse it(after reverse it will be sorted only)
			//sort(temp.begin(),temp.end());
			reverse(temp.begin(),temp.end());
			input = input.substr(0,index+1)+temp;
		}
	}
	return ;
}

int main()
{
	string input;
	cin >> input;
	solve(input);
	return 0;
}