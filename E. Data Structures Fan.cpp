#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],num1,num2,q,tp,l,r,x;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=b[i-1]^a[i];
		}
		getchar();
		cin>>s;
		s=" "+s;
		num1=num2=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1') num1^=a[i];
			else num2^=a[i];
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&tp);
			if(tp==1)
			{
				scanf("%d%d",&l,&r);
				num1^=b[r]^b[l-1];
				num2^=b[r]^b[l-1];
			}
			else
			{
				scanf("%d",&x);
				if(x)
				{
					printf("%d\n",num1);
				}
				else
				{
					printf("%d\n",num2);
				}
			}
		}
	}
	return 0;
}