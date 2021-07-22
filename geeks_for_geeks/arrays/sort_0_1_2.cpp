#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>& input,int n)
{
	if(n==0)
	{
		return ;
	}
	int low = 0;
	int mid = 0;
	int high = n-1;
	while(mid <= high)
	{
		if(input[mid]==0)
		{
			int temp = input[low];
			input[low]=input[mid];
			input[mid]=temp;
			low+=1;
			mid+=1;
		}
		else if(input[mid]==1)
		{
			mid+=1;
		}
		else
		{
			int temp = input[mid];
			input[mid]=input[high];
			input[high]=temp;
			high--;
		}
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	solve(input,n);
	for(int i=0;i<n;i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}