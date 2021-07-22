// Maximum Length of Subarray With Positive Product

// Link to the Problem: Maximum Length of Subarray With Positive Product
// Problem Level: Medium

// Problem Description:
// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
// A subarray of an array is a consecutive sequence of zero or more values taken out of that array. Return the maximum length of a subarray with a positive product.
// Example 1:
// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.




//https://docs.google.com/document/d/1d0tB9IzkLwQPYNT-Tk068CWQfeVhDVsrNLbnX3VZ3Cc/edit
// leetcode contest 204 Q2

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& input,int n)
{
	int positive_length = 0;
	int negative_length = 0;
	int max_length = 0;
	for(int i=0;i<n;i++)
	{
		if(input[i]==0)
		{
			positive_length = 0;
			negative_length = 0;
		}
		else if(input[i] > 0)
		{
			// positive
			positive_length +=1;
			// check whether negative has occured previously
			if(negative_length > 0)
			{
				negative_length+=1;
			}
		}
		else
		{
			// negative
			// we will swap positive and negative
			// check whether negative is occuring for the first time
			if(negative_length == 0)
			{
				negative_length = positive_length + 1;
				positive_length = 0;
			}
			else
			{
				int temp = positive_length;
				positive_length = negative_length + 1;
				negative_length = temp + 1;
			}
			
		}
		max_length = max(max_length,positive_length);
	}
	return max_length;
}

int main()
{
	int n;
	cin >> n;
	vector<int> input;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		input.push_back(val);
	}
	cout << solve(input,n) << endl;
	return 0;
}