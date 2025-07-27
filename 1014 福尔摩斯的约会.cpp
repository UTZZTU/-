#include <bits/stdc++.h>
using namespace std;
string s[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
string a,b;
int day,xs,fz,pd;
int main ()
{
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.size();i++)
	{
		if(!pd)
		{
			if(a[i]>='A'&&a[i]<='Z')
		{
				if(a[i]==b[i])
				{
						day=a[i]-'A'+1;
						pd++;	
				}
		}
		}
		else 
					{if(a[i]==b[i])
					{
						if(a[i]>='0'&&a[i]<='9')
						{
							xs=a[i]-'0';
							break;
						}
						else if(a[i]>='A'&&a[i]<='Z')
						{
							xs=a[i]-'A'+10;
							break;
						}
					}
						
					}
	}
	getline(cin,a);
	getline(cin,b);
	pd=0;
	for(int i=0;i<a.size();i++)
	{
				if(a[i]==b[i]&&(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'))
				{
					fz=i;
					break;
				}
	}
	cout<<s[day%7]<<" ";
	printf("%02d:%02d",xs,fz);
	return 0;
}