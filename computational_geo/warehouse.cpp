#include<bits/stdc++.h>
using namespace std;


struct points
{
	int x;
	int y;

};

typedef struct points points;

bool compare(points a,points b)
{
	return (a.y > b.y);// decreasing order
}


int main()
{
	int n;// no of posts
	cin >> n;
	points* arr = new points[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i].x;
	}
	for(int i=0;i<n;i++)
	{
		cin >> arr[i].y;
	}
	int max_ = INT_MIN;
	sort(arr,arr+n,compare);
	for(int i=0;i<n-1;i++)
	{
		int value = arr[i].y - arr[i+1].y;
		if(value > max_)
		{
			max_ = value;
		}
	}
	int firstvalue = 200 - arr[0].y;
	if(firstvalue > max_)
	{
		max_ = firstvalue;
	}
	int last = arr[n-1].y;
	if(last > max_)
	{
		max_ = last;
	}
	cout << max_ -1 << endl;
	return 0;

}