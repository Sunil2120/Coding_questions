// Multiplicative Modulo Inverse
// (A*B) mod m = 1 A,m are given we should find the  value of B
// B is known as Multiplicative Modulo Inverse.
// A*B =1 B is known as Multiplicative Inverse
// refer notes
// obtained equation is A*B + m*Q = 1;
// gcd(A,m) should be 1;
#include<bits/stdc++.h>
using namespace std;

struct triplet
{
	int x;
	int y;
	int gcd;
};
typedef struct triplet triplet;


triplet*  solve(int a,int b)
{
	//base case
	if(b==0)
	{
		// ax + 0 = gcd(a,0)=a;
		// x = 1;
		// substitue x => a + y = a;
		// y = a-a =0;
		triplet* temp1 = new triplet();
		temp1->gcd = a;
		temp1->x = 1;
		temp1->y = 0;
		return temp1;
	}
	triplet* smallans = solve(b,a%b);// this will give the value of x1 and y1
	triplet* temp = new triplet();
	temp->gcd = smallans->gcd;
	temp->x = smallans->y;// x = y1
	temp->y = smallans->x - (a/b)*smallans->y; // y = x1 - (a/b)*y1
	return temp;
}

int solve1(int a,int m)
{
	triplet* result = solve(a,m); // x is the ans we required
	return result->x;
}


int main()
{
	int a,m;
	// gcd(a,m) should be one 
	cin >> a >> m;
	int  ans = solve1(a,m);
	cout << ans << endl;
	return 0;
}