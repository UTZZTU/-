#include <bits/stdc++.h>
using namespace std;
double M,m,v,V;
int t;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>M>>m>>v;
		V=m*v*1.0/(M-m);
		printf("%.2f\n",V);
	}
	return 0;
}