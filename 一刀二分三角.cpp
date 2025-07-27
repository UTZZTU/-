#include <bits/stdc++.h>
using namespace std;
int t,xb,xc,yc;
bool judge(){
	int s=xb*yc;
	for(int i=1;i<xb;i++){
		if(i<=xc){
			int ss=i*i*yc;
			if(s*xc==2*ss) return true;
		}else{
			int ss=(xb-i)*(xb-i)*yc;
			if((xb-xc)*s==2*ss) return true;
		}
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&xb,&xc,&yc);
		if(judge())
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}