// we should find the area of the polygon
#include<bits/stdc++.h>
using namespace std;

struct points
{
	double x;
	double y;

};
typedef struct points points;


double cross_product(points* arr,int first,int second)
{
	points f = arr[first];
	points s = arr[second];
	return ((f.x*s.y) - (s.x*f.y) );
}

int area(points* arr,int n)
{
	double sum = 0;
	for(int i=0;i<n-1;i++)
	{
		sum+=cross_product(arr,i,i+1);
	}
	sum+=cross_product(arr,n-1,0);
	sum = abs(sum)/2.0;
	return sum;
}

int main()
{
	int n;
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
	cout << area(arr,n) << endl;
	delete[] arr;
	return 0;
}