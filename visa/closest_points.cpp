#include<bits/stdc++.h>
using namespace std;

//algorithm in O(nlogn)
// 1. sort the given points based on x-axis
// 2. find the mid point recurssively class on left and right
// 3. d = min(left,right)
// 4. get the points whose x axis is nearer to mid point whose distance b/w them and midpoint is less than d
// 5. sort this points based on y-axis
// 6. by using two for loops find the min distance
// 7. return the minvalue min(d,min distance)
// 8. base condition - if n <=3 brute force method

bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.first < b.first;
}

bool compare2(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}

float distance(pair<int,int> a,pair<int,int> b)
{
	float result = (abs(b.first - a.first)*abs(b.first - a.first));
	result+=(abs(b.second - a.second)*abs(b.second - a.second));
	result = sqrt(result);
	return result;
}

float brute_force(vector<pair<int,int>>& arr,int low,int high)
{
	float output = INT_MAX;
	for(int i=low;i<=high;i++)
	{
		for(int j=i+1;j<=high;j++)
		{
			output = min(output,distance(arr[i],arr[j]));
		}
	}
	return output;
}

float solve2(vector<pair<int,int>>& arr,int low,int high)
{
	if(low > high)
	{
		return INT_MAX;
	}
	if((high-low+1) <= 3)
	{
		return brute_force(arr,low,high);
	}
	int mid = low + (high-low)/2;
	//left
	float left = solve2(arr,low,mid-1);
	float right = solve2(arr,mid+1,high);
	float min_value = min(left,right);
	pair<int,int> mid_point = arr[mid];
	vector<pair<int,int>> strip;
	for(int i=low;i<=high;i++)
	{
		if(abs(arr[i].first - mid_point.first) < min_value)
		{
			strip.push_back(arr[i]);
		}
	}
	//sort this strip based on y value
	sort(strip.begin(),strip.end(),compare2);
	float min_value2 = min_value;
	for(int i=0;i<strip.size();i++)
	{
		for(int j=i+1;j<strip.size();j++)
		{
			if(distance(strip[i],strip[j]) < min_value2)
			{
				min_value2 = distance(strip[i],strip[j]);
			}
		}
	}
	return min(min_value,min_value2);



}

float solve(vector<pair<int,int>>& arr,int n)
{
	if(n==0 || n==1)
	{
		return 0;
	}
	sort(arr.begin(),arr.end(),compare);
	return solve2(arr,0,n-1);


}

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++)
	{
		int f,s;
		cin >> f >> s;
		arr.push_back(make_pair(f,s));
	}
	cout << solve(arr,n) << endl;
}