#include<bits/stdc++.h>
using namespace std;


char getchar(int i)
{
	return (char)(i + 97);// to get the character
}

void palindrome(string str)
{
	map<char,vector<int> > m;
	for(int i=0;i<str.size();i++)
	{
		m[str[i]].push_back(i);
	}
	int odd_count = 0;
	for(int i=0;i<26;i++)
	{
		if((m[getchar(i)].size())%2!=0)
		{
			odd_count++;
		}
	}
	if(odd_count >=2)
	{
		cout << "-1" << endl;
		return ;
	}
	int* arr = new int[str.length()];
	int start =0;
	int end = str.length()-1;
	vector<int> temp;
	for(int i=0;i<26;i++)
	{
		if(m[getchar(i)].size() % 2==0)
		{
				for(int j = 0;j<m[getchar(i)].size();j+=2)
				{
					arr[start]=m[getchar(i)][j]+1;
					arr[end]= m[getchar(i)][j+1]+1;
					start++;
					end--;
				}	
		}
		else
		{
			temp = m[getchar(i)];
		}
	}
	
	int k = 0;
	while(start<=end && k < temp.size())
	{
		arr[start]=temp[k]+1;
		k++;
		start++;
	}

	for(int i=0;i<str.length();i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return ;

}

int main()
{
	palindrome("abcdabcdabcdabcd");
	return 0;
}