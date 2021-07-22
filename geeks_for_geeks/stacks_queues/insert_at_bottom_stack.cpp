#include<bits/stdc++.h>
using namespace std;



// using recursion
void insert_bottom(vector<int>& s,int x)
{
	// base case
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

void print_stack(vector<int>& s)
{
	for(int i=0;i<s.size();i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	return ;
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
	int m;
	cin >> m;
	while(m--)
	{
		int val;
		cin >> val;
		insert_bottom(s,val);
		print_stack(s);
	}
	return 0;

}