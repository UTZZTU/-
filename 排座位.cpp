#include<iostream>
using namespace std;
int a[200] = {0};
int fz[200][200] = {0}; 
int fun(int x)
{
	int r = x;
	while(1)
	{
		if(a[r] == 0)
		{
			return r;
		}
		r = a[r];
	}
}
void add(int n, int m)
{
	int x = fun(n);
	int y = fun(m);
	if(x!=y)
		a[x] = y;
}
int main()
{
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int i;
	for(i=0;i<m;i++)
	{
		int q, w, e;
		cin>>q>>w>>e;
		if(e == 1)
		{
			add(q,w);
		}
		else
		{
			fz[q][w] = 1;
			fz[w][q] = 1;
		}
	}
	for(i=0;i<k;i++)
	{
		int q, w;
		cin>>q>>w;
		if(fun(q)==fun(w)&&fz[q][w]!=1)
		{
			printf("No problem\n");
		}
		else if(fun(q)==fun(w)&&fz[q][w]==1)
		{
			printf("OK but...\n");
		}
		else if(fun(q)!=fun(w)&&fz[q][w]==0)
		{
			printf("OK\n");
		}
		else if(fz[q][w]==1&&fun(q)!=fun(w))
		{
			printf("No way\n");
		}
	}	
	return 0;
}