#include<bits/stdc++.h>
using namespace std;


long min_cost(long* input,int n)
{
	long total = 0;
	int curr = 0;
	while(curr < n-1)
	{
		int next = curr + 1;
		while(next < n-1)
		{
			if((abs(input[curr]) > abs(input[next])) || (abs(input[curr])==abs(input[next]) && input[curr] > 0))
			{
				break;// we will find a j
			}
			next+=1;
		}
		total += (next - curr)*input[curr] + (next*next - curr*curr)*input[curr]*input[curr];
		curr = next;
	}
	return total;
}

int main()
{
	int n;
	cin >> n;
	long* input = new long[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << min_cost(input,n) << endl;
	return 0;
}