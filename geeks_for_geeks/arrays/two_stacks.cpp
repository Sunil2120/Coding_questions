// Your task is to implement  2 stacks in one array efficiently .

// Input:
// The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
// First line of each test case contains an integer Q denoting the number of queries . 
// A Query Q is of 4 Types
// (i)    1 1 x    (a query of this type means  pushing 'x' into the stack 1)
// (ii)   1 2      (a query of this type means to pop element from stack1  and print the poped element)
// (iii)  2 1 x  (a query of this type means pushing 'x' into the stack 2)
// (iv)  2 2     (a query of this type means to pop element from stack2 and print the poped element)
// The second line of each test case contains Q queries seperated by space.Output:
// The output for each test case will be space separated integers having -1 if the stack is empty else the element poped out from the stack. 

// Your Task:
// Since this is a function problem, you don't need to take any input. Just complete the provided functions. You are required to complete the 4 methods push1, push2 which takes one argument an integer 'x' to be pushed into the stack one and two and pop1, pop2 which returns the integer poped out from stack one and two.

// Expected Time Complexity: O(1) for all the four methods.
// Expected Auxiliary Space: O(1) for all the four methods.

1. For stack 1 start filling from the beginning and for stack 2 start filling from the end.


/*The structure of the class is
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};
*/


/* The method push to push element into the stack 2 */
void twoStacks :: push1(int x)
{
   if(top1 < top2-1)
   {
       top1+=1;
       arr[top1]=x;
   }

}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
   if(top2 > top1+1)
   {
       top2-=1;
       arr[top2]=x;
   }
}
   
/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1()
{
    if(top1>=0)
    {
        int value = arr[top1];
        top1-=1;
        return value;
    }
    else
    {
        return -1;
    }
    
}

/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2()
{
   if(top2 < size)
   {
       int value = arr[top2];
       top2+=1;
       return value;
   }
   else
   {
       return -1;
   }
    
}
