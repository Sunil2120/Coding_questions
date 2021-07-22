#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data = 0;
	struct node* left=NULL;
	struct node* right= NULL;
};
typedef struct node NODE;




NODE*  insert(NODE* root,int key)
{
	NODE* temp = new NODE();
	temp->data = key;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	NODE* cur = root;
	NODE* prev = NULL;
	while(cur!=NULL)
	{
		prev = cur;
		if(key <= cur->data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	if(key <= prev->data)
	{
		prev->left = temp;
	}
	else
	{
		prev->right = temp;
	}
	return root;
	
}

int height(NODE* root,NODE* key)
{
	int count = 0;
	if(root==NULL)
	{
		return 0;
	}
	if(root==key)
	{
		return 0;
	}
	NODE*  cur = root;
	while(cur!=NULL && cur!=key )
	{
		
		if(key->data <= cur->data)
		{
			count+=1;
			cur = cur->left;
		}
		else
		{
			count+=1;
			cur = cur->right;
		}
	}
	return count;

}



void inorder(NODE* root,NODE* root2,vector<int>& v)
{
	if(root!=NULL)
	{
		inorder(root->left,root2,v);
		v.push_back(height(root2,root));
		inorder(root->right,root2,v);
	}
}


void solve(NODE* root)
{
	int green=0;
	int red=0;
	vector<int> result;
	inorder(root,root,result);
	for(int i=0;i<result.size();i++)
	{
		if(result[i]==0)
		{
			continue;
		}
		if((result[i]%2)==0)
		{
			green+=1;
		}
		else
		{
			red+=1;
		}
	}
	cout << red << " " << green << endl;
	return ;

}





int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		NODE* root = new NODE();
		root=NULL;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int value ;
			cin >> value;
			root = insert(root,value);
		}
		// pair<int,int> result = solve(root);
		// cout << result.first << " " << result.second << endl;
		solve(root);
		delete root;
	}
	return 0;
}