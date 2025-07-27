#include <bits/stdc++.h>
using namespace std;
struct node
{
	int ti,wi;
};
vector<node> vec;
int n,v,t,w,s,f[20010];
int main ()
{
   scanf("%d %d",&n,&v);
   for(int i=1;i<=n;i++)
   {
   	scanf("%d %d %d",&t,&w,&s);
   	for(int j=1;j<=s;j*=2)
   	{
   		vec.push_back((node){t*j,w*j});
   		s-=j;
	   }
	   if(s)
	   {
	   	vec.push_back((node){t*s,w*s});
	   }
   }
   for(auto it=vec.begin();it!=vec.end();it++)
   {
   	for(int i=v;i>=it->ti;i--)
   	{
   		f[i]=max(f[i],f[i-it->ti]+it->wi);
	   }
   }
   cout<<f[v];
   return 0;
}