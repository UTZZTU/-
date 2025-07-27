#include<bits/stdc++.h>
using namespace std;
#define mm 10004
struct node
{
    int to, next;
    bool operator < (const node &b) const {
        if(to == b.to) return next < b.next;
        else return to < b.to;
    }
};
node Map[mm * 10];
int dfn[mm], low[mm], head[mm];
node ans[mm];
int top;
int n, sig, root;
void tardfs(int u, int father)
{
    dfn[u] = low[u] = sig++;
    for(int i = head[u]; ~i; i = Map[i].next)
    {
        int to = Map[i].to;
        if(!dfn[to])
        {
            tardfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > dfn[u])
            {
                ans[top].to = min(u, to);
                ans[top++].next = max(u, to);
            }
        }
        else if(to != father)
        {
            low[u] = min(low[u], dfn[to]);
        }
    }
    return;
}
void add(int u, int v, int &cnt)
{
    Map[cnt].to = v;
    Map[cnt].next = head[u];
    head[u] = cnt++;
}
int main()
{
    int u, m, v, cnt;
    while(~scanf("%d", &n))
    {
        sig = 1;
        cnt = 0; top = 0;
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &u);
            u = u + 1;
            scanf("%*c%*c%d%*c", &m);
            while(m--)//存图
            {
                scanf("%d", &v);
                v = v + 1;
                add(u, v, cnt);
                add(v, u, cnt);
            }
        }
        for(int i = 0; i < n; i++)
        {
            root = i;
            if(!dfn[i])
            tardfs(i, root);
        }
        sort(ans, ans + top);
        printf("%d critical links\n", top);
        for(int i = 0; i < top; i++)
        {
            printf("%d - %d\n", ans[i].to - 1, ans[i].next - 1);
        }
        printf("\n");
    }
    return 0;
}