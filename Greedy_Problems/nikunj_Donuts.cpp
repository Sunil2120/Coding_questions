#include<bits/stdc++.h>
using namespace std;


bool compare(int a,int b)
{
	return (a>b);
}

int cakes(int n,int* input)
{
	if(n==0)
	{
		return 0;
	}
	sort(input,input+n,compare);
	int total = 0;
	for(int i=0;i<n;i++)
	{
		total+=input[i]*pow(2,i);
	}
	return total;

}

int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << cakes(n,input) << endl;
	delete[] input;
	return 0;
}