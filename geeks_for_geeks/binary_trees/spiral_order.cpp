
// two stacks method
//Time Complexity: O(n)
// Space Complexity: O(n)+(n)=O(n)
vector <int> zigZagTraversal(Node* root)
{
	vector<int> output;
	if(root==NULL)
	{
	    return output;
	}
	stack<Node*> cur_level;
	stack<Node*> next_level;
	cur_level.push(root);
	while(!cur_level.empty() || !next_level.empty())
	{
	    while(cur_level.size() > 0)
	    {
	        Node* temp = cur_level.top();
	        output.push_back(temp->data);
	        cur_level.pop();
	        if(temp->left!=NULL)
	        {
	            next_level.push(temp->left);
	        }
	        if(temp->right!=NULL)
	        {
	            next_level.push(temp->right);
	        }
	    }
	    while(next_level.size() > 0)
	    {
	        Node* temp = next_level.top();
	        output.push_back(temp->data);
	        next_level.pop();
	        if(temp->right!=NULL)
	        {
	            cur_level.push(temp->right);
	        }
	        if(temp->left!=NULL)
	        {
	            cur_level.push(temp->left);
	        }
	    }
	    
	}
	return output;
}