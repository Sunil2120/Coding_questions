#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	long long cost_1,cost_2;
	cin >> cost_1 >> cost_2;
	string input;
	cin >> input;
	int num_count = 0;
	int i=0;
	if(input[0]=='0')
	{
		num_count++;
		i++;
	}
	int j=i+1;
	while(j<n)
	{

		if(input[i]=='1' && input[j]=='0')
		{
			num_count++;

		}
		i++;
		j=i+1;
	}

	if(input[0]=='1' && num_count==0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << num_count*min(cost_1,cost_2)+cost_2 << endl;
	return 0;
}