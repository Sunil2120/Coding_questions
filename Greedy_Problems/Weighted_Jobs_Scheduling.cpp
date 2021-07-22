#include<bits/stdc++.h>
using namespace std;



struct Job
{
	int start,finish,profit;
};

bool compare(Job a,Job b)
{
	return a.finish < b.finish;
}


int Weighted_Jobs_Scheduling(Job* input,int n)
{
	if(n==0)
	{
		return 0;
	}
	// sorting jobs on basis of finishing time(increasing order)
	sort(input,input+n,compare);
	int* output = new int[n];
	int total = 0;
	output[0]=input[0].profit;
	for(int i=1;i<n;i++)
	{
		// including
		int latest = -1;
		// for(int j=i-1;j>=0;j--)
		// {
		// 	if(input[j].finish <= input[i].start)
		// 	{
		// 		latest = j;
		// 		break;
		// 	}
		// }
		int start = 0;
		int end = i-1;
		while(start <= end)
		{
			int mid = (start + end)/2;
			if(input[mid].finish <= input[i].start)
			{
				latest = mid;
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		if(latest == -1)// latest non conflict not present
		{
			output[i] = max(input[i].profit,output[i-1]);
			continue;
		}
		
		int temp1 =	input[i].profit + output[latest];// including
		int temp = output[i-1];// not including
		output[i]=max(temp1,temp);
	}
	int ans = output[n-1];
	delete[] output;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	Job* input = new Job[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i].start >> input[i].finish >> input[i].profit;
	}
	cout << Weighted_Jobs_Scheduling(input,n) << endl;
	delete[] input;
	return 0;

}