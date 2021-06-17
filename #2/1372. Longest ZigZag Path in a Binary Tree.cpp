/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
  

int maxAns=0;
unordered_map<string,int> umap;

int findLongest(TreeNode *root,int direction){
    ostringstream get_add;
        get_add << root;
        string key =get_add.str();
        key+=char(direction);
    if(umap.find(key)!=umap.end()){
        return umap[key];
    }
    if(direction){
        if(!root->left)
            return 1;
        int dpValue= 1+findLongest(root->left,0);
        pair<TreeNode*,int> dpKey(root->left,0);
        umap[key]=1+dpValue;
        return dpValue;
        
    }else{
        if(!root->right)
            return 1;
        int dpValue= 1+findLongest(root->right,1);
        pair<TreeNode*,int> dpKey(root->right,1);
        umap[key]=dpValue;
        return dpValue;
    }
}

void traverseTree(TreeNode* root){
    int leftzigzag=0;
    int rightzigzag=0;
    if(!root)
        return;
    if(root->left){
       leftzigzag= findLongest(root->left,0);
    }

    if(root->right){
       rightzigzag=findLongest(root->right,1);
    }
    maxAns= max(leftzigzag,maxAns);
    maxAns=max(rightzigzag,maxAns);
    traverseTree(root->left);
    traverseTree(root->right);
    return;
    
}

int longestZigZag(TreeNode* root) {
    traverseTree(root);
    return maxAns;
}


    
};