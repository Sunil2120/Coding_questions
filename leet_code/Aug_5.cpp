#include<bits/stdc++.h>
using namespace std;


struct trie
{
	struct trie* arr[26];
	int word_end = 0;
};
typedef struct trie trie;

void insert(trie* root,string str)
{
	trie* cur = root;
	for(int i=0;i<str.length();i++)
	{
		int index = str[i] - 'a';
		if(cur->arr[index]==NULL)
		{
			trie* temp = new trie();
			cur->arr[index]=temp;
		}
		cur=cur->arr[index];
	}
	cur->word_end = 1;
	return ;
}

bool search(trie* root,string str)
{
	if(root==NULL)
	{
		return false;
	}
	if(str.size()==0 && root->word_end==1)
	{
		return true;
	}
	if(str.size()==0 && root->word_end==0)
	{
		return false;
	}
	if(str[0]!='.')
	{
		trie* temp = root->arr[str[0]-'a'];
		return search(temp,str.substr(1));
	}
	else
	{
		bool ans = false;
		for(int i=0;i<26;i++)
		{
			if(root->arr[i]!=NULL)
			{
				trie* temp = root->arr[i];
				ans = ans || search(temp,str.substr(1));
			}
		}
		if(ans==true)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	trie* root = new trie();
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		string value;
		cin >> value;
		if(input=="insert")
		{
			insert(root,value);
		}
		else
		{
			cout << search(root,value) << endl;
		}
	}
}