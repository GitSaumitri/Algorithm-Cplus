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
// Using two queues
void level_order_traversal_1(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  queue<BinaryTreeNode*> queues[2];
  queue<BinaryTreeNode*>* current_queue = &queues[0];
  queue<BinaryTreeNode*>* next_queue = &queues[1];

  current_queue->push(root);
  int level_number = 0;

  while (!current_queue->empty()) {
    BinaryTreeNode* temp = current_queue->front();
    current_queue->pop();
    cout << temp->data << ",";

    if (temp->left != nullptr) {
      next_queue->push(temp->left);
    }

    if (temp->right != nullptr) {
      next_queue->push(temp->right);
    }

    if (current_queue->empty()) {
      cout << endl;
      ++level_number;
      current_queue = &queues[level_number % 2];
      next_queue = &queues[(level_number + 1) % 2];
    }
  }
  cout << endl;
}
//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is linear, O(n).

// using single queue
string level_order_traversal(BinaryTreeNode* root) {
  string result = "";
  //TODO: Write - Your - Code
  queue<BinaryTreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int len = q.size();
    for(int i=0; i<len; i++){
      BinaryTreeNode *node = q.front();
      q.pop();
      result += to_string(node->data)+",";
      if(node->left)
        q.push(node->left);
      if(node->right)
        q.push(node->right);
    }
  } 
  return result;
}
//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is linear, O(n).

//6. Determine if a binary tree is a binary search tree
bool is_bst_rec(
    BinaryTreeNode* root,
    int min_value,
    int max_value) {

  if (root == nullptr) {
    return true;
  }

  if (root->data < min_value || 
      root->data > max_value) {
    return false;
  }

  return 
    is_bst_rec(root->left, min_value, root->data) &&
      is_bst_rec(root->right, root->data, max_value);
}

bool is_bst(BinaryTreeNode* root) {
  return 
    is_bst_rec(
      root,
      numeric_limits<int>::min(), 
      numeric_limits<int>::max());
}
//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is linear, O(n).

bool is_bst_tree(BinaryTreeNode* root, BinaryTreeNode* low, BinaryTreeNode* high){
    if(root==nullptr){
        return true;
    }
    if(low!=nullptr && (root->data < low->data))
        return false;
        
    if(high!=nullptr && (root->data < high->data))
        return false;
    
    return (!is_bst_tree(root->left, nullptr, root) &&
        (!is_bst_tree(root->right, root, nullptr)));
}

bool is_bst(BinaryTreeNode* root) {
    return is_bst_tree(root, nullptr, nullptr);
}

/*
7. String segmentation
You are given a dictionary of words and a large input string. 
You have to find out whether the input string can be completely segmented into the words of a given dictionary. 
*/
bool can_segment_string(string s, unordered_set <string> & dictonary) {
  for (int i = 1; i <= s.length(); ++i) {
    string first = s.substr(0, i);
    if (dictonary.find(first) != dictonary.end()) {
      string second = s.substr(i);
      if (second.empty() || dictonary.find(second) != dictonary.end() || can_segment_string(second, dictonary)) {
        return true;
      }
    }
  }
  return false;
}



int main(){
    cout<<"Amazon Common Interview Questions\n";
    return 0;
}
