#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *left , *right;
    int key;
};


//function to create a new tree
Node* newNode(int key)
{
    Node* temp = new Node;
    temp -> key = key;
    temp -> left = temp -> right = NULL;
    return temp;
}

//return level of key if it is present in tree otherwise return -1
int findLevel(Node* root, int k, int level){
    if(root == NULL)
    {
        return -1;
    }

    if(root -> key == k)
    {
        return level;
    }

    int l = findLevel(root -> left , k, level + 1);
    return (l != -1) ? l: findLevel(root -> right, k, level + 1);
}

//to find the first common ancestor of both nodes
Node* findDistUtil(Node* root, int n1, int n2, int& d1, int& d2, int &dist, int lvl)
{
    if(root == NULL)
        return NULL;
    

    if(root -> key == n1)
    {
        d1 = lvl;
        return root;
    }

    if(root-> key == n2){
        d2 = lvl;
        return root;
    }

    Node* left_lca = findDistUtil(root->left, n1, n2, d1,d2,dist,lvl+1);
    Node* right_lca = findDistUtil(root->right, n1, n2, d1,d2, dist, lvl+1);

    if(left_lca && right_lca)
    {
        dist = d1 + d2 - 2*lvl;
        return root;
    }

    return (left_lca != NULL)?left_lca : right_lca;

}


//main function that returns dist btw n1 and n2
int findDistance(Node* root, int n1, int n2)
{
    int d1 = -1, d2 = -1, dist;
    Node* lca = findDistUtil(root, n1, n2, d1, d2, dist ,1);

    //if they have common ancestors
    if(d1 != -1 && d2 != -1)
        return dist;


    //if n1 is the ancestor of n2
    //lca here is the pointer to the n1 node
    if(d1 != -1)
    {
        dist = findLevel(lca,n2,0);
        return dist;
    }


    //if n2 is the ancestor of n1
    //lca here is the pointer to the n2 node
    if(d2 != -1)
    {
        dist = findLevel(lca,n1,0);
        return dist;
    }

    return -1;
}


int main()
{
    // Let us create binary tree given in the
    // above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5)<<endl;
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6)<<endl;
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4)<<endl;
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4)<<endl;
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5)<<endl;
    return 0;
}