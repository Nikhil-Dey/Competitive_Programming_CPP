#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
    
    vector<TreeNode*> helper(int start , int end)
    {
        vector<TreeNode*> trees;

        if(start > end)
        {
            trees.push_back(NULL);
            return trees;
        }

        if(start == end)
        {
            TreeNode* newNode = new TreeNode(start);
            trees.push_back(newNode);
            return trees;
        }

        for(int i = start ; i<=end; i++)
        {
            vector<TreeNode*> leftTree = helper(start, i-1);
            vector<TreeNode*> rightTree = helper(i+1, end);
            for(int j = 0; j<leftTree.size(); j++)
            {
                for(int k = 0; k<rightTree.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        //vector<TreeNode*> trees;
        return helper(1,n);
    }
};

void printTree(TreeNode* root)
{
    if(root == NULL)
        cout<<"null"<<",";
    else
        cout<<root->val<<",";
    if(root -> left != NULL)
    {
        printTree(root->left);
    }
    if(root->right !=  NULL)
    {
        printTree(root->right);
    }
}


int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<TreeNode*> root = s.generateTrees(n);
    for(int i = 0; i<root.size(); i++)
    {
        printTree(root[i]);
        cout<<endl;
    }
}