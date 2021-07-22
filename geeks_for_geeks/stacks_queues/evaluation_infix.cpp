#include<bits/stdc++.h>
using namespace std;

// Time complexity O(n) and Auxillary space O(n)

// precedence(*,/) > precedence(+,-)
int precedence(char op)
{
	if(op=='+')
	{
		return 1;
	}
	else if(op == '-')
	{
		return 1;
	}
	else if(op == '*')
	{
		return 2;
	}
	else if(op == '/')
	{
		return 2;
	}
	return -1;
}

int precedence2(string op)
{
	if(op=="+")
	{
		return 1;
	}
	else if(op == "-")
	{
		return 1;
	}
	else if(op == "*")
	{
		return 2;
	}
	else if(op == "/")
	{
		return 2;
	}
	return -1;
}

int evaluate(int a,char op,int b)
{
	if(op=='+')
	{
		return a+b;
	}
	else if(op == '-')
	{
		return a-b;
	}
	else if(op == '*')
	{
		return a*b;
	}
	else if(op == '/')
	{
		return a/b;
	}
	return -1;
}

int evaluate2(int a,string op,int b)
{
	if(op=="+")
	{
		return a+b;
	}
	else if(op == "-")
	{
		return a-b;
	}
	else if(op == "*")
	{
		return a*b;
	}
	else if(op == "/")
	{
		return a/b;
	}
	return -1;
}

bool isDigit(char a)
{
	int value = a -'0';
	if(value >=0 && value <=9)
	{
		return true;
	}
	return false;
}
// without spaces in between and single digits
int solve(string infix)
{
	vector<int> operands;
	vector<char> operators;
	for(int i=0;i<infix.size();i++)
	{
		if(isDigit(infix[i]))
		{
			
			operands.push_back(infix[i]-'0');
			cout << operands.back() << endl;
		}
		else if(infix[i]=='(')
		{
			operators.push_back(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(operators.back()!='(')
			{
				int b = operands.back();
				operands.pop_back();
				int a = operands.back();
				operands.pop_back();
				int result = evaluate(a,operators.back(),b);
				operands.push_back(result);
				operators.pop_back();
			}
			operators.pop_back();

		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
		{
			//operators
			//Important
			while(operators.size() > 0 && operators.back()!='(' && precedence(operators.back()) >= precedence(infix[i]))
			{
				int b = operands.back();
				operands.pop_back();
				int a = operands.back();
				operands.pop_back();
				int result = evaluate(a,operators.back(),b);
				operands.push_back(result);
				cout << "value" << " " << operands.back() << endl;
				operators.pop_back();
			}
			operators.push_back(infix[i]);
			cout << operators.back() << endl;
		}
	}
	while(operators.size() > 0)
	{
		int b = operands.back();
		operands.pop_back();
		int a = operands.back();
		operands.pop_back();
		int result = evaluate(a,operators.back(),b);
		operands.push_back(result);
		cout << "value" << " " << operands.back() << endl;
		cout << a << " " << operators.back() << " " << b << endl;
		operators.pop_back();
	}
	int output = operands.back();
	operands.pop_back();
	return output;

}

bool isDigit2(string cur)
{
	
	for(int i=0;i<cur.size();i++)
	{
		int cur_value=(cur[i]-'0');
	
		if(cur_value >= 0 && cur_value <= 9)
		{
			continue;
		}
		return false;
	}
	return true;
}

int getvalue(string cur)
{
	
	int output = 0;
	int i=0;
	while(i<cur.size())
	{
		output = (output*10) + (cur[i]-'0');
		i+=1;
	}
	return output;
}

// with spaces in between and multiple digits
int solve2(string infix)
{
	vector<int> operands;
	vector<string> operators;
	int i=0;
	while(i<infix.size())
	{
		string cur;
		while( i < infix.size() && infix[i]!=' ')
		{
			cur.push_back(infix[i]);
			i+=1;
		}
		if(infix[i]==' ')
		{
			i+=1;
		}
		cout << cur << endl;
		if(isDigit2(cur))
		{
			
			operands.push_back(getvalue(cur));
			cout << operands.back() << endl;

		}
		else if(cur=="(")
		{
			operators.push_back(cur);
		}
		else if(cur==")")
		{
			while(operators.back()!="(")
			{
				int b = operands.back();
				operands.pop_back();
				int a = operands.back();
				operands.pop_back();
				int result = evaluate2(a,operators.back(),b);
				operands.push_back(result);
				operators.pop_back();
			}
			operators.pop_back();

		}
		else if(cur=="+" || cur=="-" || cur=="*" || cur=="/")
		{
			//operators
			//Important
			cout << cur << endl;
			while(operators.size() > 0 && operators.back()!="(" && precedence2(operators.back()) >= precedence2(cur))
			{
				int b = operands.back();
				operands.pop_back();
				int a = operands.back();
				operands.pop_back();
				int result = evaluate2(a,operators.back(),b);
				operands.push_back(result);
				cout << "value" << " " << operands.back() << endl;
				operators.pop_back();
			}
			operators.push_back(cur);
			cout << operators.back() << endl;
		}
	}
	while(operators.size() > 0)
	{
		int b = operands.back();
		operands.pop_back();
		int a = operands.back();
		operands.pop_back();
		int result = evaluate2(a,operators.back(),b);
		operands.push_back(result);
		cout << "value" << " " << operands.back() << endl;
		cout << a << " " << operators.back() << " " << b << endl;
		operators.pop_back();
	}
	int output = operands.back();
	operands.pop_back();
	return output;

}
int main()
{
	string infix;
	getline(cin,infix);
	cout << solve2(infix) << endl;
	return 0;
}