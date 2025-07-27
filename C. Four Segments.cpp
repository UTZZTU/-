#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
const double pi=3.1415926;
class node
{
public:
  int x,y,xx,yy;
  int z;
}s[77];
int num[44];
map<int,int>mp;
int main()
{
  int a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {   memset(num,0,sizeof(num));
     bool ans=0;
     for(int i=0;i<4;i++)
     {  if(a==c&&b==d)ans=1;
       s[i].x=a;s[i].y=b;s[i].xx=c;s[i].yy=d;///交换点生成一遍好判断
       s[i+4].x=c;s[i+4].y=d;s[i+4].xx=a;s[i+4].yy=b;
       if(i!=3)cin>>a>>b>>c>>d;
     }
     bool flag=1;
     for(int i=0;i<4;i++)
     for(int j=0;j<8;j++)
     { if(i==j)continue;
 
       if(s[i].x==s[j].x&&s[i].y==s[j].y)
        num[i]++;///判断是个四边形，那有且仅有两个点一样
        if(s[i].y==s[i].yy)flag=0;///判断有条边是x轴平行就行了
     }
     if(flag)ans=1;
     for(int i=0;i<4;i++)
      if(num[i]!=1)ans=1;
     for(int i=0;i<4;i++)
     for(int j=0;j<8;j++)
     { if(i==j)continue;
        double x,y,xx,yy,z,zz;
       if(s[i].x==s[j].x&&s[i].y==s[j].y)///判断角都是90度
        {///向量知识，(x,y)*(xx,yy)=(长度乘积)cos degree;
          x=s[i].x-s[i].xx;
          y=s[i].y-s[i].yy;
          xx=s[i].x-s[j].xx;
          yy=s[i].y-s[j].yy;
          z=x*xx+y*yy;
          zz=sqrt(x*x+y*y)*sqrt(xx*xx+yy*yy);
          z=z/zz;
          z=acos(z)/pi*180;
         /// cout<<z<<endl;
 
          if(abs(z-90.0)>0.0001)ans=1;
        }
     }
     if(ans)cout<<"NO\n";
     else cout<<"YES\n";
  }
}