//2019g 平方拆分
#include <iostream>   //vxgzh:xtsn  
using namespace std;
//先求出所有的平方数，然后使用dfs遍历即可
#include <vector>
vector <int> v;
int n,c; 

void dfs(int x,int sum)   //dfs遍历即可 
{
    if(sum>2019)    return ;
    if(sum==2019)
    {
        c++;return ;
    }    
    if(x+1<n)
    {
        dfs(x+1,sum+v[x+1]);
        dfs(x+1,sum);
    }
        
}

int main()
{
  int i;
  for(i=1;i*i<=2019;i++)
  {
      v.push_back(i*i);   //找出平方数 
  }
  
  n=v.size();
  dfs(-1,0);
  cout<<c<<endl; 
  
  
  return 0;
}