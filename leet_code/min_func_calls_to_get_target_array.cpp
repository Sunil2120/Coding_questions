//Minimum number of function calls to get target array

// we have 2 choices :
// 1. increment any element by 1
// 2. multiply all elements by 2

//https://docs.google.com/document/d/1Y35F5x1iDUXzbBsHNTxeSmh6uWMCwo4YcJ-6d-Kz94Y/edit

// For each number a, we count the number of bits "1", as well as the length of a in binary format.
// The number of times Operation 0 is performed is equal to the total number of bits "1" in all the a’s in A.
// The number of times Operation 1 is performed is equal to maximumBitLength - 1 . maximumBitLength is the number of bits(both 0 and 1) in the binary form of the largest number in A.


#include<bits/stdc++.h>
using namespace std;

string binary_form(int n)
{
	string output;
	while(n!=0)
	{
		int rem = n%2;
		n = n/2;
		output.push_back(rem+'0');
	}
	return output;
}

int count_bits(int n)
{
	int count = 0;
	while(n!=0)
	{
		n = n & (n-1);
		count+=1;
	}
	return count;

}

int solve(int* arr,int n,int large)
{
	int total_set_bits = 0;
	for(int i=0;i<n;i++)
	{
		total_set_bits+=count_bits(arr[i]);
	}
	int oper0 = total_set_bits;
	int oper1 = binary_form(large).length() - 1;
	return oper0 + oper1;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int large = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		large = max(large,arr[i]);
	}
	if(large==0)
    {
        cout<< 0 << endl;// everything is zero
    }
    else
    {
    	cout << solve(arr,n,large) << endl;
    }
    return 0;
	
}