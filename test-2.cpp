#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<int> mul1,mul2;
int p=-1,q=-1,t,l,r;
char op[2];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d %d",op,&l,&r);
		if(op[0]=='+')
		{
			if(p==-1)
			{
				p=r;
			}
			else
			{
				p=min(p,r);
			}
			if(q==-1)
			{
				q=l;
			}
			else
			{
				q=max(q,l);
			}
			mul1.insert(r);
			mul2.insert(l);
		}
		else
		{
			mul1.erase(mul1.lower_bound(r));
			if(mul1.size())
			p=*mul1.begin();
			else p=0;
			mul2.erase(mul2.lower_bound(l));
			if(mul2.size())
			q=*mul2.rbegin();
			else q=0;
		}
		if(p<q)
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}