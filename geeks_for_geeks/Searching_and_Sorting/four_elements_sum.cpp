#include<bits/stdc++.h>
using namespace std;

// Time O(n^4log(all possible quadrats))  space O(all possible quadrats)
void solve1(vector<int>& arr,int n,int k)
{
	vector<vector<int>> output;
	if(n < 4)
	{
		return ;
	}
	set<vector<int>> s;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-3;i++)
	{
		for(int j=i+1;j<n-2;j++)
		{
			for(int k=j+1;k<n-1;k++)
			{
				for(int h=k+1;h<n;h++)
				{
					if((arr[i]+arr[j]+arr[k]+arr[h]) == k)
					{
						cout << (arr[i]+arr[j]+arr[k]+arr[h]) << endl;
						s.insert({arr[i],arr[j],arr[k],arr[h]});
					}
				}
			}
		}
	}
	for(auto it:s)
	{
		output.push_back(it);
	}
	for(int i=0;i<output.size();i++)
	{
		for(int j=0;j<output[i].size();j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	return ;

	
}

//  time O(n^3) space O(n^2)
void solve2(vector<int>& arr,int n,int k)
{
	if(n < 4)
	{
		return ;
	}
	set<vector<int>> s;
	vector<vector<int>> output;
	sort(arr.begin(),arr.end());
	for(int i=0;i<(n-4);i++)
	{
		for(int j=i+1;j<=(n-3);j++)
		{
			int target = k - (arr[i]+arr[j]);
			int left = j+1;
			int right = n-1;
			while(left < right)
			{
				int sum = arr[left]+arr[right];
				if(sum == target)
				{
					s.insert({arr[i],arr[j],arr[left],arr[right]});
					left++;
				}
				else if(sum < target)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}
	for(auto it:s)
	{
		output.push_back(it);
	}
	for(int i=0;i<output.size();i++)
	{
		for(int j=0;j<output[i].size();j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	return ;
}
int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve2(arr,n,k);
	return 0;
}