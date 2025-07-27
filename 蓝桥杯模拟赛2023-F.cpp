#include <bits/stdc++.h>
using namespace std;
int w,n;
int main ()
{
	cin>>w;
	cin>>n;
	w=(w+n)%7;
	if(w==0) printf("7");
	else printf("%d",w);
	return 0;
}
//蓝桥杯模拟赛2023-D