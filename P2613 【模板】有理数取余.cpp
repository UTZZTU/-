#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c = 19260817;
ll a,b,d,x,y;
inline ll getll()
{
    int res = 0, ch = getchar();
    while(!isdigit(ch) and ch != EOF)
        ch = getchar();
    while(isdigit(ch))
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= c;
        ch = getchar();
    }
    return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main ()
{
	a=getll();
	b=getll();
	d=exgcd(b,c,x,y);
	if(a%d!=0)
	cout<<"Angry!";
	else
	{
		x*=a/d;
		c/=d;
		cout<<(x%c+c)%c;
	}
	return 0;
}