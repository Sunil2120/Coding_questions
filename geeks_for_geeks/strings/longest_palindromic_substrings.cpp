#include<bits/stdc++.h>
using namespace std;

string solve(string input)
{
	int li,ri;
	int max_size = 0;
	for(int i=0;i<input.size();i++)
	{
		// odd length
		string temp;
		int left = i;
		int count = 0;
		int right = i;
		while(left>=0 && right <input.size() && input[left]==input[right])
		{
			count = right - left + 1;
			if(count > max_size)
			{
				max_size = count;
				li = left;
				ri = right;
				
			}
			left--;
			right++;
			
		}

		// even length
		left = i;
		right = i+1;
		count = 0;
		while(left >=0 && right < input.size() && input[left]==input[right])
		{
			count = right - left + 1;
			if(count > max_size)
			{
				max_size = count;
				li = left;
				ri = right;
				
			}
			left--;
			right++;
		}
	}
	return input.substr(li,max_size);
}

bool check(string input)
{
	int i=0;
	int j=input.size()-1;
	while(i<=j && i<input.size() && j>=0)
	{
		if(input[i]!=input[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

// o(n^3) time outer for loop o(n2)* check palindrome funcion o(n)
string  solve2(string input)
{
	string max_;
	int max_size = 0;
	for(int i=0;i<input.size()-1;i++)
	{
		string temp = "";
		temp+=input[i];
		for(int j=i;j<input.size();j++)
		{
			temp=temp+input[j];
			// check palindrome
			if(check(temp))
			{
				if(temp.size() > max_size)
				{
					max_size = temp.size();
					max_ = temp;
				}
			}
		}
	}
	return max_;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		cout << solve(input) << endl;
		cout << solve2(input) << endl;
	}
	return 0;
}