#include <iostream>
#include <string>
using namespace std;
int  main ()
{
	string a,b="qiandao",c="easy";
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	while(n--)
	{
		getline(cin,a);
		int p=a.find(b),q=a.find(c);
		if(p==-1&&q==-1)
		{
			if(m>0)
			m--;
			else if(m==0)
			{
			     cout<<a;
			     return 0;
			}
		}
	}
	printf("Wo AK le");
	return 0;
}