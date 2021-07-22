// Implement the next permutation, which rearranges numbers into the numerically next greater 
// permutation of numbers. If such arrangement is not possible,
//  it must be rearranged as the lowest possible order ie, sorted in an ascending order.
#include<bits/stdc++.h>
using namespace std;

int findciel(vector<int>& input,int first,int start,int end)
{
	int small_value = input[start];
	int small_i = start;
	for(int i=start+1;i<=end;i++)
	{
		if(input[i] > first)
		{
			if(input[i] < small_value)
			{
				small_value = input[i];
				small_i = i;
			}
		}
	}
	return small_i;
}

void solve(vector<int>& input,int n)
{
	if(n==0)
	{
		return ;
	}
	// find first
	int i;
	for(i=n-2;i>=0;i--)
	{
		if(input[i] < input[i+1])
		{
			break;
		}
	}
	if(i==-1)
	{
		for(int j=n-1;j>=0;j--)
		{
			cout << input[j] << " ";
		}
		cout << endl;
		return ;
	}
	else
	{
		int index = i;
		int ciel_index = findciel(input,input[i],i+1,n-1);
		cout << ciel_index << endl;
		swap(input[index],input[ciel_index]);
		vector<int> :: iterator it = input.begin();
		for(int k=0;k<=index;k++)
		{
			it++;
		}
		sort(it,input.end());
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			cout << input[i] << " ";
		}
	
		cout << endl;
	}
	return ;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> input;
		for(int i=0;i<n;i++)
		{
			int value;
			cin >> value;
			input.push_back(value);
		}
		solve(input,n);
		
	}
	return 0;
}