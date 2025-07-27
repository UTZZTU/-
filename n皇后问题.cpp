#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,x,y,h[1000010],l[1000010],leftt[2000010],rightt[2000010];
int main ()
{
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&x,&y);
		if(h[x]||l[y]||leftt[y-x+n]||rightt[x+y]){
			printf("No\n");
		} else{
			h[x]=l[y]=leftt[y-x+n]=rightt[x+y]=1;
			printf("Yes\n");
		}
	}
	return 0;
}