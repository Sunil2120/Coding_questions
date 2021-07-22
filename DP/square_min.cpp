 #include<bits/stdc++.h>
using namespace std;




int square_min(int value)
{
	vector<int> coins;
	for(int i=1;i<=value;i++)
	{
		if(pow(i,2) <= value)
		{
			coins.push_back(i);
		}
	}
	int* output = new int[value+1]();
	int min_x = INT_MAX;
	output[0]=0;
	for(int i=1;i<=value;i++)
	{
		for(int j=0;j<coins.size();j++)
		{
			int temp;
			if(i - pow(coins[j],2) >=0)
			{
				temp = output[i - (coins[j]*coins[j])] + 1;
				if(temp < min_x)
				{
					min_x = temp;
				}
			}
		}
		output[i]=min_x;
		min_x = INT_MAX;
	}

	int ans = output[value];
	delete[] output;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << square_min(n) << endl;
	return 0;
}




