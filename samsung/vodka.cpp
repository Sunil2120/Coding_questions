#include<bits/stdc++.h>
using namespace std;


void solve(int n)
{
	// if(n==0)
	// {
	// 	return ;
	// }
	// vector<int> output;
	// for(int i=1;i<=n;i++)
	// {
	// 	int temp = 1;
	// 	while(output.size()!=0 && temp==output.back())
	// 	{
	// 		int v = output.back();
	// 		output.pop_back();
	// 		temp = (v+1);
	// 	}
	// 	output.push_back(temp);
	// }
	// for(int i=0;i<output.size();i++)
	// {
	// 	cout << output[i] << " ";
	// }
	// cout << endl;
	// return ;
	vector<int> output;
	int count = 1;
	while(n!=1)
	{
		int rem = n%2;
		if(rem!=0)
		{
			output.push_back(count);
		}
		n = n/2;
		count+=1;
	}
	output.push_back(count);
	while(output.size()!=0)
	{
		cout << output.back() << " ";
		output.pop_back();
	}
	cout << endl;
	return ;

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}