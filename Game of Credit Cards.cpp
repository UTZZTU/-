#include <iostream>
#include <string.h>
using namespace std;
int a[11],b[11];
int main ()
{
	string s1,s2;
	int n,sum1=0,sum2=0;
	cin>>n;
	getchar();
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<n;i++)
	{
		a[s2[i]-'0']++;
		b[s2[i]-'0']++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[s1[i]-'0']==0)
		{
			int pd=0;
			for(int j=s1[i]-'0'+1;j<=9;j++)
			{
				if(a[j]>0)
				{
					a[j]--;
					pd=1;
					break;
				}
			}
			if(pd==0)
			{
				sum1++;
				for(int j=0;j<s1[i]-'0';j++)
				{
					if(a[j]>0)
					{
						a[j]--;
						break;
					}
				}
			}
		}
		else
		{
			a[s1[i]-'0']--;
		}
	}
	printf("%d\n",sum1);
	for(int i=0;i<n;i++)
	{
		if(b[s1[i]-'0'+1]>0)
		{
			sum2++;
			b[s1[i]-'0'+1]--;
		}
		else
		{
			int pd=0;
			for(int j=s1[i]-'0'+2;j<=9;j++)
			{
				if(b[j]>0)
				{
					b[j]--;
					pd=1;
					sum2++;
					break;
				}
			}
			if(pd==0)
			{
				for(int j=0;j<=s1[i]-'0';j++)
				{
					if(b[j]>0)
					{
						b[j]--;
						break;
					}
				}
			}
		}
	}
	printf("%d",sum2);
	return 0;
}