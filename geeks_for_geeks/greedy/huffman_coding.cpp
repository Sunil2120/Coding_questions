#include<bits/stdc++.h>
using namespace std;

// most frequent characters get less length code(top of the tree)
// less frequent characters get more length code(bottom of the tree)


struct node
{
	char data;
	int freq=0;
	struct node* left = NULL;
	struct node* right = NULL;
};

typedef struct node node;

struct compare
{
	bool operator()(node* a,node* b)
	{
		return a->freq > b->freq;
	}
};


node* build_tree(vector<char>& characters,vector<int>& frequencies,int n)
{
	if(n==0)
	{
		return NULL;
	}
	priority_queue<node*,vector<node*>,compare> Q;
	for(int i=0;i<n;i++)
	{
		node* temp = new node();
		temp->data = characters[i];
		temp->freq = frequencies[i];
		temp->left = NULL;
		temp->right = NULL;
		Q.push(temp);
	}
	while(Q.size() > 1)
	{
		node* a = Q.top();
		Q.pop();
		node* b = Q.top();
		Q.pop();
		node* temp = new node();
		temp->freq = a->freq + b->freq;
		temp->data = '#';
		temp->left = a;
		temp->right = b;
		Q.push(temp);
	}
	node* result = Q.top();
	Q.pop();
	return result;
}

void solve(node* root,unordered_map<char,string>& hash,string code)
{
	if(root==NULL)
	{
		return ;
	}
	// leaf node
	if(root->left==NULL && root->right==NULL)
	{
		hash[root->data]=code;
		return;
	}
	solve(root->left,hash,code+'0');
	solve(root->right,hash,code+'1');
	return ;

}

string encode(unordered_map<char,string>& hash,string input)
{
	string output = "";
	for(int i=0;i<input.size();i++)
	{
		output+=hash[input[i]];
	}
	return output;
}



int main()
{
	int n;
	cin >> n;
	vector<char> characters(n);
	vector<int> frequencies(n);
	for(int i=0;i<n;i++)
	{
		cin >> characters[i] >> frequencies[i];
	}
	node* root = NULL;
	root = build_tree(characters,frequencies,n);// build huffman tree
	unordered_map<char,string> hash;
	string output = "";
	solve(root,hash,output);
	string input;
	cin >> input;
	cout << encode(hash,input) << endl;
	return 0;

}