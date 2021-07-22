#include<bits/stdc++.h>
using namespace std;


int get_sum(stack<int>& s)
{
	stack<int> temp;
	int sum = 0;
	while(!s.empty())
	{
		temp.push(s.top());
		sum+=s.top();
		s.pop();
	}
	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
	return sum;

}
int solve(stack<int>& s1,stack<int>& s2,stack<int>& s3,int n1,int n2,int n3)
{
	
	int sum1 = get_sum(s1);
	int sum2 = get_sum(s2);
	int sum3 = get_sum(s3);
	
	cout << sum1 << " " << sum2 << " " << sum3 << endl;
	while(s1.size() > 0 && s2.size()>0 && s3.size() > 0)
	{
		if(sum1==sum2 && sum2==sum3)
		{
			return sum1;
		}
		if(sum1 > sum2 && sum1 > sum3)
		{
			sum1-=s1.top();
			s1.pop();
		}
		else if(sum2 > sum1 && sum2 > sum3)
		{
			sum2-=s2.top();
			s2.pop();
		}
		else if(sum3 > sum1 && sum3 > sum2)
		{
			sum3-=s3.top();
			s3.pop();
		}
	}
	return 0;
}
int main()
{
	stack<int> s1;
	stack<int> s2;
	stack<int> s3;
	int n1,n2,n3;
	cin >> n1;
	for(int i=0;i<n1;i++)
	{
		int a;
		cin >> a;
		s1.push(a);
	}
	cin >> n2;
	for(int i=0;i<n2;i++)
	{
		int a;
		cin >> a;
		s2.push(a);
	}
	cin >> n3;
	for(int i=0;i<n3;i++)
	{
		int a;
		cin >> a;
		s3.push(a);
	}
	cout << solve(s1,s2,s3,n1,n2,n3) << endl;
	return 0;

}