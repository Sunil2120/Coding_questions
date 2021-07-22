#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string input;
		cin >> input;
		if(input.size() <= 10)
		{
			cout << input << endl;
			continue;
		}
		cout << input[0] << input.size()-2 << input.back()<< endl;
	}
	return 0;
}