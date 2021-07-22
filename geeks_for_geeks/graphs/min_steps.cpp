#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int index,int n)
{
	if(index>=n-1)
	{
		return 0;
	}
	int temp = arr[index];
	int min_x = INT_MAX;
	for(int i=1;i<=temp;i++)
	{
		int val = solve(arr,index+i,n);
		min_x = min(min_x,val);
	}
	return min_x+1;
}

// o(n) time and o(1) auxillary space
int solve1(vector<int>& arr,int n)
{
	 int max_ladder = arr[0];
	 int steps = arr[0];
	 int jumps = 1;
	 for(int i=1;i<n;i++)
	 {
	 	// update max
	 	if(i==n-1)
	 	{
	 		return jumps;
	 	}
	 	max_ladder = max(max_ladder,arr[i]+i);// arr[i]+i max destination can reach
	 	steps--;
	 	if(steps < 0)
	 	{
	 		return -1;
		}
	 	if(steps==0)
	 	{
	 		jumps+=1;
	 		steps = max_ladder - i;
	 		if(steps<=0)
	 		{
	 			return -1;
	 		}
	 	}
	 }
	 return -1;
}

int main()
{
	 int n;
	 cin >> n;
	 vector<int> arr;
	 for(int i=0;i<n;i++)
	 {
	 	int val;
	 	cin >> val;
	 	arr.push_back(val);
	 }
	 cout << solve1(arr,n) << endl;
}