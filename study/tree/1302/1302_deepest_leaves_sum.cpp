#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;

        TreeNode *currentNode;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int sum = 0;

        while(!nodes.empty()){
            sum = 0;
            int tam = nodes.size();

            for(int i = 0; i < tam; i++){
                currentNode = nodes.front();
                nodes.pop();
                if(currentNode->left) nodes.push(currentNode->left);
                if(currentNode->right) nodes.push(currentNode->right);
                sum += currentNode->val;
            }
        }
        return sum;
    }
};