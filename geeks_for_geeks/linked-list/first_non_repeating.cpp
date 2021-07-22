#include<bits/stdc++.h>
using namespace std;

// query will take O(1) and insertion will also take O(1)
// space O(256)

// where as in other methods query O(n) insertion O(n) space O(n)


// The idea is to use a DLL (Doubly Linked List) to efficiently get the first non-repeating character from a stream. The DLL contains all non-repeating characters in order, i.e., the head of DLL contains first non-repeating character, the second node contains the second non-repeating and so on.
// We also maintain two arrays: one array is to maintain characters that are already visited two or more times, we call it repeated[], the other array is an array of pointers to linked list nodes, we call it inDLL[]. The size of both arrays is equal to alphabet size which is typically 256.

// Create an empty DLL. Also create two arrays inDLL[] and repeated[] of size 256. inDLL is an array of pointers to DLL nodes. repeated[] is a boolean array, repeated[x] is true if x is repeated two or more times, otherwise false. inDLL[x] contains a pointer to a DLL node if character x is present in DLL, otherwise NULL.
// Initialize all entries of inDLL[] as NULL and repeated[] as false.
// To get the first non-repeating character, return character at head of DLL.
// Following are steps to process a new character ‘x’ in a stream.
// If repeated[x] is true, ignore this character (x is already repeated two or more times in the stream)
// If repeated[x] is false and inDLL[x] is NULL (x is seen first time). Append x to DLL and store address of new DLL node in inDLL[x].
// If repeated[x] is false and inDLL[x] is not NULL (x is seen second time). Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] as NULL and repeated[x] as true.
// Note that appending a new node to DLL is O(1) operation if we maintain tail pointer. Removing a node from DLL is also O(1). So both operations, addition of new character and finding first non-repeating character take O(1) time.
struct node

{
	char data;
	struct node* prev = NULL;
	struct node* next = NULL;
};

typedef struct node Node;

Node* newnode(char key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}
void append_node(Node** head,Node** tail,char cur)
{
	Node* temp = newnode(cur);
	if((*head)==NULL)
	{
		(*head) = (*tail) = temp;
		return ;
	}
	(*tail)->next = temp;
	temp->prev = (*tail);
	(*tail)=temp;
	return ;
}

void remove_node(Node** head,Node** tail,Node* temp)
{
	if((*head)==NULL)
	{
		return ;
	}
	if((*head)==temp)
	{
		(*head)=(*head)->next;
		
	}
	else if((*tail)==temp)
	{
		(*tail)=(*tail)->prev;
		
	}
	else
	{
		Node* prev = temp->prev;
		Node* next = temp->next;
		prev->next = next;
		next->prev = prev;
	}
	delete temp;
	return ;
}
void firstnonrepeating()
{
	Node* dll[256];
	bool repeated[256];
	string input;
	cin >> input;
	Node* head=NULL;
	Node* tail = NULL;
	for(int i=0;i<256;i++)
	{
		dll[i]=NULL;
		repeated[i]=false;
	}
	for(int i=0;i<input.size();i++)
	{
		char cur = input[i];
		if(repeated[cur]==true)
		{
			continue;
		}
		if(repeated[cur]==false && dll[cur]==NULL)//appearing for the first time
		{
			append_node(&head,&tail,cur);
			dll[cur]=tail;
		}
		else if(repeated[cur]==false && dll[cur]!=NULL)//second time
		{
			remove_node(&head,&tail,dll[cur]);
			repeated[cur]=true;
			dll[cur]=NULL;
		}
		if(head!=NULL)
		{
			cout << head->data << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return ;

}
int main()
{
	firstnonrepeating();
}