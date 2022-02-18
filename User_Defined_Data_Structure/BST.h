#include"BinaryTree.h"

class BST{
    BinaryTree* root;
    int size;
    void insertNode(BinaryTree* root, int data){
        if(root == nullptr){
            BinaryTree* newNode = new BinaryTree(data);
            size++;
            root = newNode;
            return;
        }

        if(root -> val >= data){
            insertNode(root -> left, data);
        }else{
            insertNode(root -> right, data);
        }
    }

    void deleteNode()

    public:
    BST(){
        root = nullptr;
        size = 0;
    }

    void insertNode(int data){
        insertNode(root, data);
    }

    void deleteNode(int data){
        deleteNode(root, data);
    }

};