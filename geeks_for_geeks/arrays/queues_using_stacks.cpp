// Implement a queue using two stacks

#include<bits/stdc++.h>
using namespace std;


// time complexity both push and pop takes o(1) as it is more frequent than puting all elements which is o(n)
// space complexity o(n)


int main()
{
	vector<int> push_stack;
	vector<int> pop_stack;
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		if(input=="push")
		{
			int value;
			cin >> value;
			push_stack.push_back(value);
		}
		else
		{
			if(pop_stack.size()==0 && push_stack.size()==0)
			{
				cout << -1 << endl;
				continue;
			}
			else if(pop_stack.size()==0)
			{
				while(push_stack.size()!=0)
				{
					pop_stack.push_back(push_stack.back());
					push_stack.pop_back();
				}
				cout << pop_stack.back() << endl;
				pop_stack.pop_back();
				continue;
			}
			else if(pop_stack.size()!=0)
			{
				cout << pop_stack.back() << endl;
				pop_stack.pop_back();
			}
		}
	}
	return 0;
}