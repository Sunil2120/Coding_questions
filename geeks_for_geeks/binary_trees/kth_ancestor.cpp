
// your task is to complete this function

// BFS
// time complexity O(n)(traversal) + hash O(1) = O(n)
// space complexity O(n)(hash)
int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int ,int> hash;
   
    // BFS
    queue<Node*> Q;
    Q.push(root);
    hash[root->data]=-1;
    while(!Q.empty())
    {
        Node* cur = Q.front();
        Q.pop();
        if(cur->left!=NULL)
        {
            hash[cur->left->data]=cur->data;
            Q.push(cur->left);
        }
        if(cur->right!=NULL)
        {
            hash[cur->right->data]=cur->data;
            Q.push(cur->right);
        }
    }
    int cur = node;
    while(k-- && cur!=-1 )
    {
        cur = hash[cur];
    }
    return cur;
}


//DFS

Node* temp = NULL; 
//Time Complexity : O(n), where n is the number of nodes in the binary tree.
//auxillary space  : O(1)
// recursive function to calculate Kth ancestor 
Node* kthAncestorDFS(Node *root, int node , int &k) 
{    
    // Base case 
    if (!root) 
        return NULL; 
      
    if (root->data == node|| 
       (temp =  kthAncestorDFS(root->left,node,k)) || 
       (temp =  kthAncestorDFS(root->right,node,k))) 
    {    
        if (k > 0)         
            k--; 
          
        else if (k == 0) 
        { 
            // print the kth ancestor 
            cout<<"Kth ancestor is: "<<root->data; 
              
            // return NULL to stop further backtracking 
            return NULL; 
        } 
          
        // return current node to previous call 
        return root; 
    } 
}  


