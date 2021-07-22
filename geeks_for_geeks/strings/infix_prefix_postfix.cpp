#include<bits/stdc++.h>
using namespace std;


bool isoperator(char input)
{
	if(input=='/' || input=='*' || input=='-' || input=='+')
	{
		return true;
	}
	return false;
}


string prefix_to_infix(string input)
{
	vector <string> stack;
	int n = input.size();
	for(int i=n-1;i>=0;i--)
	{
		if(input[i]=='*' || input[i]=='+' || input[i]=='-' || input[i]=='/')
		{
			string first = stack.back();
			stack.pop_back();
			string second = stack.back();
			stack.pop_back();
			string temp = "(" + first;
			temp.push_back(input[i]);
			temp = temp + second + ")";
			stack.push_back(temp);
		}
		else
		{
			string temp;
			temp.push_back(input[i]);
			stack.push_back(temp);
		}
	}
	// cout << stack.back() << endl;
	string ans = stack.back();
	stack.pop_back();
	return ans;
}

string postfix_to_infix(string input)
{
	vector <string> stack;
	int n = input.size();
	for(int i=0;i<n;i++)
	{
		if(input[i]=='*' || input[i]=='+' || input[i]=='-' || input[i]=='/')
		{
			string first = stack.back();
			stack.pop_back();
			string second = stack.back();
			stack.pop_back();
			string temp = "(" + second;
			temp.push_back(input[i]);
			temp = temp + first + ")";
			stack.push_back(temp);
		}
		else
		{
			string temp;
			temp.push_back(input[i]);
			stack.push_back(temp);
		}
	}
	// cout << stack.back() << endl;
	string ans = stack.back();
	stack.pop_back();
	return ans;
}

string prefix_to_postfix(string input)
{
	vector<string> stack;
	int n = input.size();
	for(int i=n-1;i>=0;i--)
	{
		if(isoperator(input[i]))
		{
			// op1 + op2 + operator
			string first = stack.back();
			stack.pop_back();
			string second = stack.back();
			stack.pop_back();
			string temp = first + second;
			temp.push_back(input[i]);
			stack.push_back(temp);
		}
		else
		{
			string temp;
			temp.push_back(input[i]);
			stack.push_back(temp);
		}
	}
	string ans =  stack.back();
	stack.pop_back();
	return ans;
}

string postfix_to_prefix(string input)
{
	vector<string> stack;
	int n = input.size();
	for(int i=0;i<n;i++)
	{
		if(isoperator(input[i]))
		{
			//  operator  + op2 + op1 
			string temp;
			temp.push_back(input[i]);
			string first = stack.back();
			stack.pop_back();
			string second = stack.back();
			stack.pop_back();
			temp = temp + second + first;
			stack.push_back(temp);
		}
		else
		{
			string temp;
			temp.push_back(input[i]);
			stack.push_back(temp);
		}
	}
	string ans =  stack.back();
	stack.pop_back();
	return ans;
}



string infix_to_postifix(string input)
{
	vector<char> stack;
	string operand;
	for(int i=0;i<input.size();i++)
	{
		if(input[i]=='(' || isoperator(input[i]))
		{
			stack.push_back(input[i]);
		}
		else if(input[i]==')')
		{
			// pop everthing until opening bracket
			while(stack.back()!='(')
			{
				operand.push_back(stack.back());
				stack.pop_back();
			}
			stack.pop_back();
		}
		else
		{
			operand.push_back(input[i]);
		}

	}
	return operand;

}

string infix_to_prefix(string input)
{
	reverse(input.begin(),input.end());
	for(int i=0;i<input.size();i++)
	{
		if(input[i]==')')
		{
			input[i]='(';
		}
		else if(input[i]=='(')
		{
			input[i]=')';
		}
	}
	// now infix to postifix
	string output = infix_to_postifix(input);
	reverse(output.begin(),output.end());
	return output;

}
int main()
{
	string input;
	cin >> input;
	// cout << infix_to_postifix(input) << endl;
	// cout << infix_to_prefix(input) << endl;
	// cin >> input;
	// cout << postfix_to_prefix(input) << endl;
	// cin >> input;
	// cout << prefix_to_postfix(input) << endl;
	cout << infix_to_postifix(input) << endl;
}