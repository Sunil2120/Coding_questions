#include<bits/stdc++.h>
using namespace std;

// Next Greater Element
// Last Updated: 24-07-2019
// Given an array, print the Next Greater Element (NGE) for every element. 
// The Next greater Element for an element x is the first greater element on the right side of x in array. 
// Elements for which no greater element exist, consider next greater element as -1.

// Method 2 (Using Stack)

// Push the first element to stack.
// Pick rest of the elements one by one and follow the following steps in loop.
// Mark the current element as next.
// If stack is not empty, compare top element of stack with next.
// If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
// Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
// Finally, push the next in the stack.
// After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.


// method 1 using two for loops O(n2)

// method 2 using stacks O(n)
void solve(vector<int>& arr,int n)
{
	if(n==0)
	{
		return ;
	}
	vector<int> s;
	s.push_back(arr[0]);
	unordered_map<int,int> hash;
	for(int i=1;i<n;i++)
	{
		while(s.size()!=0 && s.back() < arr[i])
		{
			hash[s.back()]=arr[i];
			s.pop_back();
		}
		s.push_back(arr[i]);
	}
	while(s.size()!=0)
	{
		hash[s.back()]=-1;
		s.pop_back();
	}
	for(int i=0;i<n;i++)
	{
		cout << hash[arr[i]] << " ";
	}
	cout << endl;
	return ;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve(arr,n);
	return 0;
}