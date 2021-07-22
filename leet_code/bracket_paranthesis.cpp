#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	vector<char> stack;
	int count = 0;
	int i=0;
	while(i<input.size())
	{
		if(input[i]=='(')
		{
			stack.push_back('(');
		}
		else
		{
			if(input[i+1]==')' && (i+1)<input.size())
			{
				if(stack.size()==0)
				{
					count+=1;
					i+=1;
				}
				else
				{
					stack.pop_back();
					i+=1;
				}
			}
			else
			{
				if(stack.size()==0)
				{
					count+=2;
				}
				else
				{
					count+=1;
					stack.pop_back();
				}
			}
		}
		i+=1;
	}
	//cout << "stack" << " " << stack.size() << endl;
	if(stack.size()!=0)
	{
		count+=(stack.size()*2);
	}
	cout << count << endl;
	return 0;
}