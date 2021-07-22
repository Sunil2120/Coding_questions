#include<bits/stdc++.h>
using namespace std;


// given an array output the min swaps to sort the array
// method-1 using selection sort

// time complexity O(n^2)
// space complexity O(1)
int get_min(vector<int>& arr,int start,int n)
{
	int min_value = INT_MAX;
	int min_index = -1;
	for(int i=start+1;i<n;i++)
	{
		if(arr[i] < arr[start])
		{
			if(arr[i] < min_value)
			{
				min_value = arr[i];
				min_index = i;
			}
		}
		
	}
	return min_index;
}
int solve(vector<int>& arr,int n)
{
	int i=0;
	if(n==0)
	{
		return 0;
	}
	int count = 0;
	while(i<n-1)
	{
		int index = get_min(arr,i,n);
		//swap
		if(index!=-1)
		{
			int temp = arr[i];
			arr[i]=arr[index];
			arr[index]=temp;
			count+=1;
		}
		i+=1;
	}
	return count;
}

//graphical method

// This can be easily done by visualizing the problem as a graph. We will have n nodes and an edge directed from node i to node j 
// if the element at i’th index must be present at j’th index in the sorted array. 
// The graph will now contain many non-intersecting cycles. Now a cycle with 2 nodes will only require 1 swap to reach the correct ordering, similarly, 
// a cycle with 3 nodes will only require 2 swaps to do so. 
// time complexity O(nlogn)=> sorting
// space complexity O(n)=> visited array
int solve2(vector<int>& arr,int n)
{
	if(n==0)
	{
		return 0;
	}
	vector<bool> visited(n,false);
	vector<pair<int,int>> temp;
	for(int i=0;i<n;i++)
	{
		temp.push_back(make_pair(arr[i],i));
	}
	//sort the temp array
	// by default it will sort on first
	sort(temp.begin(),temp.end());
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==true || temp[i].second==i)// if visited or element is in correct position
		{
			continue;
		}
		int j=i;
		int cycle_size = 0;

		while(visited[j]==false)
		{
			visited[j]=true;
			j = temp[j].second;
			cycle_size+=1;
		}
		if(cycle_size > 0)
		{
			count+=cycle_size-1;// if cycle has n nodes then the number of swaps required to sort is n-1
		}
	}
	return count;
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
	cout << solve2(arr,n) << endl;

}