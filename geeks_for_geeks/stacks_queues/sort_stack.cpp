#include<bits/stdc++.h>
using namespace std;
// this is done using additional stack
// sort stack such that the greater elements remain at top of the stack

void print_stack(stack<int>& original)
{
	vector<int> temp2;
	while(original.size() > 0)
	{
		cout << original.top() << " ";
		temp2.push_back(original.top());
		original.pop();
	}
	cout << endl;
	for(int i=0;i<temp2.size();i++)
	{
		original.push(temp2[i]);
	}
	return ;
}
void solve(stack<int>& original,stack<int>& temp)
{
	while(original.size()>0)
	{
		int cur = original.top();
		original.pop();
		while(temp.size()>0 && temp.top() > cur)
		{
			original.push(temp.top());
			temp.pop();
		}
		temp.push(cur);
	}
	vector<int> temp2;
	while(temp.size() > 0)
	{
		temp2.push_back(temp.top());
		temp.pop();
	}
	while(temp2.size() > 0)
	{
		original.push(temp2.back());
		temp2.pop_back();
	}
	return ;
}

int main()
{
	stack<int> original;
	stack<int> temp;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		original.push(val);
	}
	print_stack(original);
	solve(original,temp);
	print_stack(original);
	return 0;
}