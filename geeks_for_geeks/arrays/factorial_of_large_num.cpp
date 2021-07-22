// The following is a detailed algorithm for finding factorial.

// factorial(n)
// 1) Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output.
// 2) Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1.
// 3) Do following for all numbers from x = 2 to n.
// ……a) Multiply x with res[] and update res[] and res_size to store the multiplication result.

// How to multiply a number ‘x’ with the number stored in res[]?
// The idea is to use simple school mathematics. We one by one multiply x with every digit of res[]. The important point to note here is digits are multiplied from rightmost digit to leftmost digit. If we store digits in same order in res[], then it becomes difficult to update res[] without extra space. That is why res[] is maintained in reverse way, i.e., digits from right to left are stored.

// multiply(res[], x)
// 1) Initialize carry as 0.
// 2) Do following for i = 0 to res_size – 1
// ….a) Find value of res[i] * x + carry. Let this value be prod.
// ….b) Update res[i] by storing last digit of prod in it.
// ….c) Update carry by storing remaining digits in carry.
// 3) Put all digits of carry in res[] and increase res_size by number of digits in carry.



#include<bits/stdc++.h>
using namespace std;





#define MAX 100000 // max 500 digits

// we are storing digits in reverse order

int multiply(int x,int res[MAX],int res_size)
{
	long long carry = 0;
	for(int i=0;i<res_size;i++)
	{
		res[i] = res[i]*x + carry;
		int temp = res[i];
		res[i] = temp%10;// last  digit
		carry = temp/10;
	}
	// will add carry 
	while(carry)
	{
		res[res_size] = carry%10;
		carry = carry/10;
		res_size+=1;
	}
	return res_size;
}


int main()
{

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int res[MAX];
		res[0]=1;
		int res_size = 1;
		for(int i=2;i<=n;i++)
		{
			res_size = multiply(i,res,res_size);
		}
		// result will be int reverse order
		for(int i= res_size -1 ;i>=0;i--)
		{
			cout << res[i];
		}
		cout << endl;
		delete[] res;
	}
	return 0;
	
}