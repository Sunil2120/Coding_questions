#include<bits/stdc++.h>
using namespace std;


int solve(string input,int k)
{
	//only lowercase
	int* arr = new int[26]();// count of each characters
	for(int i=0;i<input.size();i++)
	{
		arr[input[i]-'a']+=1;
	}
	int value = 0;
	// max heap
	priority_queue<int> maxheap;
	//min heap
	//priority_queue<int,vector<int>,greater<int>> minheap;
	for(int i=0;i<26;i++)
	{
		if(arr[i] > 0)
		{
			maxheap.push(arr[i]);
			value +=(arr[i]*arr[i]);
		}
	}
	cout << maxheap.top() << endl;
	while(k--)
	{
		int cur = maxheap.top();
		value = value + 1 - (2*cur);
		maxheap.pop();
		maxheap.push(cur-1);
	}
	return value;
}

int main()
{
	string input;
	cin >> input;
	int k;
	cin >> k;
	cout << solve(input,k) << endl;
	return 0;
}