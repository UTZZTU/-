#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}s[1000010];
stack<node> st;
bool cmp(node a,node b)
{
	if(a.l!=b.l)
	return a.l<b.l;
	else
	return a.r<b.r;
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
}

int n,dfs[1000010],tree[1000010],cnt;

int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		dfs[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		tree[i]=read();
	}
	for(int i=2;i<=n;i++)
	{
		int x=dfs[i],y=dfs[i-1];
			if(tree[x]<tree[y])
			{
				s[++cnt]={min(x,y),max(x,y)};
				if(tree[y]>tree[x]+1)
				{
					st.push({y,tree[y]-tree[x]-1});
				}
			}
			else
			{
				node u=st.top();
				s[++cnt]={min(x,u.l),max(x,u.l)};
				st.pop();
				if(u.r-tree[x]>0)
				{
					st.push({u.l,u.r-tree[x]});
				}
			}
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	printf("%d %d\n",s[i].l,s[i].r);
	return 0;
}