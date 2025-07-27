#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d,f1,f2,f3,f4,res,fk;
string s;
int main ()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		cin>>s;
		if(s.size()<8||s.size()>16)
		{
			printf("0\n");
		}
		else
		{
			a=b=c=d=f1=f2=f3=f4=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]>='A'&&s[i]<='Z') a++;
				else if(s[i]>='a'&&s[i]<='z') b++;
				else if(s[i]>='0'&&s[i]<='9') c++;
				else if(s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!') d++;
			}
			if(a) f1=1;
			if(b) f2=1;
			if(c) f3=1;
			if(d) f4=1;
			if(f1+f2+f3+f4>=3)
			{
				res=0;
				fk=0;
				for(int i=0;i<s.size();i++)
				{
					if(s[i]>='A'&&s[i]<='Z')
					{
						int k;
						if(a-1==0) k=0;
						else k=1;
						if(k+f2+f3+f4==4)
						{
							res+=66;
							fk++;
						}
						else if(k+f2+f3+f4==3)
						{
							if(k==0)
							{
								res+=26;
							}
							else if(f2==0)
							{
								res+=26;
							}
							else if(f3==0)
							{
								res+=10;
							}
							else
							{
								res+=4;
							}
							fk++;
						}
						else if(k+f2+f3+f4==2)
						{
							continue;
						}
						
					}
					else if(s[i]>='a'&&s[i]<='z')
					{
						int k;
						if(b-1==0) k=0;
						else k=1;
						if(k+f1+f3+f4==4)
						{
							res+=66;
							fk++;
						}
						else if(k+f1+f3+f4==3)
						{
							if(k==0)
							{
								res+=26;
							}
							else if(f1==0)
							{
								res+=26;
							}
							else if(f3==0)
							{
								res+=10;
							}
							else
							{
								res+=4;
							}
							fk++;
						}
						else if(k+f1+f3+f4==2)
						{
							continue;
						}
					}
					else if(s[i]>='0'&&s[i]<='9')
					{
						int k;
						if(c-1==0) k=0;
						else k=1;
						if(k+f2+f1+f4==4)
						{
							res+=66;
							fk++;
						}
						else if(k+f2+f1+f4==3)
						{
							if(k==0)
							{
								res+=10;
							}
							else if(f2==0)
							{
								res+=26;
							}
							else if(f1==0)
							{
								res+=26;
							}
							else
							{
								res+=4;
							}
							fk++;
						}
						else if(k+f2+f1+f4==2)
						{
							continue;
						}
					}
					else if(s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!')
					{
						int k;
						if(d-1==0) k=0;
						else k=1;
						if(k+f2+f3+f1==4)
						{
							res+=66;
							fk++;
						}
						else if(k+f2+f3+f1==3)
						{
							if(k==0)
							{
								res+=4;
							}
							else if(f2==0)
							{
								res+=26;
							}
							else if(f3==0)
							{
								res+=10;
							}
							else
							{
								res+=26;
							}
							fk++;
						}
						else if(k+f2+f3+f1==2)
						{
							continue;
						}
					}
				}
				printf("%d\n",res-fk);
			}
			else
			printf("0\n");
		}
	}
	return 0;
}