#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
string u;
char v[210];
int a[210],n,k;
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
		break;
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		while(scanf("%d",&k)!=EOF)
		{
			
			if(!k)
			break;
			getchar();
			getline(cin,u);
			while(u.size()<n)
			u+=' ';
			while(k--)
			{
				for(int i=0;i<n;i++)
				v[a[i+1]-1]=u[i];
				v[n]='\0';
				u=v;
			}
			printf("%s\n",v);
		}
	}
	return 0;
}