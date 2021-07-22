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
	string input;
	cin >> input;
	int* arr = new int[input.length()]();
	for(int i=0;i<input.length();i++)
	{
		cin >> arr[i];
	}
	points* arr1 = new points[input.length()+1];
	int x = 0;
	int y = 0;
	arr1[0].x = 0;
	arr1[0].y = 0;
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='N')
		{
			y = y + arr[i];
		}
		else if(input[i]=='S')
		{
			y = y - arr[i];
		}
		else if(input[i]=='W')
		{
			x = x - arr[i];
		}
		else
		{
			x = x + arr[i];
		}
		
		arr1[i+1].x = x;
		arr1[i+1].y = y;
		
	}

	cout << area(arr1,input.length()+1);
	return 0;

}