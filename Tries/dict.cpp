#include<bits/stdc++.h>
using namespace std;


class Trie
{
	public:
		Trie* children[26];
		int we;

	Trie()
	{
		for(int i=0;i<26;i++)
		{
			children[i]=NULL;
		}
		we = 0;
	}

};

void dfs(Trie* cur,string input)
{
	if(cur->we==1)
	{
		cout << input << endl;
	}
	for(int i=0;i<26;i++)
	{
		if(cur->children[i]!=NULL)
		{
			char suni = i+'a';
			string temp = input  + suni;
			dfs(cur->children[i],temp);	
		}
		
	}
	
	return ;
}


void  insert(Trie* head,string input)
{
	Trie* cur = head;
	for(int i=0;i<input.size();i++)
	{
		int ch = input[i]-'a';
		if(cur->children[ch]==NULL)
		{
			cur->children[ch]=new Trie();
		}
		cur=cur->children[ch];
	}
	cur->we = 1;
	return ;
}


void search(Trie* head,string input)
{
	vector<string> result;
	Trie* cur = head;
	int count = 0;
	for(int i=0;i<input.size();i++)
	{
		int ch = input[i]-'a';
		if(cur->children[ch]==NULL)
		{
			break;
		}
		cur=cur->children[ch];
		count+=1;
	}
	if(count==input.size())
	{
		dfs(cur,input);
	}
	else
	{
		cout << "No suggestions" << endl;
		insert(head,input);
		return ;
	}

}





int main()
{
	int  n;
	cin >> n;
	Trie* head = new Trie();
	for(int i=0;i<n;i++)
	{
		string input;
		cin >> input;
		insert(head,input);
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		string sub;
		cin >> sub;
		search(head,sub);
	}
}