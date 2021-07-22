#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	long long cur = 1;
	int i=input.size()-1;
	long long total = 0;
	while(i>=0)
	{
		total+=cur*(input[i]-'A'+1);
		cur = cur*26;
		i--;
	}
	cout << total << endl;
}