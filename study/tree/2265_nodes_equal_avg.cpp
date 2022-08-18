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
#include <utility>
#include <math.h> 
class Solution {
public:
    //essa funcao conta quantos nós tem na arvore e soma os valores das chaves
    std::pair<int, float> count_avg(TreeNode* root){
        std::pair<int,float> aux=std::make_pair(0,0);;
        
        if(root==NULL) 
            return std::make_pair(0,0);
        
        if(root->left==NULL && root->right==NULL)
            return std::make_pair(1,root->val);
        
        if(root->left!=NULL)
            aux = count_avg(root->left);
        
        if(root->right!=NULL){
            std::pair<int,float> aux_1 = count_avg(root->right);
            aux.first+=aux_1.first;
            aux.second+=aux_1.second;
        }
            
        
        aux.first+=1;
        aux.second+=root->val;
        
        return aux;
            
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL) 
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        float sum=root->val;
        int cont=1;
        
        if(root->left!=NULL){
            std::pair<int,float> aux_avg=count_avg(root->left);
            cont+=aux_avg.first;
            sum+=aux_avg.second;
        }
        if(root->right!=NULL){
            std::pair<int,float> aux_avg = count_avg(root->right);
            cont+=aux_avg.first;
            sum+=aux_avg.second;
        }
        //std::printf("%d %d %f\n",root->val,cont,sum);
            
        
        float avg = std::floor(sum/cont);
        return (avg==root->val?1:0)+averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
    
    
};