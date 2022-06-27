#include<iostream>
using namespace std;

class BinaryTreeSeries{
    private:
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

    public:
    BinaryTree *root=nullptr;

    BinaryTree * getNewBNode(int val){
        BinaryTree *n = new BinaryTree(val);
        return n;
    }

    /* recurssive preorder traversal */
    void recurssive_preorder(BinaryTree *root){
        if(root==nullptr){
            //cout<<"No elements in the Tree\n";
            return;
        }
        cout<<root->data<<" ";
        recurssive_preorder(root->left);
        recurssive_preorder(root->right);
    }

    /* recurssive post order traversal */
    void recurssive_postorder(BinaryTree *root){
        if(root){
            recurssive_postorder(root->left);
            recurssive_postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    /* recurssive inorder traversal */
    void recurssive_inorder(BinaryTree *root){
        if(root){
            recurssive_inorder(root->left);
            cout<<root->data<<" ";
            recurssive_inorder(root->right);
        }
    }    
};


int main(){

    BinaryTreeSeries ob;
    ob.root = ob.getNewBNode(5);
    ob.root->left = ob.getNewBNode(10);
    ob.root->right = ob.getNewBNode(12);

    cout<<"Recurssive pre-order traversal:\n";
    ob.recurssive_preorder(ob.root);
    cout<<endl;

    cout<<"Recurssive post-order traversal:\n";
    ob.recurssive_postorder(ob.root);
    cout<<endl;

    cout<<"Rrecurssive in-order traversal:\n";
    ob.recurssive_inorder(ob.root);
    cout<<endl;

    return 0;
}