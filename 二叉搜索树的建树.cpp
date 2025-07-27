#include <iostream>
#include <cstdio>
using namespace std;
 
 
//定义树的节点
struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):value(v),left(NULL),right(NULL){}
};
 
 
//递归函数，向二叉搜索树中插入节点
TreeNode* Insert(TreeNode* root,int value){
    if(root==NULL){                               //如果待插入的二叉树是空树
        root = new TreeNode(value);               //创建节点并成为该二叉搜索树的头结点
    }else if(value<root->value){
        root->left = Insert(root->left, value);   //向左子树中插入
    }else if(value>root->value){
        root->right = Insert(root->right, value); //向右子树中插入
    }
    return root;                                  
}
 
 
int main(){
    int n;                                        //读取待插入序列个数
    while(scanf("%d",&n)!=EOF){            
        TreeNode* root = NULL;                     //定义一个空的二叉搜索树
        int x;    
        for(int i = 0;i<n;i++){                    //将n个数字依次插入二叉搜索树
            scanf("%d",&x);
            root = Insert(root, x);
        }
    }
    return 0;
}