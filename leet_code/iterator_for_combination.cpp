#include<bits/stdc++.h>
using namespace std;

int solve(string input,vector<string>& output)
{
	if(input.size()==0)
	{
		output.push_back("");
		return 1;
	}
	int sm = solve(input.substr(1),output);
	for(int i=0;i<sm;i++)
	{
		output.push_back(input[0]+output[i]);
	}
	return 2*sm;
}

bool hasnext(int n,int count)
{
	if(count >= n)
	{
		return false;
	}
	return true;
}

string next(vector<string>& arr,int count)
{
	if(hasnext(arr.size(),count))
	{
		return arr[count];
	}
	return "nothing";
}


int main()
{
	string input;
	cin >> input;
	vector< string > output;
	int k;
	cin >> k;
	int suni = solve(input,output);
	vector< string> arr;
	for(int i=0;i<output.size();i++)
	{
		if(output[i].length()==k)
		{
			arr.push_back(output[i]);
		}
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++)
	{
		cout << arr[i] << endl;
	}
	int n = arr.size();
	int q;
	cin >> q;
	int count = 0;
	for(int i=0;i<q;i++)
	{
		string value;
		cin >> value;
		if(value=="next")
		{
			cout << next(arr,count) << endl;
			count+=1;
		}
		else
		{
			cout << hasnext(n,count) << endl;
		}
	}


}