#include<bits/stdc++.h>
using namespace std;

// You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. 
// A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. 
// Calculate the minimum number of swaps necessary to make a string balanced.


// o(n^2) and o(1) auxillary space
int solve(string input,int n)
{
	if(n==0)
	{
		return 0;
	}
	int open=0;
	int count = 0;
	int i=0;
	while(i<n)
	{
		if(input[i]=='[')
		{
			open+=1;
		}
		else
		{
			if(open==0)
			{
				int j;
				for(j=i+1;j<n;j++)
				{
					if(input[j]=='[')
					{
						break;
					}
				}
				for(int k=j;k>=i-1;k--)
				{
					swap(input[k],input[k-1]);
				}
				count+=(j-i);
				//cout << count << endl;
				i+=1;
			}
			else
			{
				open-=1;
			}
		}
		i+=1;
	}
	return count;
}

// optimized solution o(n) and extra space o(n)
int solve1(string input,int n)
{
	vector<int> open;
	for(int i=0;i<n;i++)
	{
		if(input[i]=='[')
		{
			open.push_back(i);
		}
	}
	int p=0;// p will be pointing to the index of next opening bracket.
	int count = 0;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(input[i]=='[')
		{
			count+=1;
			p+=1;
		}
		else
		{
			if(count>0)
			{
				count--;
			}
			else// start swapping
			{
				sum+= (open[p] - i);
				swap(input[i],input[open[p]]);
				p+=1;
				count=1;// next iteration count become 0
			
			}
		}
	}
	return sum;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string input;
		cin >> input;
		cout << solve1(input,n) << endl;
	}
	return 0;
}