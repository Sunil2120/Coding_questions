#include<bits/stdc++.h>
using namespace std;

// recurrsion
int solve(int* arr,int n,int start)
{
	if(start>=n-1)
	{
		return 0;
	}
	if(arr[start]==0)
	{
		return INT_MAX;
	}
	int min_ = INT_MAX;
	for(int i=1;i<=arr[start];i++)
	{
		int temp = solve(arr,n,start+i);
		min_ = min(temp,min_);
	}
	return min_ + 1;
}

void print_jumps(int* parent,int n,int start)
{
	cout << start << " ";
	if(parent[start]==-1)
	{
		return ;
	}
	return print_jumps(parent,n,parent[start]);
}

// DP o(n2)
int solve1(int* arr,int n)
{
	int* parent = new int[n]();
	int* jumps = new int[n];
	for(int i=0;i<n;i++)
	{
		jumps[i]=-1;
	}
	jumps[0]=0;
	parent[0]=-1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((arr[j]+j)>=i)// reachable
			{
				if(jumps[i]==-1)
				{
					jumps[i]=jumps[j]+1;
					parent[i]=j;
				}
				else
				{
					// min(jumps[i],jumps[j]+1)
					if(jumps[i] > (jumps[j]+1))
					{
						jumps[i]=jumps[j]+1;
						parent[i]=j;
					}
				}
			}
		}
	}
	// to print parent and where we jumped
	print_jumps(parent,n,n-1);
	cout << endl;

	int ans = jumps[n-1];
	delete[] jumps;
	delete[] parent;
	return ans;

}

// optimized solution o(n)
int solve3(int* arr,int n)
{
	int max_ladder = 0;
	int steps = 0;
	int jumps = 0;
	// intially
	max_ladder=arr[0];
	steps =arr[0];
	if(steps==0)
    {
        return -1;
    }
	int ans = 0;
	jumps = 1;// climbing the first ladder
	for(int i=1;i<=n-1;i++)
	{
		if(i==n-1)
		{
			ans = jumps;
			break;
		}
		// update max_ladder
		int temp = max_ladder;
		max_ladder = max(max_ladder,arr[i]+i);// arr[i]+i  max destination current node can reach
		steps--;
		if(steps==0)
		{
			// current ladder got over so we need to jumps on to max_ladder
			steps = max_ladder - i;
			jumps++;
			if(steps<=0)
			{
				return -1;
			}
			
		}
	}
	return ans;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}

		cout << solve3(arr,n) << endl;
		cout << solve1(arr,n) << endl;
		delete[] arr;
	}
}