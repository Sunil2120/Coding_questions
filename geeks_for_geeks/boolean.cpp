#include<bits/stdc++.h>
using namespace std;

unordered_map<string,pair<int,int>> ha;

pair<int,int> solve(string input)
{


	
	if(input.size()==1)
	{
		if(input[0]=='T')
		{
			return {1,0};
		}
		else
		{
			return {0,1};
		}
	}
	if(ha.find(input)!=ha.end())
	{
		return ha[input];
	}
	int t = 0;
	int f=0;
	for(int i=0;i<input.size()-2;i++)
	{
		if(input[i]!='T' && input[i]!='F')
		{
			continue;
		}
		
		pair<int,int> temp1 = solve(input.substr(0,i+1));
		pair<int,int> temp2 = {0,0};
		if(i!=input.size()-1)
		{
			temp2 = solve(input.substr(i+2));
		}
		if(i+1 < input.size())
		{
			if(input[i+1]=='|')
			{
				t += temp1.first*(temp2.first+temp2.second);
				t += temp1.second*(temp2.first);
				f += temp1.second*(temp2.second);
			}
			else if(input[i+1]=='&')
			{
				t+= temp1.first*(temp2.first); 
				f+= temp1.first*(temp2.second);
				f+= temp1.second*(temp2.first+temp2.second);
			}
			else
			{
				t+= temp1.first*(temp2.second);
				t+= temp1.second*(temp2.first);
				f+= temp1.first*(temp2.first);
				f+= temp1.second*(temp2.second);
			}
		}
	}
	ha[input]={t,f};
	return {t,f};

}

int main()
{
	string input;
	cin >> input;
	cout << solve(input).first << endl;
	return 0;
}