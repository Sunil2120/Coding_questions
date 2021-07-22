// Minimize Cash Flow among a given set of friends who have borrowed money from each other
// Last Updated: 11-12-2019
// Given a number of friends who have to give or take some amount of money from one another.
// Design an algorithm by which the total cash flow among all the friends is minimized.


#include<bits/stdc++.h>
using namespace std;


// Do following for every person Pi where i is from 0 to n-1.
// 1) Compute the net amount for every person. The net amount for person ‘i’ can be computed be subtracting sum of all debts from sum of all credits.

// 2) Find the two persons that are maximum creditor and maximum debtor. Let the maximum amount to be credited maximum creditor be maxCredit and maximum amount to be debited from maximum debtor be maxDebit. 
//Let the maximum debtor be Pd and maximum creditor be Pc.

// 3) Find the minimum of maxDebit and maxCredit. Let minimum of two be x. Debit ‘x’ from Pd and credit this amount to Pc

// 4) If x is equal to maxCredit, then remove Pc from set of persons and recur for remaining (n-1) persons.

// 5) If x is equal to maxDebit, then remove Pd from set of persons and recur for remaining (n-1) persons.

int getmax(vector<int>& amount,int n)
{
	int max_value = amount[0];
	int max_i = 0;
	for(int i=1;i<n;i++)
	{
		if(amount[i] > max_value)
		{
			max_value = amount[i];
			max_i = i;
		}
	}
	return max_i;
}

int getmin(vector<int>& amount,int n)
{
	int min_value = amount[0];
	int min_i = 0;
	for(int i=1;i<n;i++)
	{
		if(amount[i] < min_value)
		{
			min_value = amount[i];
			min_i = i;
		}
	}
	return min_i;
}

void solve(vector<int>& amount,int n)
{
	int maxdeb = getmin(amount,n);
	int maxcre = getmax(amount,n);
	if(amount[maxdeb]==0 && amount[maxcre]==0)// everthing is settled
	{
		return ;
	}
	// else get min of absolute of maxdeb and maxcred
	int min_value = min(-1*amount[maxdeb],amount[maxcre]);
	amount[maxcre]-=min_value;
	amount[maxdeb]+=min_value;
	cout << "person" << " " << maxdeb << " " << "pays" << " " << min_value << " to " << maxcre << endl;
	solve(amount,n);
	return ;
}

int main()
{
	int n,m;
	cin >> n  >> m;
	vector<int> amount(n,0);
	for(int i=0;i<m;i++)
	{
		int u,v,a;
		cin >> u >> v >> a;
		//(u->v)
		amount[v]+=a;
		amount[u]-=a;
	}
	solve(amount,n);
	return 0;
}