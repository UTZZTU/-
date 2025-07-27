#include <bits/stdc++.h>
using namespace std;
int t,n,bx,shu,d;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		bx=shu=d=0;
		scanf("%d",&n);
		getchar();
		cin>>s;
		if(s.size()&1)
		{
			d=1;
		}
		for(int i=0,j=s.size()-1;i<j;i++,j--)
		{
			if(s[i]==s[j]) shu++;
			else bx++;
		}
		int i=0;
		for(i;i<=n;i++)
		{
			if(i<bx) printf("0");
			else
			{
				if((i-bx)&1)
				{
					if(d)
					{
						if((i-bx-d)/2<=shu) printf("1");
						else printf("0");
					}
					else
					{
						printf("0");
					}
				}
				else
				{
					if((i-bx)/2<=shu) printf("1");
					else printf("0");
				}
			}
		}
		printf("\n");
	}
	return 0;
}