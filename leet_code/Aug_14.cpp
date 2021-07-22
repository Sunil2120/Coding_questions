// longest palindrome
#include<bits/stdc++.h>
using namespace std;

int solve(string input)
{
	unordered_map<char,int> hash;
	for(int i=0;i<input.size();i++)
	{
		hash[input[i]]+=1;
	}
	int check = 0;
	int total = 0;
	unordered_map<char,int> :: iterator it;
	for(it=hash.begin();it!=hash.end();it++)
	{
		int count = it->second;
		if((count%2)==0)// even
		{
			total+=count;
		}
		else
		{
			// odd
			check = 1;
			total+=(count-1);
		}
	}
	if(check==1)
	{
		total+=1;
	}
	return total;

}

void solve1(string input)// printing longest palindrome can be formed from given string
{
	string beg;
	string end;
	char mid;
	int* arr = new int[26]();
	for(int i=0;i<input.size();i++)
	{
		arr[input[i]-'a']+=1;
	}
	for(int i=0;i<26;i++)
	{
		if((arr[i]%2)!=0)// odd
		{
			mid = i+'a';
			arr[i]=arr[i]-1;
		}
		int temp = arr[i]/2;
		for(int k=0;k<temp;k++)
		{
			beg.push_back(i+'a');
		}
	}
	end = beg;
	reverse(end.begin(),end.end());
	beg.push_back(mid);
	cout << beg+end << endl;
	return ;
	
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	solve1(input);
}