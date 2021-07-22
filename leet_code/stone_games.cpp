// biweekly 30 4th question
#include<bits/stdc++.h>
using namespace std;


bool isperfect_square(int n)
{
	for(int i=1;i*i<=n;i++)
	{
		if((i*i)==n)
		{
			return true;
		}
	}
	return false;
}



// recurssion
bool solve(int n)
{
	if(n==0)
	{
		return false;
	}
	if(n==1)
	{
		return true;// i will take and opp loses
	}
	if(n==2)
	{
		return false;// i will take 1 so opp is left 1 so he will take 1 and i don't have anything
	}
	if(n==3)
	{
		return true;
	}
	if(isperfect_square(n))
	{
		return true;// n is perfect square so i will take everything
	}
	int i=1;
	bool ans = true;
	while((i*i) < n)
	{
		bool temp = solve(n-(i*i));
		ans = ans&temp;// if any one is false  ALice will win
		i+=1;
	}
	if(ans==false)// opp loses in any one case
	{
		return true;
	}
	return false;
}

//  memorization
bool solve2(int n,int* dp)
{
	if(dp[n]!=-1)
	{
		if(dp[n]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(n==0)
	{
		return false;
	}
	if(n==1)
	{
		return true;// i will take and opp loses
	}
	if(n==2)
	{
		return false;// i will take 1 so opp is left 1 so he will take 1 and i don't have anything
	}
	if(n==3)
	{
		return true;
	}
	if(isperfect_square(n))
	{
		return true;// n is perfect square so i will take everything
	}
	int i=1;
	bool ans = true;
	while((i*i) < n)
	{
		bool temp = solve2(n-(i*i),dp);
		ans = ans&temp;// if any one is false  ALice will win
		i+=1;
	}
	if(ans==false)// opp loses in any one case
	{
		dp[n]=1;
		return true;
	}
	dp[n] = 0;
	return false;
}


bool solve3(int n)
{
	bool* dp = new bool[n+1]();
	dp[0]=false;
	dp[1]=true;
	dp[2]=false;
	dp[3]=true;
	for(int i=4;i<=n;i++)
	{
		if(isperfect_square(i))
		{
			dp[i]=true;
			continue;
		}
		int k = 1;
		bool temp = true;
		while((k*k) < i)
		{
			temp = temp&dp[is-(k*k)];
			k+=1;
		}
		if(temp==false)
		{
			dp[i]=true;
		}
		else
		{
			dp[i]=false;
		}
	}
	bool ans = dp[n];
	delete[] dp;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	bool ans = solve(n);
	if(ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	int* dp = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	bool ans1 = solve2(n,dp);
	if(ans1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	bool ans2 = solve3(n);
	if(ans2)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}