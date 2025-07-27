#include<bits/stdc++.h>
using namespace std;
char b[110];
int t,n,m,x;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        fill(b+1,b+m+1,'B');//填充函数
       while(n--)
      {
         cin>>x;
         if(x<m+1-x)
         {
            if(b[x]!='A')//如果这个位置已经有了，那就只能选择另一个了
                b[x]='A';
            else b[m+1-x]='A';
         }
         else
         {
             if(b[m+1-x]!='A')
                b[m+1-x]='A';
             else b[x]='A';
         }
 
      }
      for(int i=1;i<=m;i++)cout<<b[i];
      cout<<endl;
    }
}