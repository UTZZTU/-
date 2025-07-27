#include <bits/stdc++.h>
using namespace std;
int date[13]={0,31,30,31,30,31,30,31,31,30,31,30,31};
int nn=1900,yy=1,rr=1,res;
bool judge(int x)
{
	if(x%4==0&&x%100!=0||x%400==0) return true;
	else return false;
}
bool check(int nn,int yy,int rr)
{
	int res1=0,res2=0;
	while(nn)
	{
		res1+=nn%10;
		nn/=10;
	}
	while(yy)
	{
		res2+=yy%10;
		yy/=10;
	}
	while(rr)
	{
		res2+=rr%10;
		rr/=10;
	}
	return res1==res2;
}
int main ()
{
	for(nn;nn<=9999;nn++)
	{
		if(judge(nn)) date[2]=29;
		else date[2]=28;
		for(yy;yy<=12;yy++)
		{
			for(rr;rr<=date[yy];rr++)
			{
				if(check(nn,yy,rr)) res++;
			}
			rr=1;
		}
		yy=1;
	}
	cout<<res<<endl;
	return 0;
}