#include<bits/stdc++.h>
using namespace std;

int count_palindrome(string input)
{
	int left = 0;
	int right = 0;
	int count = INT_MIN;
	for(int i=0;i<input.size();i++)
	{
		// odd
		left = i;
		right = i;
		while(left >=0 && right < input.size() &&  input[left]==input[right])
		{
			count  = max(count,right-left+1);
			left--;
			right++;
		}
		//even
		left = i;
		right=i+1;
		while(left >=0 && right < input.size() && input[left]==input[right])
		{
			count  = max(count,right-left+1);
			left--;
			right++;
		}
	}
	return count;
}

void solve(string input,int n)
{
	
	for(int i=0;i<n;i++)
	{
		cout << count_palindrome(input.substr(0,i+1)) << " ";
	}
	cout << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	string input;
	cin >> input;
	solve(input,n);
	return 0;
}