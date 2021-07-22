#include<bits/stdc++.h>
using namespace std;


bool compare(int a,int b)
{
	return a > b;
}

void solve(int n,int* sides)
{
	if(n==0)
	{
		return ;
	}
	sort(sides,sides+n,compare);
	int* s = new int[3]();
	long long sum = -1;
	for(int i=0;i<n-2;i++)
	{
		int a = sides[i];
		int b = sides[i+1];
		int c = sides[i+2];
		if((a+b > c) && (a+c > b) && (b+c > a))
		{
			long long perimeter = a + b + c;
			if(perimeter > sum)
			{
				sum = perimeter;
				s[0]=c;
				s[1]=b;
				s[2]=a;
			}
			else if(perimeter == sum)
			{
				if(s[2]==a)// longest sides are equal
				{
					if(s[0]<c)
					{
						continue;
					}
					s[0]=c;
					s[1]=b;
					s[2]=a;
				}
			}
		}
	}
	if(sum == -1)
	{
		cout << -1 << endl;
		return ;
	}
	//cout << sum << endl;
	cout << s[0] << " " << s[1] << " " << s[2] << endl;
	return ;
}


int main()
{
	int n;
	cin >> n;
	int* sides = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> sides[i];
	}
	solve(n,sides);
	return 0;
}