#include <bits/stdc++.h>
using namespace std;
int n,tx,ty,flag=-1;
struct node
{
	int a,b,g,k;
}s[10010];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].g,&s[i].k);
	scanf("%d%d",&tx,&ty);
	for(int i=1;i<=n;i++)
	if(s[i].a<=tx&&s[i].a+s[i].g>=tx&&s[i].b<=ty&&s[i].b+s[i].k>=ty)
	flag=i;
	printf("%d",flag);
	return 0;
}