//We are given a row wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.
 // to find median the array should be sorted
// if n is odd median is (n+1)/2;
// if n is even median is (n/2) + 1;
// necessary condition if x is a median it should have n/2 elements lesser than it in given array
#include<bits/stdc++.h>
using namespace std;



int solve(int** input,int r,int c)
{
	vector<int> output;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			output.push_back(input[i][j]);
		}
	}
	sort(output.begin(),output.end());
	int n = output.size();
	if((n%2)==0)// even
	{
		return output[((n/2)+1)-1];
	}
	else
	{
		return output[((n+1)/2)-1];
	}
	return 0;
}

// o(32*r*log(c))
// Auxillary space o(1)
int solve1(int** input,int r,int c)
{
	int desired = (r*c + 1)/2;
	int min_ = INT_MAX;
	int max_ = INT_MIN;
	// rows are sorted so we will check min in first elements and max in last element
	for(int i=0;i<r;i++)
	{
		min_ = min(input[i][0],min_);
		max_ = max(input[i][c-1],max_);
	}
	while(min_ < max_)
	{
		int mid = min_ + (max_-min_)/2;
		// get the elements less than mid
		int place = 0;
		for(int i=0;i<r;i++)
		{
			place+= upper_bound(input[i],input[i]+c,mid) - input[i];
		}
		if(place < desired)
		{
			min_ = mid+1;
		}
		else
		{
			max_ = mid;
		}
	}
	return min_;
}
int main()
{
	int r,c;
	cin >> r >> c;
	int** input = new int*[r];
	for(int i=0;i<r;i++)
	{
		input[i]=new int[c];
		for(int j=0;j<c;j++)
		{
			cin >> input[i][j];
		}
	}
	cout << solve(input,r,c) << endl;

}