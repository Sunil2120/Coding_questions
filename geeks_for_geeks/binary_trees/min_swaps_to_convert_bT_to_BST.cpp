// Minimum swap required to convert binary tree to binary search tree

// Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. 
// The task is to find the minimum number of swap required to convert it into Binary Search Tree.

// min swaps to convert binary tree to binary search tree
// Inorder of binary search tree is sorted
// so write the inorder of the given binary tree
// find the min swaps to sort  the array is the answer to this problem
// The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value.
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer. 
// Please refer below post to find minimum number of swaps required to get the array sorted.

// refer to min_swaps to sort problem in geeks for geeks > array
int min_swaps(vector<int> arr,int n)
{
	if(n==0)
	{
		return 0;
	}
	vector<bool> visited(n,false);
	vector<pair<int,int>> temp;
	for(int i=0;i<n;i++)
	{
		temp.push_back(make_pair(arr[i],i));
	}
	int count = 0;
	sort(temp.begin(),temp.end());
	for(int i=0;i<n;i++)
	{
		if(visited[i]==true || temp[i].second == i)
		{
			continue;
		}
		int cycle_size = 0;
		int j=i;
		while(visited[j]==false)
		{
			visited[j]=true;
			j=temp[j].second;
			cycle_size+=1;
		}
		if(cycle_size > 0)
		{
			count+=cycle_size-1;
		}
	}
	return count;
}