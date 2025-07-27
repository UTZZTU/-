#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node1
{
    int x;
    int y;
    
    bool operator<(const node1& a) const
    {
        if (a.x == x)
            return y < a.y;
        return x < a.x;
    }
};
struct node2
{
    int x;
    int y;
    
    bool operator<(const node2& a) const
    {
        if (a.y != y)
            return y < a.y;
        return x < a.x;
    }
};
//bool cmp1(node a,node b)
//{
//	if(a.y!=b.y) return a.y<b.y;
//	else a.x<b.x;
//}
//bool cmp2(node a,node b)
//{
//	if(a.x!=b.x) return a.x<b.x;
//	else a.y<b.y;
//}
multiset<node1> mul1;
multiset<node2> mul2;
int t,l,r;
char op[2];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d %d",op,&l,&r);
		if(op[0]=='+')
		{
			mul1.insert({l,r});
			mul2.insert({l,r});
		}
		else
		{
			mul1.erase(mul1.lower_bound({l,r}));
			mul2.erase(mul2.lower_bound({l,r}));
		}
		if(mul1.size()>=2)
		{
			node1 p=*mul1.rbegin();
			node2 q=*mul2.begin();
			if(p.x>q.y)
			puts("YES");
			else puts("NO");
		} 
		else puts("NO");
	}
	return 0;
}