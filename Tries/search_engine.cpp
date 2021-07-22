#include<bits/stdc++.h>
using namespace std;


class Trie
{
	public:
		Trie* children[26];
		int weight;

	Trie()
	{
		for(int i=0;i<26;i++)
		{
			children[i]=NULL;
		}
		weight = 0;
	}

};


void  insert(Trie* head,string input,int value)
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
		if(cur->weight < value)
		{
			cur->weight = value;
		}
	}
	return ;
}

int searchEngine(Trie* head,string input)
{
	Trie*  cur = head;
	int result = 0;
	for(int i=0;i<input.size();i++)
	{
		int ch = input[i]-'a';
		if(cur->children[ch]==NULL)
		{
			return -1;
		}
		cur = cur->children[ch];
		result = cur->weight;
	}
	return result;
}


int main()
{
	int n;
	cin >> n;
    int q;
	cin >> q;
	Trie* head = new Trie();
	for(int i=0;i<n;i++)
	{
		string input;
		int value;
		cin >> input >> value;
		insert(head,input,value);
	}
	while(q--)
	{
		string sub;
		cin >> sub;
		cout  << searchEngine(head,sub) << endl;
	}
	
	return 0;

}