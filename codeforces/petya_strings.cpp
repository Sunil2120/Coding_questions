#include<bits/stdc++.h>
using namespace std;

void convert(string& first)
{
	for(int i=0;i<first.size();i++)
	{
		if(first[i] < 97)
		{
			first[i]= first[i] + 32;
		}
	}
	return ;
}

int main()
{
	string first,second;
	cin >> first >> second;
	convert(first);
	convert(second);
	int i = 0;
	int j=0;
	while(i<first.size() && j<second.size())
	{
		if(first[i]==second[j])
		{
			i+=1;
			j+=1;
			continue;
		}
		if(first[i] < second[j])
		{
			cout << -1 << endl;
			return 0;
		}
		else if(second[j] < first[i])
		{
			cout << 1 << endl;
			return 0;
		}
	}
	if(i==first.size() && j==second.size())
	{
		cout << 0 << endl;
		return 0;
	}
	int value = (i < first.size()?1:-1);
	cout << value << endl;
	return 0;
}