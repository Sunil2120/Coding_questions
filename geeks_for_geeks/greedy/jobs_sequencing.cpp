#include<bits/stdc++.h>
using namespace std;


struct Job
{
	int id;
	int deadline;
	int profit;
};

typedef struct Job Job;

bool compare(Job a,Job b)
{
	return a.profit > b.profit;
}

void solve(vector<Job>& input,int n)
{
	if(n==0)
	{
		return ;
	}
	// sort based on profit
	sort(input.begin(),input.end(),compare);
	bool slot[n];
	Job result[n];
	for(int i=0;i<n;i++)
	{
		slot[i]=false;
		
	}
	// assign the job to the latest time slot(because previous time slots can be assigned to other jobs)
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,input[i].deadline)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=input[i];
				slot[j]=true;
				break;
			}
		}
	}
	int total_profit = 0;
	// print the  job sequence
	for(int i=0;i<n;i++)
	{
		if(slot[i])
		{
			cout << result[i].id << " ";
			total_profit+=result[i].profit;
		}
	}
	cout << endl;
	return ;

}

int main()
{
	int n;
	cin >> n;
	vector<Job> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i].deadline >> input[i].profit;
		input[i].id = i+1;
	}
	solve(input,n);
	return 0;
}