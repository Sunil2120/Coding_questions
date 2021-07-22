#include<bits/stdc++.h>
using namespace std;

// recursion
int solve1(int* first,int* second,int** time,int n,int cur,int line,int* exit)
{
	if(cur==n-1)
	{
		if(line==0)
		{
			return exit[line]+first[cur];
		}
		else
		{
			return exit[line]+second[cur];
		}
	}
	// same line
	int temp1 = solve1(first,second,time,n,cur+1,line,exit);
	// diff line
	int temp2 = solve1(first,second,time,n,cur+1,line^1,exit)+time[line][cur];
	int total = min(temp1,temp2);

	if(line==0)
	{
		total+=first[cur];
	}
	else
	{
		total+=second[cur];
	}
	return total;
}

int solve(int* first,int* second,int* entry,int* exit,int n,int** time)
{
	// we will start from first line
	int value = solve1(first,second,time,n,0,0,exit)+entry[0];
	int svalue = solve1(first,second,time,n,0,1,exit)+entry[1];
	cout << value << " " << svalue << endl;
	return min(value,svalue);
}

// iterative
int solve3(int* first,int* second,int* entry,int* exit,int n,int** time)
{
	int* line0 = new int[n]();
	int* line1 = new int[n]();
	line0[n-1]=first[n-1]+exit[0];
	line1[n-1]=second[n-1]+exit[1];
	for(int i=n-2;i>=0;i--)
	{
		// first
		int temp1 = line0[i+1];
		int temp2 = line1[i+1]+time[0][i];
		line0[i]=min(temp1,temp2)+first[i];
		// second
		temp1 = line1[i+1];
		temp2 = line0[i+1]+time[1][i];
		line1[i]=min(temp1,temp2)+second[i];
	}
	line0[0]+=entry[0];
	line1[0]+=entry[1];
	int ans = min(line0[0],line1[0]);
	delete[] line1,line0;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int* first = new int[n];
	int* second = new int[n];
	int** time = new int*[2];
	for(int i=0;i<2;i++)
	{
		time[i]=new int[n]();
	}
	for(int i=0;i<n;i++)
	{
		cin >> first[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> second[i];
	}

	// entries time
	int* entry = new int[2];
	int* exit = new int[2];
	for(int i=0;i<2;i++)
	{
		cin >> entry[i];
	}
	for(int i=0;i<2;i++)
	{
		cin >> exit[i];
	}
	// time
	for(int i=0;i<n-1;i++)
	{
		int a;
		cin >> a ;
		time[0][i]=a;
	}
	for(int i=0;i<n-1;i++)
	{
		int a;
		cin >> a ;
		time[1][i]=a;
	}

	cout << solve(first,second,entry,exit,n,time) << endl;
	cout << solve3(first,second,entry,exit,n,time) << endl;
}