#include<bits/stdc++.h>
using namespace std;


bool solve(string input,string output,int k)
{
	int* arr = new int[input.size()]();
	if(input.size()!=output.size())
	{
		return false;
	}
	int* mul = new int[26]();
	for(int i=0;i<input.size();i++)
	{
		if(input[i]!=output[i])
		{
			if(output[i] > input[i])
			{
				arr[i]=(output[i]-input[i]);
			}
			else
			{
				arr[i]=(26 - (input[i]-output[i]));
			}
			int temp = arr[i];
			arr[i] = arr[i] + mul[arr[i]]*26;// how many times it has occured previously*26
			// if first time means 0*26 = 0
			if(arr[i]>k)
			{
				return false;
			}
			mul[temp]+=1;

		}
	}
	// for(int i=0;i<input.size()-1;i++)
	// {
	// 	if(arr[i]==0)
	// 	{
	// 		continue;
	// 	}
	// 	for(int j=i+1;j<input.size();j++)
	// 	{
	// 		if(arr[j]==arr[i])
	// 		{
	// 			arr[j]+=26;
	// 		}
	// 	}

	// }
	for(int i=0;i<input.size();i++)
	{
		if(arr[i] > k)
		{
			return false;
		}
	}
	return true;;
}

int main()
{
	string input;
	string output;
	cin >> input;
	cin >> output;
	int k;
	cin >> k;
	cout << solve(input,output,k) << endl;
}