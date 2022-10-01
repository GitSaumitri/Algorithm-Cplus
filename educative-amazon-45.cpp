#include<bits/stdc++.h>
using namespace std;

//https://www.educative.io/blog/crack-amazon-coding-interview-questions
//Data structures you should know: 
//Arrays, Stacks, Queues, Linked lists, Trees, Graphs, Hash tables
//Algorithms you should know: 
//Breadth First Search, Depth First Search, Binary Search, Quicksort, Mergesort, Dynamic programming, Divide and Conquer
//https://www.educative.io/blog/why-amazon-interview-question
//https://www.educative.io/blog/behavioral-interviews-how-to-prepare-and-ace-interview-questions

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
struct BinaryTreeNode {
  int data;
  struct BinaryTreeNode *left, *right;
};

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

bool is_bst1(BinaryTreeNode* root) {
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
/* CHEK FOR THE DP SOLUTION
To achieve memoization, you can store the second string in a new set each time. This will reduce both time and memory complexities.To achieve memoization, you can store the second string in a new set each time. This will reduce both time and memory complexities.
*/


// 8. Reverse Words in a Sentence
// reverse the string and then reverse each word
void str_rev(char * str, int len) {

  if (str == nullptr || len < 2) {
    return;
  }

  char * start = str;
  char * end = str + len - 1;

  while (start < end) {
    if (start != nullptr && end != nullptr) {
      char temp = * start;
      * start = * end;
      * end = temp;
    }
    start++;
    end--;
  }
}

void reverse_words(char * sentence) {

  // Here sentence is a null-terminated string ending with char '\0'.
  if (sentence == nullptr) {
    return;
  }

  // To reverse all words in the string, we will first reverse
  // the string. Now all the words are in the desired location, but
  // in reverse order: "Hello World" -> "dlroW olleH".
  int len = strlen(sentence);
  str_rev(sentence, len);

  // Now, let's iterate the sentence and reverse each word in place.
  // "dlroW olleH" -> "World Hello"
  char * start = sentence;
  char * end;
  while (true) {
    // find the  start index of a word while skipping spaces.
    while (start && *start == ' ') {
      ++start;
    }

    if (start == nullptr || *start == '\0') {
      break;
    }

    // find the end index of the word.
    end = start + 1;
    while (end && *end != '\0' && *end != ' ') {
      ++end;
    }

    // let's reverse the word in-place.

    if (end != nullptr) {
      str_rev(start, (end - start));
    }

    start = end;
  }
}

//The runtime complexity of this solution is linear, O(n).
//The memory complexity of this solution is constant, O(1).

//9. How many ways can you make change with coins and a total amount
int solve_coin_change(vector<int>& denominations, int amount) {

  vector<int> solution(amount + 1); 
  solution[0] = 1;

  for (int den: denominations) {
    for (int i = den; i < (amount + 1); ++i) {
      solution[i] += solution[i - den]; 
    }
  }
  
  return solution.back();
}
//The runtime complexity of this solution is quadratic, O(m×n), where m is the number of denominations and n is the total amount.
//The memory complexity of this solution is linear, O(n), where n is the total amount.

//10. Find Kth permutation
int factorial(int n) {
  if (n == 0 || n == 1) return 1;
  return n * factorial(n -1 );
}

void find_kth_permutation(
    vector<char>& v,
    int k,
    string& result) {
  if (v.empty()) {
    return;
  }
  
  int n = (int)(v.size());
  // count is number of permutations starting with each digit
  int count = factorial(n - 1);
  int selected = (k - 1) / count;

  result += v[selected];
  v.erase(v.begin() + selected);

  k = k - (count * selected);
  find_kth_permutation(v, k, result);
}

string get_permutation(int n, int k) {
    vector<char> v;
    for (char i = 1; i <= n; ++i) {
        v.push_back(i + '0');
    }
    
    string result;
    find_kth_permutation(v, k, result);
    return result;
}
//Runtime Complexity: Linear, O(n)
//Memory Complexity: Linear, O(n)


//11. Find all subsets of a given set of integers
int get_bit(int num, int bit) {
	int temp = (1 << bit);
	temp = temp & num;
	if (temp == 0) {
		return 0;
	}
	return 1;
}

void get_all_subsets(vector<int>& v, vector<unordered_set<int>>& sets) {	
	int subsets_count = pow((double)2, (double)v.size());
	for (int i = 0; i < subsets_count; ++i) {
		unordered_set<int> set;
		for (int j = 0; j < v.size(); ++j) {
			if (get_bit(i, j)) {
				set.insert(v[j]);
			}
		}
		sets.push_back(set);
	}
}
//runtime - Exponential, O(2^{n}* n) - where ‘n’ is number of integers in the given set.
//space - Exponential, O(2^{n}* n) O(2n∗n)

//12. Print balanced brace combinations
void print(vector<vector<char>> result){
  for(int i = 0; i < result.size(); i++){
    cout << "[ ";
    for(int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << ", "; 
    }
    cout << "]" << endl;
  }
}

void print_all_braces_rec(
    int n,
    int left_count,
    int right_count,
    vector<char>& output, vector<vector<char>>& result) {

  if (left_count == n && right_count == n) {
    result.push_back(output);
  }

  if (left_count < n) {
    output.push_back('{');
    print_all_braces_rec(n, left_count + 1, right_count, output, result);
    output.pop_back();
  }

  if (right_count < left_count) {
    output.push_back('}');
    print_all_braces_rec(n, left_count, right_count + 1, output, result);
    output.pop_back();
  }
}

vector<vector<char>> print_all_braces(int n) {
  vector<vector<char>> result;
  vector<char> output;
  print_all_braces_rec(n, 0, 0, output, result);
  return result;
}
//The runtime complexity of this solution is exponential, 2^{n}
//The memory complexity of this solution is linear, O(n).

//13. Clone a Directed Graph
struct Node {
  int data;
  list<Node*> neighbors;
  Node(int d) : data(d) {}
};

Node* clone_rec(Node* root, 
        unordered_map<Node*, 
        Node*>& nodes_completed) {
  
  if (root == nullptr) {
    return nullptr;
  }

  Node* pNew = new Node(root->data);
  nodes_completed[root] = pNew;
  
  for (Node* p : root->neighbors) {
    auto x = nodes_completed.find(p);
    if (x == nodes_completed.end()){
      pNew->neighbors.push_back(clone_rec(p, nodes_completed));
    } else {
      pNew->neighbors.push_back(x->second /*value*/);
    }
  }
  return pNew;
}

Node* clone(Node* root) {
  unordered_map<Node*, Node*> nodes_completed;
  return clone_rec(root, nodes_completed);
}
//runtime - Linear, O(n).
//Logarithmic, O(n). ‘n’ is the number of vertices in the graph.

//14. Find Low/High Index
int find_low_index(vector<int>& arr, int key) {
  int low = 0;
  int high = arr.size() - 1;
  int mid = high / 2;

  while (low <= high) {
    int mid_elem = arr[mid];

    if (mid_elem < key) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
    mid = low + (high - low) / 2;
  }
  if (low < arr.size() && arr[low] == key) {
    return low;
  }
  return -1;
}

int find_high_index(vector<int>& arr, int key) {
  int low = 0;
  int high = arr.size()-1;
  int mid = high/2;
  while (low <= high) {
    int mid_elem = arr[mid];
    if (mid_elem <= key) {
      low = mid+1;
    } else {
      high = mid-1;
    }
    mid = low + (high-low)/2;
  }
  
  if(high == -1)
    return high;
  
  if (high < arr.size() && arr[high] == key) {
    return high;
  }

  return -1;
}
//Runtime Complexity: Logarithmic, O(logn)
//Memory Complexity: Constant, O(1)

//15. Search Rotated Array
int binary_search(vector<int>& arr, int start, int end, int key) {
  // assuming all the keys are unique.  
  if (start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2;
  if (arr[mid] == key) {
    return mid;
  }

  if (arr[start] <= arr[mid] && key <= arr[mid] && key >= arr[start]) {
    return binary_search(arr, start, mid-1, key);
  }

  else if (arr[mid] <= arr[end] && key >= arr[mid] && key <= arr[end]) {
    return binary_search(arr, mid+1, end, key);
  }

  else if (arr[end] <= arr[mid]) {
    return binary_search(arr, mid+1, end, key);
  }

  else if (arr[start] >= arr[mid]) {
    return binary_search(arr, start, mid-1, key);
  }

  return -1;
}

int binary_search_rotated(vector<int>& arr, int key) {
  return binary_search(arr, 0, arr.size()-1, key);
}
//Runtime Complexity: Logarithmic, O(logn)
//Memory Complexity: Logarithmic, O(logn)

//16. K largest elements from an array
//17. Convert a Binary tree to DLL
//18. Given a binary tree T, find the maximum path sum. The path may start and end at any node in the tree.
//19. Rotate a matrix by 90 degrees
//20. Assembly line scheduling with dynamic programming
//21. Implement a stack with push(), min(), and pop() in O(1) time
//22. How do you rotate an array by K?
//23. Design Snake Game using Object Oriented analysis and design technique.
//24. Print all permutations of a given string using recursion
//25. Implement a queue using a linked list
//26. Find the longest increasing subsequence of an array
//27. Lowest common ancestor in a Binary Search Tree and Binary Tree
//28. Rotate a given list to the right by k places, which is non-negative.
//29. Write a function that counts the total of set bits in a 32-bit integer.
//30. How do you detect a loop in a singly linked list?
//31. Reverse an array in groups
//32. Given a binary tree, check if it’s a mirror of itself
//33. Josephus problem for recursion
//34. Zero Sum Subarrays
//35. Huffman Decoding for greedy algorithms
//36. Egg Dropping Puzzle for dynamic programming
//37. N-Queen Problem
//38. Check if strings are rotations of each other
//39. 0-1 Knapsack Problem
//40. Unbounded knapsack problem
//41. Longest palindromic subsequence
//42. Print nth number in the Fibonacci series
//43. Longest common substring
//44. Longest common subsequence

int main(){
    cout<<"Amazon Common Interview Questions\n";
    return 0;
}
