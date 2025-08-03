#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps=1e-8;
const double pi=acos(-1.0);
const int inf=0x3f3f3f3f;
const ll INF=1e18;
const int Mod=1e9+7;
const int maxn=2e5+10;

int f[maxn],primes[maxn],cnt,color[maxn],maxx;
bool st[maxn];
void init()
{
	st[1]=st[0]=true;
	for(int i=2;i<=200000;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=200000;++j)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
	}
}
int main(){
	init();
	f[1]=1;
	color[1]=1;
	maxx=1;
    for(int i=2;i<=300;i++)
    {
    	set<int> stt;
    	for(int j=1;j<i;j++)
    	{
    		stt.insert(color[j]);
		}
    	for(int j=1;j<i;j++)
    	{
    		if(!st[i^j])
    		{
    			if(stt.find(color[j])!=stt.end())
    			stt.erase(stt.find(color[j]));
			}
		}
		if(stt.size())
		{
			color[i]=*stt.rbegin();
		}
		else
		{
			color[i]=++maxx;
		}
		f[i]=maxx;
		cout<<"num: "<<f[i]<<" "<<color[i]<<endl;
		cout<<i<<endl;
	}
/*
1 2 3 4
4 3 2 1
3 4 1 2
2 1 4 3
2 1 4 3
3 4 1 2
4 3 2 1
1 2 3 4


5 6 7 8
8 7 6 5
7 8 5 6
6 5 8 7
6 5 8 7

*/
	

    return 0;
}




