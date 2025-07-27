#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,pos,res;
string s;
int main ()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		cin>>s;
		pos=1;
		res=0;
		for(int i=0;i<4;i++)
		{
			int idx=s[i]-'0';
			if(idx==0) idx=10;
			res+=abs(idx-pos);
			pos=idx;
		}
		printf("%d\n",res+4);
	}
	return 0;
}