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

    /* recurssive preorder traversal */
    void recurssive_preorder(BinaryTree *root);

    /* recurssive postorder traversal */
    void recurssive_postorder(BinaryTree *root);

    /* recurssive preorder traversal */
    void recurssive_inorder(BinaryTree *root);

    /* iterative preorder traversal */
    void iterative_preorder(BinaryTree *root);

    /* iterative postorder traversal */
    void iterative_postorder(BinaryTree *root);

    /* iterative preorder traversal */
    void iterative_inorder(BinaryTree *root);

    /* iterative preorder traversal */
    void levelorder_traversal(BinaryTree *root);

};

/* recurssive preorder traversal */
void BinaryTreeSeries::recurssive_preorder(BinaryTree *root){
    if(root==nullptr){
        //cout<<"No elements in the Tree\n";
        return;
    }
    cout<<root->data<<" ";
    recurssive_preorder(root->left);
    recurssive_preorder(root->right);
}

/* recurssive post order traversal */
void BinaryTreeSeries::recurssive_postorder(BinaryTree *root){
    if(root){
        recurssive_postorder(root->left);
        recurssive_postorder(root->right);
        cout<<root->data<<" ";
    }
}

/* recurssive inorder traversal */
void BinaryTreeSeries::recurssive_inorder(BinaryTree *root){
    if(root){
        recurssive_inorder(root->left);
        cout<<root->data<<" ";
        recurssive_inorder(root->right);
    }
}   

/* iterative preorder traversal - DLR */
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

/* iterative post order traversal - LRD*/
void BinaryTreeSeries::iterative_postorder(BinaryTree *root){
    if(root){
        iterative_postorder(root->left);
        iterative_postorder(root->right);
        cout<<root->data<<" ";
    }
}

/* iterative inorder traversal - LDR*/
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

/* recurssive inorder traversal */
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



int main(){

    BinaryTreeSeries ob;
    ob.root = ob.getNewBNode(1);
    ob.root->left = ob.getNewBNode(2);
    ob.root->right = ob.getNewBNode(3);
    ob.root->left->left = ob.getNewBNode(4);
    ob.root->left->right = ob.getNewBNode(5);
    ob.root->right->left = ob.getNewBNode(6);
    ob.root->right->right = ob.getNewBNode(7);
      
    cout<<"Recurssive pre-order traversal:\n";
    ob.recurssive_preorder(ob.root);
    cout<<endl;

    cout<<"Recurssive post-order traversal:\n";
    ob.recurssive_postorder(ob.root);
    cout<<endl;

    cout<<"Rrecurssive in-order traversal:\n";
    ob.recurssive_inorder(ob.root);
    cout<<endl;

    cout<<"Iterative pre-order traversal:\n";
    ob.iterative_preorder(ob.root);
    cout<<endl;

    cout<<"Iterative post-order traversal:\n";
    ob.iterative_postorder(ob.root);
    cout<<endl;

    cout<<"Iterative in-order traversal:\n";
    ob.iterative_inorder(ob.root);
    cout<<endl;

    cout<<"level order traversal:\n";
    ob.levelorder_traversal(ob.root);
    cout<<endl;

    return 0;
}