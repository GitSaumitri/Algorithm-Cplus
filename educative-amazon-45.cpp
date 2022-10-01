#include<bits/stdc++.h>
using namespace std;

//https://www.educative.io/blog/crack-amazon-coding-interview-questions

//1. Find the missing number in the array
int FindMissing(const vector<int>& input) {
	int n = input.size();
	int sum = 0;
	int sum_of_n = (n * (n+1))/2;
	for(int i=0; i<n; i++){
		sum += input[i];
	}
	return sum_of_n - sum;
}
//runtime - Linear, O(n)
//Memory Complexity - Constant, O(1)

//2. Determine if the sum of two integers is equal to the given value
bool find_sum_of_two(vector<int>& A, int val) {
  unordered_set<int> found_values;
  for (int& a : A) {
    if (found_values.find(val - a) != found_values.end()) {
      return true;
    }
    found_values.insert(a);
  }
  return false;
}
//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is linear, O(n).

//3. Merge two sorted linked lists
struct LinkedListNode{
    int data;
    struct LinkedListNode *next;
};
typedef LinkedListNode* NodePtr;
NodePtr merge_sorted(NodePtr head1, NodePtr head2) {
  
  // if both lists are empty then merged list is also empty
  // if one of the lists is empty then other is the merged list
  if (head1 == nullptr) {
    return head2;
  } else if (head2 == nullptr) {
    return head1;
  }


  NodePtr mergedHead = nullptr;
  if (head1->data <= head2->data) {
    mergedHead = head1;
    head1 = head1->next;
  } else {
    mergedHead = head2;
    head2 = head2->next;
  }

  NodePtr mergedTail = mergedHead;
  
  while (head1 != nullptr && head2 != nullptr) {
    NodePtr temp = nullptr;
    if (head1->data <= head2->data) {
      temp = head1;
      head1 = head1->next;
    } else {
      temp = head2;
      head2 = head2->next;
    }

    mergedTail->next = temp;
    mergedTail = temp;
  }

  if (head1 != nullptr) {
    mergedTail->next = head1;
  } else if (head2 != nullptr) {
    mergedTail->next = head2;
  }

  return mergedHead;
}
//run time - Linear, O(m + n) where m and n are lengths of both linked lists.
//space - Constant, O(1)

//4. Copy linked list with arbitrary pointer
struct LinkedListNode1{
    int data;
    struct LinkedListNode1 *next;
    struct LinkedListNode1 *arbitrary_pointer;
    LinkedListNode1(int d){
        data = d;
        next = arbitrary_pointer = NULL;
    }
};
LinkedListNode1* deep_copy_arbitrary_pointer(
    LinkedListNode1* head) {

    LinkedListNode1* curr = head, *temp;
 
    // insert additional node after
    // every node of original list
    while (curr)
    {
        temp = curr->next;
 
        // Inserting node
        curr->next = new LinkedListNode1(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
 
    curr = head;
 
    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        if(curr->next)
            curr->next->arbitrary_pointer = curr->arbitrary_pointer ?
                                 curr->arbitrary_pointer->next : curr->arbitrary_pointer;
 
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next?curr->next->next:curr->next;
    }
 
    LinkedListNode1* original = head, *copy = head->next;
 
    // save the start of copied linked list
    temp = copy;
 
    // now separate the original list and copied list
    while (original && copy)
    {
        original->next = original->next? original->next->next : original->next;
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
 
    return temp;

  return NULL;
}
//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is constant, O(1).

//5. Level Order Traversal of Binary Tree


int main(){
    cout<<"Amazon Common Interview Questions\n";
    return 0;
}
