/* Strivers binary tree series */
    /* 5. recurssive preorder traversal */
    /* 6. recurssive inorder traversal */
    /* 7. recurssive postorder traversal */
    /* 8. level order traversal */
    /* 9. iterative preorder traversal */
    /* 10. iterative inorder traversal */
    /* 11. iterative postorder traversal - using 2 stacks */
    /* 12. iterative postorder traversal - using 1 stacks */
    /* 13. pre-in-post order in one traversal */
    /* 14. Maximum depth of Binary Tree */
    /* 15. Check for balanced Binary Tree */
    /* 16. Diameter of Binary Tree */
    /* 17. Maximum Path sum */
    /* 18. Check if two trees are identical */
    /* 19. Zig-Zag traversal */
    /* 20. Boundary traversal */
    /* 21. Vertical order traversal */
    /* 22. Top view of Binary tree */
    /* 23. Bottom view of Binary tree */
    /* 24. Right/Left view of Binary tree */
    /* 25. Check for Symmetrical Binary tree */
    /* 26. Print Root to node path in binary tree */
    /* 27. Lowest Common Ancestor in binary tree */
    /* 28. Maximum width of Binary tree */
    /* 29. Children sum property in Binary tree */
    /* 30. Print all nodes to a distance K in Binary tree */
    /* 31. Minimum time taken to Burn the binary tree from root to node */
    /* 32. Count total nodes in a complete binary tree */
    /* 33. Requirement needed to construct a unique binary tree */
    /* 34. Construct a binary tree from preorder and inorder */
    /* 35. Construct a binary tree from postorder and inorder */
    /* 36. Serialize and de-serialize binary tree */
    /* 37. Morris traversal - preorder - inorder */
    /* 38. Flatterened a binary tree to linked list */
    /* 39. Introduction to binary search tree */
    /* 40. Search in a Binary search tree */
    /* 41. Ceil in a binary search tree */
    /* 42. Floor in a binary search tree */
    /* 43. Insert a given node in binary search tree */
    /* 44. Delete a node in binary search tree */
    /* 45. K-th smallest/largest element in a BST */
    /* 46. Check if a tree is a BST */
    /* 47. LCA in BST */
    /* 48. Construct a BST from a preorder traversal */
    /* 49. Inorder successor/predecessor in BST */
    /* 50. Binary search tree iterator */
    /* 51. Two SUM in BST */
    /* 52. Correct BST with two nodes swapped */
    /* 53. Largest BST in Binary tree */ 

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

#define TreeNode BinaryTree
struct BinaryTree {
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;

   BinaryTree(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTreeSeries{
    private:
    /*
    struct BinaryTree {
        int data;
        struct BinaryTree *left;
        struct BinaryTree *right;

        BinaryTree(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
    };
    */
    public:
    BinaryTree *root=nullptr;

    BinaryTree * getNewBNode(int val){
        BinaryTree *n = new BinaryTree(val);
        return n;
    }

    /* 5. recurssive preorder traversal */
    void recurssive_preorder(BinaryTree *root);

    /* 6. recurssive inorder traversal */
    void recurssive_inorder(BinaryTree *root);

    /* 7. recurssive postorder traversal */
    void recurssive_postorder(BinaryTree *root);

    /* 8. level order traversal */
    void levelorder_traversal(BinaryTree *root);

    /* 9. iterative preorder traversal */
    void iterative_preorder(BinaryTree *root);

    /* 10. iterative inorder traversal */
    void iterative_inorder(BinaryTree *root);

    /* 11. iterative postorder traversal - using 2 stacks */
    void iterative_postorder2(BinaryTree *root);

    /* 12. iterative postorder traversal - using 1 stacks */
    //void iterative_postorder(BinaryTree *root);

    /* 13. pre-in-post order in one traversal */
    //void iterative_pre-in-post(BinaryTree *root);

    /* 14. Maximum depth of binary tree
           Maximum height of binary tree */
    int Height(BinaryTree *root);

    /* 15. Check for balanced binary tree */
    int dfsHeight(BinaryTree *root);
    bool isBalanced(BinaryTree *root);

    /* 16. Diameter of Binary Tree */
    int diaHeight(BinaryTree *root, int& dia);
    int diameter(BinaryTree *root);

    /* 17. Maximum path sum */
    int maxPath(BinaryTree *root, int &path);
    int maxPathSum(BinaryTree *root);

    /* 18. Check if two trees are identical */
    bool isSameTree(BinaryTree* root1, BinaryTree* root2);

    /* 19. Zig-Zag traversal */
    vector<vector<int>> zigzag_traversal(BinaryTree *root);

    /* 20. Boundary traversal in Binary tree */
    bool isLeaf(BinaryTree *node);
    void addLeftBoundary(BinaryTree *root, vector<int>& res);
    void addRightBoundary(BinaryTree *root, vector<int>& res);
    void addLeavesBoundary(BinaryTree *root, vector<int>& res);
    vector<int> printBoundary(BinaryTree *root);

    /* 21. Vertical order traversal */
    vector<vector<int>> verticalTraversal(TreeNode *root);

    /* 22. top view traversal */
    vector<int> topViewTraversal(TreeNode *root);

    /* 23. Bottom view traversal */
    vector<int> bottomViewTraversal(TreeNode *root);

    /* 24. Right/Left view traversal */
    void tree_traversal(TreeNode *root, int level, vector<int>& res);
    vector<int> rightSideView(TreeNode *root);
    void tree_traversal1(TreeNode *root, int level, vector<int>& res);
    vector<int> leftSideView(TreeNode *root);

    /* 25. Check for symmetrical binary tree */
    bool checkSymmetrical(TreeNode *left, TreeNode *right);
    bool isSymmetrical(TreeNode *root);  

    /* 26. Print node to root path */
    bool getRootToNodePath(TreeNode *root, vector<int> &arr, int x);
    vector<int> rootToNodePath(TreeNode *root, int value);

    /* 27. LCA */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

    /* 28. Maximum width of a binary tree */
    int widthOfBinaryTree(TreeNode* root);

    /* 29. Children sum property */
    void childrenSumProperty(BinaryTree* root);

    /* 30. Print all nodes to a distance K in Binary tree */
    /* 31. Minimum time taken to Burn the binary tree from root to node */
    /* 32. Count total nodes in a complete binary tree */
    /* 33. Requirement needed to construct a unique binary tree */
    /* 34. Construct a binary tree from preorder and inorder */
    /* 35. Construct a binary tree from postorder and inorder */
    /* 36. Serialize and de-serialize binary tree */
    /* 37. Morris traversal - preorder - inorder */
    /* 38. Flatterened a binary tree to linked list */
    /* 39. Introduction to binary search tree */

    /* 40. Search in a Binary search tree */
    TreeNode * searchBST(TreeNode* root, int val);

    /* 41. Ceil in a binary search tree */
    int findCeilinBST(TreeNode* root, int val);
    
    /* 42. Floor in a binary search tree */
    int findFloorBST(TreeNode* root, int val);
    
    /* 43. Insert a given node in binary search tree */
    TreeNode * insertIntoBST(TreeNode *bst, int val);
    
    /* 44. Delete a node in binary search tree */
    TreeNode * findlastRight(TreeNode *root);
    TreeNode * deleteHelper(TreeNode *root);
    TreeNode * deleteNodeBST(TreeNode *bst, int val);

    /* 45. K-th smallest/largest element in a BST */
    TreeNode* kthLargest(TreeNode* root, int &k);
    TreeNode* kthSmallest(TreeNode* root, int &k);

    /* 46. Check if a tree is a BST */
    bool validateBST(TreeNode *root, TreeNode *low, TreeNode *high);

    /* 47. LCA in BST */
    TreeNode * lcaBST(TreeNode* root, int a, int b);

    /* 48. Construct a BST from a preorder traversal */
    TreeNode* bstFromPreorder(vector<int>& arr);
    TreeNode* bstBuild(vector<int>& arr, int& i, int bound);

    /* 49. Inorder successor/predecessor in BST */
    TreeNode* inorderSuccessorBST(TreeNode *root, int val);

    /* 50. Binary search tree iterator */
    /* 51. Two SUM in BST */
    /* 52. Correct BST with two nodes swapped */
    /* 53. Largest BST in Binary tree */ 


};

/* 5. recurssive preorder traversal */
void BinaryTreeSeries::recurssive_preorder(BinaryTree *root){
    if(root==nullptr){
        //cout<<"No elements in the Tree\n";
        return;
    }
    cout<<root->data<<" ";
    recurssive_preorder(root->left);
    recurssive_preorder(root->right);
}

/* 6. recurssive inorder traversal */
void BinaryTreeSeries::recurssive_inorder(BinaryTree *root){
    if(root){
        recurssive_inorder(root->left);
        cout<<root->data<<" ";
        recurssive_inorder(root->right);
    }
}   

/* 7. recurssive post order traversal */
void BinaryTreeSeries::recurssive_postorder(BinaryTree *root){
    if(root){
        recurssive_postorder(root->left);
        recurssive_postorder(root->right);
        cout<<root->data<<" ";
    }
}

/* 8. level order traversal */
void BinaryTreeSeries::levelorder_traversal(BinaryTree *root){
    queue<BinaryTree *>q;
    if(root==nullptr){
        return;
    }
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            BinaryTree *node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            cout<<node->data<<" ";
        }
    }
    /*
    while(!q.empty()){
        BinaryTree * node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
    */
}   

/* 9. iterative preorder traversal - DLR */
void BinaryTreeSeries::iterative_preorder(BinaryTree *root){
    if(root==nullptr)
        return;
    stack<BinaryTree*>s;
    s.push(root);
    while(!s.empty()){
        BinaryTree *node = s.top();
        s.pop();
        cout<<node->data<<" ";
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }
}

/* 10. iterative inorder traversal - LDR*/
void BinaryTreeSeries::iterative_inorder(BinaryTree *root){  
    if(root==nullptr){
        return;
    }
    stack<BinaryTree*>st;
    BinaryTree *node = root;

    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }else {
            if(st.empty()){
                break;
            }
            node = st.top(); st.pop();
            cout<<node->data<<" ";
            node=node->right;
        }
    }
}

/* 11. iterative post order traversal - LRD */
// using two stacks
void BinaryTreeSeries::iterative_postorder2(BinaryTree *root){
    //vector<int> postorder;
    if(root==nullptr)
        return;
    stack<BinaryTree *> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        BinaryTree * node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left){
            st1.push(node->left);
        }
        if(node->right){
            st1.push(node->right);
        }
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        //postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return;
    //return postorder;
}

/* 14. Maximum depth of binary tree
           Maximum height of binary tree 
    Need to traverl all the nodes - O(n) space - O(n)           
*/
int BinaryTreeSeries::Height(BinaryTree *root){
    if(root == NULL)
        return 0;
    else 
        return 1 + max(Height(root->left), Height(root->right));
}

/* 15. Check for balanced binary tree 
    we can check height at each node - O(n*n)
    or modify the above height itself - O(n)

    return height if a balance tree else return -1
*/
int BinaryTreeSeries::dfsHeight(BinaryTree *root){
    if(root==NULL)
        return 0;
    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh-rh) > 1)
        return -1; //if this node is not balanced
    return max(lh,rh) + 1;
}    

bool BinaryTreeSeries::isBalanced(BinaryTree *root){
    return dfsHeight(root) != -1;
}

/* 16. Diameter of Binary Tree 
    Longest path between two nodes
    Path doesn't need to pass via root
    for a given node - find the left height and right height
        1. find height at each node - O(n*n)
        2. 
*/
int BinaryTreeSeries::diaHeight(BinaryTree *root, int& dia){
    if(root==nullptr)
        return 0;
    int lh = diaHeight(root->left,dia);
    int rh = diaHeight(root->right,dia);
    
    dia = max(dia, lh+rh);
    return 1 + max(lh,rh);
}
int BinaryTreeSeries::diameter(BinaryTree *root){
    int dia=0;
    diaHeight(root,dia);
    return dia;
}

/* 17. Maximum path sum
    A valid path passes through one node once only.
    Use the same logic as applied for diameter
*/
int BinaryTreeSeries::maxPath(BinaryTree *root, int& max_path){
    if(root==nullptr)
        return 0;
    int lsum = max(0, maxPath(root->left,max_path));
    //don't take the negative value - so take max between 0 and value
    int rsum = max(0, maxPath(root->right,max_path));

    max_path = max(max_path, lsum + rsum + root->data);
    return root->data + max(lsum,rsum);
}
int BinaryTreeSeries::maxPathSum(BinaryTree *root){
    int path=INT_MIN; // we might max as negative value as well
    maxPath(root,path);
    return path;
}

/* 18. Check if two trees are identical */
bool BinaryTreeSeries::isSameTree(BinaryTree* root1, BinaryTree* root2){
    if(root1 == nullptr || root2 == nullptr){
        return root1 == root2;
    }

    return (root1->data == root2->data) &&
        (isSameTree(root1->left,root2->left)) &&
        (isSameTree(root1->right, root2->right));
}

/* 19. Zig-Zag traversal 
    //follow same as level order traversal
*/
vector<vector<int>> BinaryTreeSeries::zigzag_traversal(BinaryTree *root){
    queue<BinaryTree *> q;
    vector<vector<int>> res;
    if(root==nullptr){
        return res;
    }
    q.push(root);
    bool leftToright=true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i=0; i<size; i++){
            BinaryTree *node = q.front();
            q.pop();
            //find position to fill node value
            int index = leftToright? i : (size - i - 1);
            row[index] = node->data;

            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            
            //cout<<node->data<<" ";
        }
        //after this level
        leftToright = !leftToright;
        res.push_back(row);
    }
    return res;
}

/* 20. Boundary traversal 
    Anti-clock wise boundary traversal
        - left boundary + leaf nodes + right boundary in reverse order
        - if left then put in queue, else if right put in queue, if leaf leave it
        - for leaf nodes we can't do level order, we want only the end leaf nodes 
                can use inorder traversal
        - if right then put in stack, else left put in stack, if leaf leave it.
*/  
bool BinaryTreeSeries::isLeaf(BinaryTree *node){
    if(node->left == nullptr && 
        node->right == nullptr)
        return true;
    return false;
}
void BinaryTreeSeries::addLeftBoundary(BinaryTree *root, vector<int>& res){
    BinaryTree* curr = root->left;
    while(curr){
        if(!isLeaf(curr))
            res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void BinaryTreeSeries::addRightBoundary(BinaryTree *root, vector<int>& res){
    BinaryTree* curr = root->right;
    stack<int> st; // to get reverse order
    while(curr){
        if(!isLeaf(curr))
            st.push(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    while(!st.empty()){
        //can use an array as well and reverse it here
        res.push_back(st.top());
        st.pop();
    }
}
void BinaryTreeSeries::addLeavesBoundary(BinaryTree *root, vector<int>& res){
    if(!root)
        return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeavesBoundary(root->left, res);
    if(root->right) addLeavesBoundary(root->right, res);
}
vector<int> BinaryTreeSeries::printBoundary(BinaryTree *root){
    vector<int> res;
    if(!root)
        return res;
    if(!isLeaf(root)){
        res.push_back(root->data);
        //return res;
    }
    //res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeavesBoundary(root,res);
    addRightBoundary(root,res);
    return res;
}


/* 21. Vertical order traversal */
vector<vector<int>> BinaryTreeSeries::verticalTraversal(TreeNode *root){
    map<int, map<int, multiset<int>>> nodes;
        // instead of multiset we can take a vector as well, then we need to sort at the end
        // map<int, map<int, vector<int>>> nodes;
        // sort(begin(q.second), end(q.second))
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p:nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

/* 22. Top view traversal 
*/
vector<int> BinaryTreeSeries::topViewTraversal(TreeNode *root){
    vector<int> ans;
    if(root == nullptr) 
        return ans;
    map<int,int> mpp;
    queue<pair<TreeNode *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end())
            mpp[line] = node->data;
        if(node->left)
            q.push({node->left, line-1});
        if(node->right)
            q.push({node->right, line+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

/* 23. Bottom view traversal 
*/
vector<int> BinaryTreeSeries::bottomViewTraversal(TreeNode *root){
    vector<int> ans;
    if(root == nullptr) 
        return ans;
    map<int,int> mpp;
    queue<pair<TreeNode *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left)
            q.push({node->left, line-1});
        if(node->right)
            q.push({node->right, line+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

/* 24. Right/Left view of Binary tree
    - iterative - avoid level order traversall - space more
    - recursive - RLR - latest take as Root -> Right -> Left
*/
void BinaryTreeSeries::tree_traversal(TreeNode *root, int level, vector<int>& res){
    if(root==nullptr) return;
    if(res.size()==level) res.push_back(root->data);
    tree_traversal(root->right,level+1,res);
    tree_traversal(root->left,level-1,res);
}
vector<int> BinaryTreeSeries::rightSideView(TreeNode *root){
    vector<int> res;
    tree_traversal(root, 0, res);
    return res;
}
void BinaryTreeSeries::tree_traversal1(TreeNode *root, int level, vector<int>& res){
    if(root==nullptr) return;
    if(res.size()==level) res.push_back(root->data);
    tree_traversal(root->left,level+1,res);
    tree_traversal(root->right,level-1,res);
}
vector<int> BinaryTreeSeries::leftSideView(TreeNode *root){
    vector<int> res;
    tree_traversal1(root, 0, res);
    return res;
}

/* 25. Check for symmetrical binary tree */
bool BinaryTreeSeries::checkSymmetrical(TreeNode *left, TreeNode *right){
    if(left == NULL || right == NULL)
        return left == right;
    if(left->data != right->data)
        return false;
    return checkSymmetrical(left->left, right->right) && 
        checkSymmetrical(left->right, right->left);
}

bool BinaryTreeSeries::isSymmetrical(TreeNode *root){
    if(root==nullptr)
        return true;
    return checkSymmetrical(root->left, root->right);
}

/* 26. Print node to root path 
    - the given node can be a pointer or a value
    - time O(n)  space - O(h)
*/
bool BinaryTreeSeries::getRootToNodePath(TreeNode *root, vector<int>& arr, int x){
    if(!root)
        return false;
    arr.push_back(root->data);
    /* got the value so return true */
    if(root->data==x)
        return true;

    /* if any of the path returns true then return true */
    if(getRootToNodePath(root->left,arr,x) || getRootToNodePath(root->right,arr,x))
        return true;

    /* node x is not present in left or right of this node so 
        pop back the value inserted and return false */    
    arr.pop_back();
    return false;    
}

vector<int> BinaryTreeSeries::rootToNodePath(TreeNode *root, int value){
    vector<int> arr;
    if(root==NULL)
        return arr;
    getRootToNodePath(root, arr, value);
    return arr;
}

/* 27. Lowest common ancestor in binary tree 
        - traverl from root to first node, travel from root to second node
        then check where both path differs that the lca
        - 
*/
TreeNode* BinaryTreeSeries::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else //both left and right are not null, found our result
        return root;
}

/* 28. Maximum width of a binary tree 
    Width is the maximum number of nodes in a level bewteen any two nodes.
    - if root is ith -> left node = 2*i+1 - right node = 2*i+2
    - in the last level we can find the difference of right and left node to get the result
    - since we need only the difference 

*/
int BinaryTreeSeries::widthOfBinaryTree(TreeNode* root){
    if(!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int len = q.size();
        // to make the id starting from 0
        int mmin = q.front().second;
        int first, last;
        for(int i=0; i<len; i++){
            int cur_id = q.front().second - mmin;
            TreeNode * curr = q.front().first;
            q.pop();
            if(i==0)    first = cur_id;
            if(i==len-1)    last = cur_id;
            if(curr->left)
                q.push({curr->left, cur_id*2+1});
            if(curr->right)
                q.push({curr->right, cur_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}

/* 28. Children sum property
    - each node should be sum of it's left and right child
    - while going down - make sure to take the root value down 
                       - while coming back to root - add the node values to get the root value
*/
void BinaryTreeSeries::childrenSumProperty(BinaryTree* root){
    if(root==nullptr) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }

    if(child >= root->data)
        root->data = child;
    else {
        if(root->left)
            root->left->data = root->data;
        else if(root->right)
            root->right->data = root->data;
    }

    childrenSumProperty(root->left);
    childrenSumProperty(root->right);
    
    int total=0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left or root->right) root->data = total;
}

/* 40. Search in a binary search tree */
TreeNode * BinaryTreeSeries::searchBST(TreeNode* root, int val){
    while(root!=NULL and root->data != val){
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

/* 41. Find ceil in a binary search tree */
/* find the minimum value which is greater than the input val
    that means from root go to right until you get the number 
    greater than the input then come to left until you get a 
    number less than the input then keep on going to right 
    to get the result. */

int BinaryTreeSeries::findCeilinBST(TreeNode* root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            break;
        }
        if(key > root->data){
            root = root->right;
        }else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

/* 42. Find Floor in a BST */
int BinaryTreeSeries::findFloorBST(TreeNode* root, int key){
    int floor=-1;
    while(root){
        if(root->data == key){
            floor = root->data;
            break;
        }
        if(root->data > key){
            root = root->left;
        }else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

/* 43. Insert a node in an bst */
/* Find where it can be and insert */
TreeNode * BinaryTreeSeries::insertIntoBST(TreeNode *bst, int val){
    if(bst == NULL)
        return new TreeNode(val);
    TreeNode *curr = bst;
    while(true){
        if(curr->data > val){
            if(curr->left == NULL){
                curr->left = new TreeNode(val);
                break;
            }else{
                curr = curr->left;
            }
        } else {
            if(curr->right == NULL){
                curr->right = new TreeNode(val);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    return bst;
}

/* 44. delete a node in BST */
/* it can be done in two ways
    1a.left of deleted node will point to root of the deleted node
    1b.right of delete node will be pointing to the last right of the left tree
    2a. right of deleted node will point to the root of the deleted node
    22b. left of deleted node will be pointing to the last left of the right tree
*/
TreeNode * BinaryTreeSeries::findlastRight(TreeNode *root){
    if(root->right==NULL)
        return root;
    return findlastRight(root->right);
}
TreeNode * BinaryTreeSeries::deleteHelper(TreeNode *root){
    if(root->left==NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findlastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode * BinaryTreeSeries::deleteNodeBST(TreeNode *root, int key){
    if(root==NULL)
        return root;
    if(root->data==key)
        return deleteHelper(root);
    TreeNode *dummy = root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left = deleteHelper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right!=NULL && root->right->data==key){
                root->right = deleteHelper(root->right);
                break;
            }else{
                root = root->right;
            }
        } 
    }
    return dummy;
}

/* 45. kth smallest element in bst */
/*  inorder of every bst is in sorted order (increasing)
    reverse of inorder of bst is in sorted order (decreasing)
*/
TreeNode* BinaryTreeSeries::kthSmallest(TreeNode* root, int &k){
    if(root==NULL)
        return NULL;

    TreeNode * left = kthSmallest(root->left, k);
    if(left)
        return left;
    k--;
    if(k == 0)
        return root;
    return kthSmallest(root->right, k);
}

TreeNode* BinaryTreeSeries::kthLargest(TreeNode* root, int &k){
    if(root == NULL)
        return NULL;
    
    TreeNode * right = kthLargest(root->right, k);
    if(right)
        return right;

    k--;
    if(k == 0)
        return root;

    return kthLargest(root->left, k);
}

/* 46. Validate BST */
bool BinaryTreeSeries::validateBST(TreeNode *root, TreeNode *low, TreeNode *high){
    if(root==NULL)
        return true;

    if(low!=NULL && root->data < low->data)
        return false;
    if(high!=NULL && root->data > high->data)
        return false;

    return (validateBST(root->left, NULL, root) && 
            validateBST(root->right, root, NULL));
}

/* 47. LCA of BST */
TreeNode* BinaryTreeSeries::lcaBST(TreeNode* root, int a, int b){
    if(root==NULL)
        return NULL;
    if(root->data > a && root->data > b)
        return lcaBST(root->left, a, b);
    if(root->data < a && root->data < b)
        return lcaBST(root->right, a, b);
    return root;
}

/* 48. bst from preorder */
/* bst nodes are always between a range - make use of upper bound here 
   left node will always smaller than the root node - otherwise return null 
   right node will be always be smaller than its smaller than the roots parent */
TreeNode* BinaryTreeSeries::bstBuild(vector<int>& arr, int& i, int bound){
    if( i == arr.size() || arr[i] > bound)
        return NULL;
    TreeNode* root = new TreeNode(arr[i++]);
    root->left = bstBuild(arr, i, root->data);
    root->right = bstBuild(arr, i, bound);
    return root;
}

TreeNode* BinaryTreeSeries::bstFromPreorder(vector<int>& arr){
    int i = 0;
    return bstBuild(arr, i, INT_MAX);
}

/* 49. Inorder successor/predecessor on bst */
/*
    - in order traversal - store in a list and find the next element
    - while traversing inorder, stop at the next greater element to given element 
    - logic - successor is always greater than the element   
    Note the inout val can be a node as well.   
*/
TreeNode* BinaryTreeSeries::inorderSuccessorBST(TreeNode *root, int val){
    TreeNode * successor = NULL;
    while( root != NULL ){
        if(root->data <= val){
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main(){

    BinaryTreeSeries ob;
    ob.root = ob.getNewBNode(1);
    ob.root->left = ob.getNewBNode(2);
    ob.root->right = ob.getNewBNode(3);
    ob.root->left->left = ob.getNewBNode(4);
    ob.root->left->right = ob.getNewBNode(5);
    ob.root->right->left = ob.getNewBNode(6);
    ob.root->right->right = ob.getNewBNode(7);
     
    /* 5. recurssive preorder traversal */
    cout<<"Recurssive pre-order traversal:\n";
    ob.recurssive_preorder(ob.root);
    cout<<endl;

    /* 6. recurssive inorder traversal */
    cout<<"Rrecurssive in-order traversal:\n";
    ob.recurssive_inorder(ob.root);
    cout<<endl;

    /* 7. recurssive postorder traversal */
    cout<<"Recurssive post-order traversal:\n";
    ob.recurssive_postorder(ob.root);
    cout<<endl;

   /* 8. level order traversal */
    cout<<"level order traversal:\n";
    ob.levelorder_traversal(ob.root);
    cout<<endl;

    /* 9. iterative preorder traversal */
    cout<<"Iterative pre-order traversal:\n";
    //https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45312/three-ways-of-iterative-preorder-traversing-easy-explanation
    ob.iterative_preorder(ob.root);
    cout<<endl;

    /* 10. iterative inorder traversal */
    cout<<"Iterative in-order traversal:\n";
    //https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31313/three-ways-of-iterative-inorder-traversing-easy-explanation
    ob.iterative_inorder(ob.root);
    cout<<endl;

    /* 11. iterative postorder traversal - using 2 stacks */
    cout<<"Iterative post-order traversal:\n";
    //https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/three-ways-of-iterative-postorder-traversing-easy-explanation
    ob.iterative_postorder2(ob.root);
    cout<<endl;

    /* 12. iterative postorder traversal - using 1 stacks */
    /* 13. pre-in-post order in one traversal */

    /* 14. Maximum depth of binary tree
           Maximum height of binary tree */
    cout<<"Maximum depth of binary tree:\n";
    cout<<ob.Height(ob.root)<<endl;

    /* 15. Check for balanced binary tree */
    cout<<"Is balanced "<<ob.isBalanced(ob.root)<<endl;

    /* 16. Diameter of binary tree */
    cout<<"Diameter "<<ob.diameter(ob.root)<<endl;

    /* 17. Max path sum */
    cout<<"Maximum Path sum "<<ob.maxPathSum(ob.root)<<endl;

    /* 18. Check if two trees are identical */
    cout<<"Is Same Tree "<<ob.isSameTree(ob.root, ob.root)<<endl;

    /* 19. zigzag traversal */
    vector<vector<int>> res19;
    res19 = ob.zigzag_traversal(ob.root);
    for(int i=0; i<res19.size(); i++){
        for(int j=0; j<res19[i].size(); j++){
            cout<<res19[i][j]<<" ";
        }
        cout<<endl;
    }   
    cout<<endl;

    /* 20. Boundary traversal */
    vector<int> res20;
    res20 = ob.printBoundary(ob.root);
    for(auto value: res20){
        cout<<value<<" ";
    }
    cout<<endl;

    /* 21. Vertical order traversal */
    vector<vector<int>> res21;
    res21 = ob.verticalTraversal(ob.root);
    cout<<"Vertical traversal:";
    for(int i=0; i<res21.size(); i++){
        for(int j=0; j<res21[i].size(); j++){
            cout<<res21[i][j]<<" ";
        }
        cout<<"--";
    }
    cout<<endl;

    /* 22. Top view of a binary tree */
    vector<int> res22;
    res22 = ob.topViewTraversal(ob.root);
    cout<<"Top view of the binary tree: ";
    for(int i=0; i<res22.size(); i++){
        cout<<res22[i]<<" ";
    }
    cout<<endl;

    /* 23. Bottom view of a binary tree */
    vector<int> res23;
    res23 = ob.bottomViewTraversal(ob.root);
    cout<<"Bottom view of the binary tree: ";
    for(int i=0; i<res23.size(); i++){
        cout<<res23[i]<<" ";
    }
    cout<<endl;

    /* 24. Right/left view of a binary tree */
    vector<int> res24;
    res24 = ob.rightSideView(ob.root);
    cout<<"Right view of the binary tree: ";
    for(int i=0; i<res24.size(); i++){
        cout<<res24[i]<<" ";
    }
    cout<<endl;
    res24 = ob.leftSideView(ob.root);
    cout<<"Left view of the binary tree: ";
    for(int i=0; i<res24.size(); i++){
        cout<<res24[i]<<" ";
    }
    cout<<endl;

    /* 25. check symmetrical */
    cout<<"check symmetrical tree "<< ob.isSymmetrical(ob.root)<<endl;

    /* 26. Root to node path */
    cout<<"Root to node path: ";
    vector<int> res26 = ob.rootToNodePath(ob.root,5);
    for(int i=0; i<res26.size(); i++){
        cout<<res26[i]<<" ";
    }
    cout<<endl;

    /* 27. LCA */
    TreeNode *p = ob.root->left->left; //= ob.getNewBNode(4);
    TreeNode *q = ob.root->right->left; // = ob.getNewBNode(6);
    TreeNode* res27 = ob.lowestCommonAncestor(ob.root, p, q);
    cout<<"LCA "<<res27->data<<endl;

    /* 28. Width of BT */
    cout<<"Width of binary tree: "<<ob.widthOfBinaryTree(ob.root)<<endl;

    /* 29. Children sum property */
    ob.childrenSumProperty(ob.root); 
    ob.iterative_preorder(ob.root);
    cout<<endl;

    /* 40. Binary search tree */
    TreeNode *bstroot = new TreeNode(12);
    bstroot->left = new TreeNode(8);
    bstroot->right = new TreeNode(15);
    bstroot->left->left = new TreeNode(5);
    bstroot->left->right = new TreeNode(10);

    TreeNode * bs40 =  ob.searchBST(bstroot, 5);
    cout<<"Binary Tree Search result:"<<bs40->data<<endl;

    /* 41. Ceil in Binary search tree */
    int ceil = ob.findCeilinBST(bstroot, 5);
    cout<<"Ceil of the value in BST:"<<ceil<<endl;

    /* 42. Floor in Binary search tree */
    int floor = ob.findFloorBST(bstroot, 9);
    cout<<"Floor of the value in BST:"<<floor<<endl;

    /* 43. insert in bst */
    TreeNode * bst43 = ob.insertIntoBST(bstroot, 13);
    cout<<endl;
    ob.levelorder_traversal(bst43);

    /* 44. delete a node in bst */
    TreeNode * bst44 = ob.deleteNodeBST(bstroot, 13);
    cout<<endl;
    ob.levelorder_traversal(bst44);

    /* 45. kth smallest and largest in bst */
    int k = 3;
    TreeNode* bst45 = ob.kthLargest(bstroot, k);
    cout<<endl<<"Find 3rd Largest "<<bst45->data;
    k = 3;
    bst45 = ob.kthSmallest(bstroot, k);
    cout<<endl<<"Find 3rd smallest "<<bst45->data<<endl;

    /* 46. Validate BST */
    cout<<"isBST "<<ob.validateBST(bstroot, NULL, NULL)<<endl;

    /* 47. LCA of bst */
    TreeNode* bst47 = ob.lcaBST(bstroot, 8,15);
    cout<<"lca of 8 and 15 is "<<bst47->data<<endl;

    /* 48. bst from preOrder */
    vector<int> arr48({8,5,1,7,10,12});
    TreeNode* bst48r = ob.bstFromPreorder(arr48);
    cout<<"New BST from preorder:";
    ob.recurssive_inorder(bst48r);
    cout<<endl;

    /* 49. inorder successor */
    TreeNode* bst49 = ob.inorderSuccessorBST(bst48r, 1);
    cout<<"Inorder successor of 1 is "<<bst49->data<<endl;

    return 0;
}