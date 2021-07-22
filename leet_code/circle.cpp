#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int boarding_cost,int running_cost)
{
	vector<int> output;
	int waiting = 0;
	int arrived = 0;
	int board = 0;
	int cur = 1;
	for(int i=0;i<arr.size();i++)
	{
		arrived = arr[i];
		int cost = 0;
		if(waiting >= 4)
		{
			board+=4;
			waiting-=4;
			cost = (board*boarding_cost) - (cur*running_cost);
			output.push_back(cost);
		}
		else
		{
			board+=waiting;
			if(arrived >=(4-waiting))
			{
				board+=4-waiting;
				arrived = arrived - (4-waiting);
			}
			waiting = 0;
			cost = (board*boarding_cost)-(cur*running_cost);
			output.push_back(cost);
		};
		waiting = arrived+waiting;
		cur+=1;
	}
	while(waiting!=0)
	{
		int cost = 0;
		if(waiting >=4)
		{
			board+=4;
			waiting-=4;
			cost = (board*boarding_cost) - (cur*running_cost);
			output.push_back(cost);
		}
		else
		{
			board+=waiting;
			waiting = 0;
			cost = (board*boarding_cost)-(cur*running_cost);
			output.push_back(cost);
		}
		cur+=1;
	}
	int max_value = INT_MIN;
	int max_i = -1;
	for(int i=0;i<output.size();i++)
	{
		if(output[i]< 0)
		{
			continue;
		}
		if(output[i] > max_value)
		{
			max_value = output[i];
			max_i = i;
		}
	}
	if(max_value == INT_MIN)
	{
		return -1;
	}
	return max_i+1;
}


int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int boarding_cost  = 0;
	int running_cost = 0;
	cin >> boarding_cost >> running_cost;
	cout << solve(arr,boarding_cost,running_cost) << endl;
	return 0;
}