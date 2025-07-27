#include <bits/stdc++.h>
using namespace std;
bool judge(int n)
{
	if(n==2||n==3)
	return true;
	if(n%6!=1&&n%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(n));i+=6)
		{
			if(n%i==0||n%(i+2)==0)
			return false;
		}
		return true;
	}
}
int x;
vector<int> yz;
int main ()
{
	cin>>x;
	if(judge(x))
	{
		printf("1\n");
		printf("%d\n",x);
	}
	else
	{
		int pos,ans=0;
		for(int i=2;i<=ceil(sqrt(x));i++)
		{
			if(x%i==0)
			{
				int sum=i;
				for(int j=i+1;j<=ceil(sqrt(x));j++)
				{
					sum*=j;
					if(x%sum!=0)
					{
						if(j-i>ans)
						{
							ans=j-i;
							pos=i;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=pos;i<=pos+ans-1;i++)
		{
			if(i!=pos)
			cout<<"*";
			cout<<i;
		}
	}
	return 0;
}