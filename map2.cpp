#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<limits.h>
#include<set>
using namespace std;
struct node{
    int v,p;
    bool operator<(const node &a)const//p大的优先
    {   return p>a.p;    }
};
int main()
{
    int u;
    set<node>q;
    node temp;
    while(~scanf("%d",&u))
    {
        if(u==0)
            break;
        if(u==1)
        {
            scanf("%d%d",&temp.v,&temp.p);
            q.insert(temp);
        }
        else if(q.empty())
            puts("0");
        else if(u==2)
        {
            printf("%d\n",q.begin()->v);
            q.erase(q.begin());
        }
        else
        {
            set<node>::iterator it=q.end();
            it--;
            printf("%d\n",it->v);
            q.erase(it);
        }
    }
    return 0;
}