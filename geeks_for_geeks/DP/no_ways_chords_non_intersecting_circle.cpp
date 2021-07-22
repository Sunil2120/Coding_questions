// Count ways to divide circle using N non-intersecting chords
// Last Updated: 17-12-2018
// Given a number N, find the number of ways you can draw N chords in a circle with 2*N points such that no 2 chords intersect.
// Two ways are different if there exists a chord which is present in one way and not in other.
#include<bits/stdc++.h>
using namespace std;

// observation
// chords =1 => ans = 1
// chords = 2 => ans = 2
// chords = 3 => ans = 5
// chords = 4 => ans = 14
// we  is nothing but  catalan(chords)
// time  to find catalan number is O(n)
// Cn = (2nCn)/(n+1)

int solve(int n,int r)
{	
	if(r==0 || r==n)
	{
		return 1;
	}
	if(r==1)
	{
		return n;
	}
	// nCr = nC(n-r)
	if(r > (n-r))
	{
		r = n-r;
	}
	int total = 1;
	for(int i=0;i<r;i++)
	{

		total=total*(n-i);
		total=total/(i+1);
	}
	return total;

}
int main()
{
	int n;
	cin >> n;
	int value = solve(2*n,n);
	value = value/(n+1);
	cout << value << endl;
	return 0;
}