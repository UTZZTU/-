#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n1,n2;
struct point
{
    int xh;
    int num;
}s1[1000010],s2[1000010];
bool cmp1(point x,point y)
{
    if(x.num!=y.num)
    return x.num>y.num;
    else
    return x.xh<y.xh;
}
bool cmp2(point x,point y)
{
    if(x.num!=y.num)
    return x.num<y.num;
    else
    return x.xh<y.xh;
}
int main()
{
cin>>n1>>n2;
for(int i=1;i<=n1;i++)
{
    s1[i].xh=i;
    cin>>s1[i].num;
}
for(int i=1;i<=n2;i++)
{
    s2[i].xh=i;
    cin>>s2[i].num;
}
string u;
cin>>u;
sort(s1+1,s1+n1+1,cmp2);
sort(s2+1,s2+1+n2,cmp1);
int u1=1,u2=1;
for(int i=0;i<u.size();i++)
{
    if(u[i]=='0')
    {
        cout<<"A"<<s1[u1].xh<<endl;
        u1++;
    }
    else
    {
        cout<<"B"<<s2[u2].xh<<endl;
        u2++;
    }
}
cout<<"E";
  return 0;
}