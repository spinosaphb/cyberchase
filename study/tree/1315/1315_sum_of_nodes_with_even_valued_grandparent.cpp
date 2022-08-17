
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    int getChildSum(TreeNode* node){
        if (!node) return 0;
        TreeNode* childs[] = {node->left, node->right};
        int sum = 0;
        for (auto child : childs)
            sum += (child) ? child->val : 0;
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if (!root)
           return 0;
        if(root->val % 2 != 0)
            return sumEvenGrandparent(root->left) +
                   sumEvenGrandparent(root->right);
        int sum = 0;
        sum += this->getChildSum(root->left);
        sum += this->getChildSum(root->right);
        return sum + sumEvenGrandparent(root->left) 
            + sumEvenGrandparent(root->right); 
    }
};