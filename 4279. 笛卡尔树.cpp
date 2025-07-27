#include <bits/stdc++.h>
using namespace std;
const int N = 35;
const int INF = 2147483647;
int n,a[N];
int trlen;
struct node
{
	int l,r,data;
}tree[N];
int dfs(int l,int r)
{
	if(l>=r)
	return -INF;
	int min_value=*min_element(a+l,a+r);
	int min_id=min_element(a+l,a+r)-a;
	int root=trlen;
	tree[trlen++]=(node){dfs(l,min_id),dfs(min_id+1,r),min_value};
	return root;
}
void bfs()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		printf("%d ",tree[p].data);
		if(tree[p].l!=-INF)
		q.push(tree[p].l);
		if(tree[p].r!=-INF)
		q.push(tree[p].r);
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	dfs(0,n);
	bfs();
	return 0;
}