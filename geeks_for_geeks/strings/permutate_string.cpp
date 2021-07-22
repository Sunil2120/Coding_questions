#include<bits/stdc++.h>
using namespace std;


// using rotate function
void permutate(string input,string output)
{
	if(input=="")
	{
		cout << output << endl;
		return ;
	}
	for(int i=0;i<input.size();i++)
	{
		rotate(input.begin(),input.begin()+i,input.end());// ith element as first char
		permutate(input.substr(1),output+input[0]);
		
	}
	return ;
}
// using  backtracking

void permutate2(string input,int left,int right)
{
	// base case
	if(left==right)
	{
		cout << input << endl;
		return ;
	}
	for(int i=left;i<=right;i++)
	{
		// swap
		swap(input[left],input[i]);
		permutate2(input,left+1,right);
		// backtrack
		swap(input[left],input[i]);
	}

}

int main()
{
	string input;
	cin >> input;
	permutate2(input,0,input.size()-1);

}