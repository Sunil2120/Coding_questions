#include<bits/stdc++.h>
using namespace std;

typedef pair<int,char> pd;


string solve(string input)
{
	int* count = new int[26]();
	for(int i=0;i<input.size();i++)
	{
		count[input[i]-'a']+=1;
	}
	priority_queue<pd> pq;
	for(char c='a';c<='z';c++)
	{
		if(count[c-'a']>0)
		{
			pq.push(make_pair(count[c-'a'],c));
		}
	}
	pd prev;
	prev.first = -1;
	prev.second ='#';
	string output ="";
	while(!pq.empty())
	{
		pd cur = pq.top();
		pq.pop();
		output=output+cur.second;
		cur.first-=1;
		if(prev.first>0)
		{
			pq.push(prev);
		}
		prev = cur;
	}
	return output;
}
int main()
{
	string input;
	cin >> input;
	string output = solve(input);
	if(output.size()<input.size())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << output << endl;
	}

}