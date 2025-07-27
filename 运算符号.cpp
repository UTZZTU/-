#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
	putchar('\n');
}

ll t,n;

int main(){
	t=read();
	while(t--)
	{
		n=read();
		if(n==0)
		print(0);
		else if(n==1)
		print(1);
		else{
			if(n&1)
			print(3);
			else
			print(2);
		}
	}
	return 0;
}