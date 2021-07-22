// Delete nodes which have a greater value on right side
// Last Updated: 28-09-2020
// Given a singly linked list, remove all the nodes which have a greater value on right side. 


// 1. Reverse the list. 
// 2. Traverse the reversed list. Keep max till now. If next node is less than max, then delete the next node, otherwise max = next node. 
// 3. Reverse the list again to retain the original order. 
// Time Complexity: O(n)

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3


// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60