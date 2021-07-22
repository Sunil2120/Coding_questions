#include<bits/stdc++.h>
using namespace std;


int balancedBTs(int n)
{
	if(n==0 || n==1)// only one balanced_binary_tree is possible
	{
		return 1;
	}
	int m = pow(10,9) + 7;
	int x = balancedBinaryTree(n-1);
	int y = balancedBinaryTree(n-2);
	long long x1 = (long long)x*x ;
	long long x2 =  (long long)x*y*2;
	int ans1 = (int) (x1%m); // x1 is long converting it to integer
	int ans2 = (int) (x2%m) ;// x2 is long converting it to integer
	int ans = (ans1 + ans2)% m; // (x1+x2) are above integer range so divide by m (since m is integer the result will be within m(integer))
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << balancedBinaryTree(n) << endl;
	return 0;
}