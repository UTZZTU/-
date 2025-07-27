#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
double a[1010][1010];
int main ()
{
    set<int> nan,nv;
    vector<int> n1,n2;
    int n,m,k,i,j,nnzj,nvzj,pd=0;
    double mx;
    cin>>n>>m;
    while(m--)
    {
        int e[1010];
        double t;
        cin>>k;
        t=1.0/k;
        for(i=1;i<=k;i++)
        {
            cin>>e[i];
            if(e[i]>=0)
                nan.insert(e[i]);
            else
                nv.insert(-e[i]);
                
        }
        for(i=1;i<=k-1;i++)
        {
            for(j=i+1;j<=k;j++)
            {
                a[abs(e[i])][abs(e[j])]+=t;
                a[abs(e[j])][abs(e[i])]+=t;
            }
        }
    }
    cin>>nnzj>>nvzj;
    if(nnzj<0||nvzj>0)
    {
    	pd=1;
        k=nnzj;
        nnzj=nvzj;
        nvzj=k;
    }
    nvzj*=-1;
    mx=0;
    for(auto it=nv.begin();it!=nv.end();it++)
    {
        int o=*it;
        if(a[nnzj][o]>mx)
        {
            mx=a[nnzj][o];
        }
    }
    for(auto it=nv.begin();it!=nv.end();it++)
    {
        int o=*it;
        if(a[nnzj][o]==mx)
        {
           n1.push_back(o);
        }
    }
    mx=0;
    for(auto it=nan.begin();it!=nan.end();it++)
    {
        int o=*it;
        if(a[o][nvzj]>mx)
            mx=a[o][nvzj];
    }
    for(auto it=nan.begin();it!=nan.end();it++)
    {
        int o=*it;
        if(a[o][nvzj]==mx)
        {
           n2.push_back(o);
        }
    }
    vector<int>::iterator it1=find(n1.begin(),n1.end(),nvzj);
    vector<int>::iterator it2=find(n2.begin(),n2.end(),nnzj);
    if(it1!=n1.end()&&it2!=n2.end())
    {
    	if(pd==1)
        printf("-%d %d",nvzj,nnzj);
        else
        printf("%d -%d",nnzj,nvzj);
        return 0;
    }
    else
    {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        nvzj*=-1;
        if(pd==1)
        {
        	for(auto it=n2.begin();it!=n2.end();it++)
        {
            cout<<nvzj<<" "<<*it<<endl;
        }
        for(auto it=n1.begin();it!=n1.end();it++)
        {
            int o=*it;
            o*=-1;
            cout<<nnzj<<" "<<o<<endl;
        }
		}
        else
        {
        	for(auto it=n1.begin();it!=n1.end();it++)
        {
            int o=*it;
            o*=-1;
            cout<<nnzj<<" "<<o<<endl;
        }
        for(auto it=n2.begin();it!=n2.end();it++)
        {
            cout<<nvzj<<" "<<*it<<endl;
        }
		}
    }
    return 0;
}