#include<bits/stdc++.h>
using namespace std;

// Given N jobs where every job is represented by following three elements of it.

// Start Time
// Finish Time
// Profit or Value Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

// 1) First sort jobs according to finish time.
// 2) Now apply following recursive process. 
//    // Here arr[] is array of n jobs
//    findMaximumProfit(arr[], n)
//    {
//      a) if (n == 1) return arr[0];
//      b) Return the maximum of following two profits.
//          (i) Maximum profit by excluding current job, i.e., 
//              findMaximumProfit(arr, n-1)
//          (ii) Maximum profit by including the current job            
//    }


struct node
{
	int start;
	int end;
	int profit;
};
typedef struct node node;

bool compare(node* a,node* b)// we will sort based on ending time
{
	return a->end < b->end;
}
int latest_non_overlap_job(vector<node*>& input,int n)
{
	int low = 0;
	int high = n-2;
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(input[mid]->end <= input[n-1]->start)
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
}

//O(nlogn)
int solve(vector<node*>& input,int n)
{
	if(n==1)
	{
		return input[n-1]->profit;
	}
	// include
	int include_profit = input[n-1]->profit;
	int latest = latest_non_overlap_job(input,n);//binary search
	if(latest!=-1)
	{
		include_profit+=solve(input,latest+1);
	}
	//exclude
	int exclude_profit = solve(input,n-1);
	return max(include_profit,exclude_profit);
}

int main()
{
	int n;
	cin >> n;
	vector<node*> input;
	for(int i=0;i<n;i++)
	{
		node*  temp = new node();
		int start,end,profit;
		cin >> start >> end >> profit;
		temp->start = start;
		temp->end = end;
		temp->profit = profit;
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),compare);
	cout << solve(input,n) << endl;
	return 0;
}