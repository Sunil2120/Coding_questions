#include<bits/stdc++.h>
using namespace std;


// Take three variables low , mid , high.
// Initialize low=0,mid=0,high=n-1.
// pass a[mid] as variable in switch condition.
// Whenever ‘R’ comes to swap a[mid] and a[low] and increment low and mid.
// Whenever ‘B’ comes just increment mid.
// Whenever ‘G’ comes to swap a[mid] and a[high] and decrement high.


string solve(string input)
{
	int low = 0;
	int mid = 0;
	int high = input.size()-1;
	while(mid <= high)
	{
		if(input[mid]=='R')
		{
			//swap with low
			char temp = input[mid];
			input[mid]=input[low];
			input[low]=temp;
			mid+=1;
			low+=1;
		}
		else if(input[mid]=='G')
		{
			mid+=1;
		}
		else
		{
			char temp = input[mid];
			input[mid]=input[high];
			input[high]=temp;
			high-=1;
		}
	}
	return input;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}