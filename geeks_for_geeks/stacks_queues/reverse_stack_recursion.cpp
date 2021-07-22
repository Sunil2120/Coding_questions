// reverse stack using recursion
#include<bits/stdc++.h>
using namespace std;


void insert_bottom(vector<int>& s,int x)
{
	if(s.size()==0)
	{
		s.push_back(x);
		return ;
	}
	int a = s.back();
	s.pop_back();
	insert_bottom(s,x);
	s.push_back(a);
	return ;

}
void reverse(vector<int>& s)
{
	if(s.size()==0)
	{
		return ;
	}
	int a = s.back();
	s.pop_back();
	reverse(s);
	insert_bottom(s,a);
	return ;
}

void print_stack(vector<int>& s)
{
	for(int i=s.size()-1;i>=0;i--)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		s.push_back(val);
	}
	print_stack(s);
	reverse(s);
	print_stack(s);
	return 0;
}