#include <bits/stdc++.h>
using namespace std;
long long ans=0;
long long sw[205],sv[205];
int n;
long long m;
struct node
{
int w,v;
}a[205];
inline int read()  //���
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool mycmp(node a,node b)
{
return a.w>b.w;
}
void dfs(int x,long long sumw,long long sumv)
{
ans=max(ans,sumv);
if (sumw+a[n].w>m) return;  //������֦�������Ѹ���
if (sumv+sv[x]<ans) return;
if (sumw+sw[x]<=m)
{
ans=max(ans,sumv+sv[x]);
return;
}
if (sumw+a[x].w<=m) dfs(x+1,sumw+a[x].w,sumv+a[x].v);  //�������ȡ��ǰ������ݹ�
dfs(x+1,sumw,sumv);  //��ȡ
}
int main()
{
int T;
T=read();
for (int t=1;t<=T;t++)
{
scanf("%d %lld",&n,&m);
for (int i=1;i<=n;i++) scanf("%d %d",&a[i].w,&a[i].v);
sort(a+1,a+n+1,mycmp);  //��ʱ��Ӵ�С����
sw[n+1]=0; sv[n+1]=0;  //��ֵ����Ϊ�ǵ��ƣ�����û��Ҫmemset
for (int i=n;i>=1;i--)  //��׺��
{
sw[i]=sw[i+1]+a[i].w;
sv[i]=sv[i+1]+a[i].v;
}
ans=0;
dfs(1,0,0);
printf("%lld\n",ans);  //�������ֵ
}
return 0;
}

