#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int x = 0;
	while(n--)
	{
		string input;
		cin >> input;
		if(input== "++X" || input == "X++")
		{
			x+=1;
		}
		else if(input== "--X" || input == "X--")
		{
			x-=1;
		}
	}
	cout << x << endl;
	return 0;
}