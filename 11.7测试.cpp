#include<iostream>
using namespace std;
#include<queue>
template<class T>
struct TreeNode
{
     T data;
     TreeNode<T>*  left;
     TreeNode<T>*  right;
     TreeNode(const T& x)
         :data(x)
         ,left(NULL)
         ,right(NULL)
     {}
};



template<class T>
bool  IsComplete(TreeNode<T>* root)
{
    //1.��Ϊ�գ����ش���
   if (root==NULL)
   {
       return false;
   }
   //2.����Ϊ��
   queue<TreeNode<T>*>  q;
   q.push(root);
   while (!q.empty())
   {
       TreeNode<T>* top=q.front();
       //2.1����ýڵ��������Ӷ��У���ֱ��pop
       if (top->left&&top->right)
       {
           q.pop();
           q.push(top->left);
           q.push(top->right);
       }
       //2.2����ýڵ�����Ϊ�գ��Һ��Ӳ�Ϊ�գ���һ��������ȫ������
       if (top->left==NULL&&top->right)
       {
           return false;
       }
       //2.3����ýڵ����Ӳ�Ϊ�գ��Һ���Ϊ�ջ��߸ýڵ�ΪҶ�ӽڵ㣬��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
       if ((top->left&&top->right==NULL)||(top->left==NULL&&top->right==NULL))
       {
           q.pop();
           //��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
           while (!q.empty())
           {
               top=q.front();
               if (top->left==NULL&&top->right==NULL)
               {
                   q.pop();
               }
               else
               {
                   return false;
               }
           }
           return true;
       }
   }
   return true;  
}



//��������
void test1()
{
    //       1
    //   2       3
    // 4    5  6   7
     TreeNode<char>* node1=new TreeNode<char>('A'); 
     TreeNode<char>* node2=new TreeNode<char>('B'); 
     TreeNode<char>* node3=new TreeNode<char>('C'); 
     TreeNode<char>* node4=new TreeNode<char>('D'); 
     node1->left=node2;
     node1->right=node3;
     node2->left=node4;
     cout<<IsComplete<char>(node1)<<endl;
}

//������Ϊ��
void test2()
{
    cout<<IsComplete<int>(NULL)<<endl;
}
//3.��������Ϊ�գ�Ҳ������������������һ���������Ϊ�գ��Һ��Ӳ�Ϊ��
void test3()
{
    //       1
    //   2       3
    // 4    5      7
    TreeNode<int>* node1=new TreeNode<int>(1); 
    TreeNode<int>* node2=new TreeNode<int>(2); 
    TreeNode<int>* node3=new TreeNode<int>(3); 
    TreeNode<int>* node4=new TreeNode<int>(4); 
    TreeNode<int>* node5=new TreeNode<int>(5); 
    TreeNode<int>* node7=new TreeNode<int>(7); 
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->right=node7;
    cout<<IsComplete<int>(node1)<<endl;
}

//4.��������Ϊ�գ�Ҳ������������������Ҷ�ӽڵ�,���Ҷ�ӽڵ�֮������н�㶼ΪҶ�ӽڵ�
void test4()
{
    //        1
    //    2       3
    // 4    5      
    TreeNode<int>* node1=new TreeNode<int>(1); 
    TreeNode<int>* node2=new TreeNode<int>(2); 
    TreeNode<int>* node3=new TreeNode<int>(3); 
    TreeNode<int>* node4=new TreeNode<int>(4); 
    TreeNode<int>* node5=new TreeNode<int>(5); 
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    cout<<IsComplete<int>(node1)<<endl;
}
//4.��������Ϊ�գ�Ҳ���������������������Ӳ�Ϊ�գ��Һ���Ϊ�յĽ�㣬��ýڵ�֮������н�㶼ΪҶ�ӽڵ�
void test5()
{
    //        1
    //    2       3
    // 4    5   6 
    TreeNode<int>* node1=new TreeNode<int>(1); 
    TreeNode<int>* node2=new TreeNode<int>(2); 
    TreeNode<int>* node3=new TreeNode<int>(3); 
    TreeNode<int>* node4=new TreeNode<int>(4); 
    TreeNode<int>* node5=new TreeNode<int>(5); 
    TreeNode<int>* node6=new TreeNode<int>(6); 
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    cout<<IsComplete<int>(node1)<<endl;
}
int main()
{
    test1();
    /*test2();*/
    /*test3();*/
    /*test4();*/
    /*test5();*/
    return 0;
}

