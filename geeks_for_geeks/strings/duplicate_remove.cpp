#include<bits/stdc++.h>
using namespace std;

// o(n2)to remove the duplicate elements and remove the first one

string solve(string input)
{
	string temp ="";
	for(int i=0;i<input.size()-1;i++)
	{
		int check = 0;
		for(int j=i+1;j<input.size();j++)
		{
			if(input[i]==input[j])
			{
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			temp+=input[i];
		}
	}
	temp+=input[input.size()-1];
	return temp;
}


// o(n2) to remove the duplicate elements and remove the last one
// extra space o(1)
string solve1(string input)
{
	int index = 0;
	for(int i=0;i<input.size();i++)
	{
		int check = 0;
		for(int j=0;j<i;j++)
		{
			if(input[i]==input[j])
			{
				check = 1;
				break;
			}
		}
		if(check==0)
		{
			input[index]=input[i];
			index+=1;
		}
	}
	input.erase(index);
	return input;;
}

// o(n) time
// auxillary space o(1)
string solve2(string input)
{
	int index = 0;
	unordered_map<char,int> hash;
	for(int i=0;i<input.size();i++)
	{
		if(hash[input[i]]==0)
		{
			input[index]=input[i];
			index+=1;
			hash[input[i]]=1;
		}
	}
	input.erase(index);
	return input;
}

// using binary search o(nlogn) 
// Auxillary space o(n)
string solve3(string input)
{
	string temp = input;
	string temp1="";
	int index = input.size()-1;
	sort(temp.begin(),temp.end());
	for(int i=0;i<input.size();i++)
	{
		int start = 0;
		int end = i-1;
		int check = 0;
		while(start < end)
		{
			int mid = start + (end-start)/2;
			if(temp[mid]==input[i])
			{
				check = 1;
				break;
			}
			else if(temp[mid] > input[i])
			{
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
		if(check == 0)
		{
			temp1+=input[i];
		}
	}

	return temp1;
}



int main()
{
	string input;
	cin >> input;
	cout << solve2(input) << endl;
	cout << solve1(input) << endl;
	cout << solve3(input) << endl;
	return 0;
}