#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
int n,hp,op,x,h,res,pos;
int tr[N][2],cnt[N],idx;
void fj(int x)
{
	pos=0;
	while(x)
	{
		pos++;
		x>>=1;
	}
}
void insert(int x,int v)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(!tr[p][u]) tr[p][u]=++idx;
        p=tr[p][u];
        cnt[p]+=v;
//        cout<<cnt[p]<<endl;
    }
}

int query(int x)
{
    int res=0,p=0,cntt=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(cnt[tr[p][!u]])
		{
//			cout<<"zhuangtai"<<endl;
			if(res*2+1>(h>>(i)))
			{
				cntt+=cnt[tr[p][!u]];
//				cout<<"p:"<<cnt[tr[p][!u]]<<endl;
				if(cnt[tr[p][u]])
				{
					res=res*2;
					p=tr[p][u];
				}
				else 
				{
					return cntt;
				}
			}
			else
			{
				res=res*2+1,p=tr[p][!u];
			}
		} 
        else
		{
//			cout<<"yeue"<<endl;
			if(res*2>(h>>(i)))
			{
				cntt+=cnt[tr[p][!u]];
				return cntt;
			}
			else
			{
				res=res*2,p=tr[p][u];
			}
		} 
//		cout<<"i:"<<i<<" "<<cntt<<" "<<res<<endl;
    }
    return cntt;
}
int main ()
{
	scanf("%d%d",&n,&hp);
//	insert(0,1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d",&x);
			insert(x,1);
		}
		else if(op==1)
		{
			scanf("%d",&x);
			insert(x,-1);
		}
		else
		{
			scanf("%d%d",&x,&h);
			fj(h);
			res=query(x);
			printf("%d\n",res);
			if(!res) hp--;
		}
	}
	printf("%d",hp);
	return 0;
}