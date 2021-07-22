// maximum xor pair in a given array
#include<bits/stdc++.h>
using namespace std;


struct trie
{
	struct trie* left=NULL;
	struct trie* right = NULL;
};

typedef struct trie Trie;


void insert(Trie* head,int key)
{
	Trie* cur = head;
	for(int i=31;i>=0;i--)
	{
		// check the ith bit
		int b = key&(1 << i);
		if(b==0)
		{
			if(cur->left==NULL)
			{
				Trie* temp = new Trie();
				cur->left = temp;
			}
			cur=cur->left;
		}
		else
		{
			if(cur->right==NULL)
			{
				Trie* temp = new Trie();
				cur->right = temp;
			}
			cur=cur->right;
		}
	}
	return ;
}


int findMax_XOR(Trie* head,int* arr,int n)
{
	int max_value = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int value = arr[i];
		Trie* cur = head;
		int cur_value = 0;
		for(int j=31;j>=0;j--)
		{
			int b = value&(1<<j);
			// if 1 we need 0 if 0 we need 1
			if(b==0)
			{
				if(cur->right!=NULL)// pair of 0 and 1 is formed which is 1
				{
					cur=cur->right;
					cur_value+=pow(2,j);
				}
				else
				{
					cur = cur->left;
				}
				
			}
			else
			{
				if(cur->left!=NULL)// pair of 1 and 0 is formed which is 1
				{
					cur_value+=pow(2,j);
					cur=cur->left;
				}
				else
				{
					cur=cur->right;
					
				} 
			}
		}
		if(cur_value > max_value)
		{
			max_value = cur_value;
		}
	}
	return max_value;
}




int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	Trie* head = new Trie();
	for(int i=0;i<n;i++)
	{
		insert(head,arr[i]);
	}
	cout << findMax_XOR(head,arr,n)<< endl;
	delete[] arr;
	delete head;
	return 0;
}