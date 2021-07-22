#include<bits/stdc++.h>
using namespace std;




// maximum steps 3 f(n-1)+f(n-2)+f(n-3)
// if he take n-1 steps f(n-1) then add 1 at the end
// if he takes n-2 steps f(n-2) then add 2 at the end
// if he takes n-3 steps f(n-3) then add 3 at the end
// total steps to reach n is f(n) = f(n-1)+f(n-2)+f(n-3)
long staircase(int n)
{
	long* arr = new long[n+1];
	arr[0]=1;
	arr[1]=1;
	arr[2]=2;
	for(int i=3;i<=n;i++)
	{
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
	}
	long output = arr[n];
	delete[] arr;
	return output;

}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n) << endl;
	return 0;
}