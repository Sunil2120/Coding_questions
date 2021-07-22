#include<bits/stdc++.h>
using namespace std;



bool candis(int fruits)
{
	if(fruits%11==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int fruits;
	cin >> fruits;
	int fullmoon=0;
	while(!candis(fruits))
	{
		fullmoon+=1;
		fruits=2*fruits;
	}
	cout << fullmoon << " " << fruits << endl;
	return 0;
}