#include <bits/stdc++.h>
using namespace std;
int hh1,mm1,ss1,hh2,mm2,ss2,t1,t2;
int main ()
{
	scanf("%d:%d:%d",&hh1,&mm1,&ss1);
	scanf("%d:%d:%d",&hh2,&mm2,&ss2);
	t1=hh1*60*60+mm1*60+ss1;
	t2=hh2*3600+mm2*60+ss2;
	printf("%d",max(t1-t2,t2-t1));
	return 0;
}