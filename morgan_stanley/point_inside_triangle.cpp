#include<bits/stdc++.h>
using namespace std;


bool solve(pair<int,int> A,pair<int,int> B,pair<int,int> C,pair<int,int> P)
{
	float area_PAC = abs(A.first*(C.second - P.second)+ C.first*(P.second - A.second) + P.first*(A.second - C.second))/2;
	float area_PAB = abs(A.first*(B.second - P.second)+ B.first*(P.second - A.second)+ P.first*(A.second - B.second))/2;
	float area_PBC = abs(B.first*(C.second - P.second)+ C.first*(P.second - B.second)+P.first*(B.second - C.second))/2;
	float area_ABC = abs(A.first*(B.second - C.second)+ B.first*(C.second - A.second)+C.first*(A.second - B.second))/2;
	if(area_ABC == (area_PBC+area_PAC+area_PAB))
	{
		return true;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		pair<int,int> A;
		cin >> A.first >> A.second ;
		pair<int,int> B;
		cin >> B.first >> B.second;
		pair<int,int> C;
		cin >> C.first >> C.second;
		pair<int,int> P;
		cin >> P.first >> P.second;
		if(solve(A,B,C,P))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;

}