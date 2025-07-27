#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int a[1510][1510];
struct lx
{
    int xh;
    int hf;
}e[1510];
bool cmp(lx x,lx y)
{
	if(x.hf!=y.hf)
	return x.hf<y.hf;
	else
	return x.xh<y.xh;
}
int main ()
{
    int n,m,i,j,t,s,ks=1,k;
    cin>>n>>m;
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if(a[x][y]!=0)
        {
            a[x][y]=min(a[x][y],w);
            a[y][x]=a[x][y];
        }
        else
            a[x][y]=a[y][x]=w;
    }
    cin>>k;
    int pd=0,sum,l[1510];
    for(i=1;i<=k;i++)
    {
        pd=0;
        sum=0;
        vector<int> p;
        set<int> r;
        cin>>t;
        for(j=1;j<=t;j++)
        {
            cin>>l[j];
            p.push_back(l[j]);
            r.insert(l[j]);
        }
        if(r.size()!=n||p.size()!=n)
        pd=1;
        if(a[0][l[1]]==0)
        {
            pd=1;
        }
         else
         {
             sum+=a[0][l[1]];
         }
         if(t>=1)
         {
         	j=1;
        while(a[l[j]][l[j+1]]!=0&&j<t)
        {
            sum+=a[l[j]][l[j+1]];
            j++;
        }
        if(j!=t)
        {
            pd=1;
        }
        else
        {
            if(a[l[j]][0]==0)
                pd=1;
            else
            {
                sum+=a[l[j]][0];
            }
        }
		 }
        else if(t==1)
        {
        	if(a[l[1]][0]==0)
                pd=1;
            else
            {
                sum+=a[l[1]][0];
            }
		}
        if(pd==0)
        {
            e[ks].hf=sum;
            e[ks].xh=i;
			ks++;
        }
    }
    sort(e+1,e+ks,cmp);
    printf("%d\n",ks-1);
    printf("%d %d",e[1].xh,e[1].hf);
    return 0;
}