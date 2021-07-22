#include<bits/stdc++.h>
using namespace std;


bool isPossible(int row,int col,string& temp,int n)
{
	//same col
	for(int i=0;i<temp.size();i++)
	{
		int x = temp[i]-'0';
		if(x==col)
		{
			return false;
		}
	}
	//left diagonal
	int y = col-1;
	for(int i=temp.size()-1;i>=0;i--)
	{
		int x = temp[i]-'0';
		if(x==y)
		{
			return false;
		}
		y-=1;
	}
	//right
	y=col+1;
	for(int i=temp.size()-1;i>=0;i--)
	{
		int x = temp[i]-'0';
		if(x==y)
		{
			return false;
		}
		y+=1;
	}
	return true;

}
void solve2(int row,int n,vector<string>& output,string temp)
{
	if(row==n)
	{
		output.push_back(temp);
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(isPossible(row,i,temp,n)==true)
		{
			string temp2 = temp;
			temp2.push_back(i+'0');
			solve2(row+1,n,output,temp2);
		}
	}
	return ;
}

void solve(int n,vector<string>& output)
{
	for(int i=0;i<n;i++)
	{
		string temp;
		temp.push_back(i+'0');
		solve2(1,n,output,temp);
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	vector<string> output;
	solve(n,output);
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << endl;
	}
	return 0;
}