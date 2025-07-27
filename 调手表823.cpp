#include <bits/stdc++.h>
using namespace std;
int ans=0,n,k,t,book[100001];
typedef struct
{ int num;//当前状态里的时间 
  int step; //走到这个状态所需要的步数 
}Status;//定义状态结构体 
queue<Status> q;
int main() 
{ 
      cin>>n>>k;
      Status start,f,now1;//起始    首元素    当前状态 
      start.step=0;
      start.num=0;
      book[0]=1;
      q.push(start);//先插入当前状态 
      while(!q.empty())
      {
          f=q.front();//取出首元素
          q.pop();
          t=(f.num+1)%n;//按+1键后的时间 
          if(!book[t])//如果这个时间没有走过 
          { book[t]=1;//标记走过 
          now1.num=t;
            now1.step=f.step+1;
            ans=max(ans,now1.step); //更新答案 
            q.push(now1);//把当前状态插入 
          }
          t=(f.num+k)%n;//按+k键后的时间 
          if(!book[t])//如果这个时间没有走过
          { book[t]=1;//标记走过 
          now1.num=t;
            now1.step=f.step+1;
            ans=max(ans,now1.step);
            q.push(now1);//把当前状态插入
          }
          
      }
      cout<<ans;
    return 0;
    
}