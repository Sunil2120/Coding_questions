// given ax+by = gcd(a,b) we should find the value of x,y
// we know that gcd(a,b)=gcd(b,a%b) this will give the value of x1 and y1
// wkt x = y1 and  y = x1 - (a/b)*y1
// refer notes
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


int main()
{
	int a,b;
	cin >> a >> b;
	triplet* ans = solve(a,b);
	cout << ans->gcd << " " << ans->x << " " << ans->y << endl;
	return 0;
}

// ans
// 10x + 5y = gcd(10,5)
// 10x + 5y = 5;
// x=1,y=-1(10-5 = 5)