#include<bits/stdc++.h>
using namespace std;


struct Trie
{
	struct Trie* left=NULL;
	struct Trie* right = NULL;

};

typedef struct Trie Trie;

void insert(Trie* head,int key)
{
	Trie* cur = head;
	for(int i=31;i>=0;i--)
	{
		// int b = key&(1<<i);
		int b = (key>>i)&1;
		if(b==0)
		{
			if(cur->left==NULL)
			{
				cur->left = new Trie();
			}
			cur=cur->left;
		}
		else
		{
			if(cur->right==NULL)
			{
				cur->right = new Trie();
			}
			cur=cur->right;
		}
	}
	return ;
}

int findMaxPair(Trie* head,int key)
{
	Trie* cur = head;
	int value = 0;
	for(int i=31;i>=0;i--)
	{
		int b = (key>>i)&1;
		if(b==0)// we are looking for 1
		{
			if(cur->right!=NULL)
			{
				// we will get result 1
				value+=pow(2,i);
				cur=cur->right;
			}
			else
			{
				cur=cur->left;
			}
		}
		else// we are looking for 0
		{
			if(cur->left!=NULL)
			{
				// we will get result 1
				value+=pow(2,i);
				cur=cur->left;
			}
			else
			{
				cur = cur->right;
			}

		}
	}
	return value;
}


int  solve(Trie* head,int* arr,int n)
{
	int pre_xor = 0;
	int result = INT_MIN;
	insert(head,pre_xor);
	for(int i=0;i<n;i++)
	{
		pre_xor = pre_xor ^ arr[i];
		insert(head,pre_xor);
		// case 2 to remove some of the prefixes
		int m = findMaxPair(head,pre_xor);// we will get only prefix ending with arr[i]
		if(m > result)
		{
			result = m;
		}
	}
	return result;
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n]();
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	Trie* head = new Trie();

	cout << solve(head,arr,n) << endl;

}