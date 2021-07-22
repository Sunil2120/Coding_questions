#include<bits/stdc++.h>
using namespace std;
// Largest rectangle area in a histogram
// refer pepcoding youtube channel

// O(n^2)
int solve(vector<int>& arr,int n)
{
	int max_value = INT_MIN;
	for(int i=0;i<n;i++)
	{
		//considering arr[i] as base
		int left = i-1;
		int right = i+1;
		int area = 1;
		while(left >=0 && arr[left] >= arr[i])
		{
			area+=1;
			left--;
		}
		while(right < n && arr[right] >= arr[i])
		{
			area+=1;
			right++;
		}
		area = area*arr[i];
		max_value = max(max_value,area);
	}
	return max_value;
}

// O(n) using stacks
int solve2(vector<int>& arr,int n)
{
	int* lb = new int[n];// stores next smallest element in left
	int* rb = new int[n];// stores next smallest element in right
	stack<int> a;
	stack<int> b;
	// storing next smallest element in left(we are storing the index not value)
	// for the first element next smallest element in left is -1;
	lb[0]=-1;
	a.push(0);
	for(int i=1;i<n;i++)
	{
		// we will pop until we get element smaller than cur element
		while(a.size() > 0 && arr[a.top()] >= arr[i])
		{
			a.pop();
		}
		// if stack is empty no smallest elements on left
		if(a.size()==0)
		{
			lb[i]=-1;
		}
		else
		{
			lb[i]=a.top();
		}
		a.push(i);
	}

	// storing next smallest element in right(storing indices)
	// for the last element next smallest element in right is n
	// we are traversing from end so the we will get to know the 
	// smallest element which will come after cur element
	rb[n-1]=n;
	b.push(n-1);
	for(int i=n-2;i>=0;i--)
	{
		while(b.size() > 0 && arr[b.top()] >= arr[i])
		{
			b.pop();
		}
		if(b.size() == 0)
		{
			rb[i]=n;
		}
		else
		{
			rb[i]=b.top();
		}
		b.push(i);
	}
	int max_area = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int width = (rb[i]-lb[i]-1);//(rb[i]-lb[i]+1-2)
		int height = arr[i];
		int area = width*height;
		max_area = max(max_area,area);
	}
	delete[] lb;
	delete[] rb;
	return max_area;
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
	cout << solve(arr,n) << endl;
	cout << solve(arr,n) << endl;
	return 0;
}