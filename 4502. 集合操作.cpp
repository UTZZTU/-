#include <bits/stdc++.h>
using namespace std;
int w[500010];
int k,pos,q,op,x;
double r,sum;
int main ()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			w[++pos]=x;
			while(k+1<=pos&&w[k+1]<=(sum+w[pos])*1.0/(k+1))
			sum+=w[++k];
			r=max(r,w[pos]-(sum+w[pos])*1.0/(k+1));
		}
		else
		printf("%.6f\n",r);
	}
	return 0;
}