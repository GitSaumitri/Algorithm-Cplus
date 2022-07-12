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
    /* 14. Maximum depth of binary tree */
    /* 15. Check for balanced binary tree */

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

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

    return 0;
}