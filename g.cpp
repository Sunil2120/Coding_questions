#include<bits/stdc++.h>
using namespace std;


int getPosOfRightmostSetBit(int n) 
{ 
    return log2(n&-n)+1; 
} 
  
// function to get the position of rightmost unset bit 
int getPosOfRightMostUnsetBit(int n) 
{ 
    // if n = 0, return 1 
    if (n == 0) 
        return 1; 
      
    // if all bits of 'n' are set 
    if ((n & (n + 1)) == 0)     
        return -1; 
      
    // position of rightmost unset bit in 'n' 
    // passing ~n as argument 
    return getPosOfRightmostSetBit(~n);         
}

void solve(int n,int cur)
{

	if(n==1)
	{
		if(cur==0)
		{
			cout << "Vaishani" << endl;
		}
		else
		{
			cout << "Anjali" << endl;
		}
		return ;
	}

	int bit = getPosOfRightMostUnsetBit(n);
	cout << bit << endl;
	if(bit==-1)
	{
		if(cur==0)
		{
			cout << "Anjali" << endl;
		}
		else
		{
			cout << "vaishani" << endl;
		}
		return ;
	}
	int value = pow(2,bit-1);
	int check = 0;

	if(value < n)
	{
		return solve(n-value,cur^1);
	}
	if(check==0)
	{
		if(cur==0)
		{
			cout << "Anjali" << endl;
		}
		else
		{
			cout << "vaishani" << endl;
		}
	}
	return ;


}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		solve(n,0);
	}
	return 0;
}