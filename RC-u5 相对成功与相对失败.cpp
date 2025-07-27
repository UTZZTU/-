#include <bits/stdc++.h>
using namespace std;
int t,num1,num2,num3,num4,k,res;
struct node
{
	int t1,t2;
}s[100010];
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		num1=num2=num3=num4=res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].t1>>s[i].t2;
			if(s[i].t1==1&&s[i].t2==1)
			{
				num1++;
			}
			else if(s[i].t1==1&&s[i].t2==2)
			{
				num2++;
			}
			else if(s[i].t1==2&&s[i].t2==1)
			{
				num3++;
			}
			else if(s[i].t1==2&&s[i].t2==2)
			{
				num4++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			if()
			{
				res++;
			}
		}
		printf("%d\n",res);
		
	}
	return 0;
}