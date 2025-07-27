#include <bits/stdc++.h>
using namespace std;
int s=1,x=0,z=0,y=1,pd,n;
int dx1=0,dy1=1,dx2=1,dy2=1,dx3=0,dy3=0,dx4=1,dy4=0,fx=0;
void check()
{
	if(dx1==dx2&&dy1==dy2||dx1==dx3&&dy1==dy3||dx1==dx4&&dy1==dy4||dx3==dx2&&dy3==dy2||dx4==dx2&&dy4==dy2||dx3==dx4&&dy3==dy4)
	pd=1;
}
void gx()
{
	s=max(s,max(dy1,max(dy2,max(dy3,dy4))));
	x=min(x,min(dy1,min(dy2,min(dy3,dy4))));
	z=min(z,min(dx1,min(dx2,min(dx3,dx4))));
	y=max(y,max(dx1,max(dx2,max(dx3,dx4))));
}
string u;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		getline(cin,u);
		if(u[0]=='F'&&u[1]=='L')
		{
			if(u[2]=='P')
			{
				    int dx,dy;
					dx=dx1-dy1+dy2,dy=dx1+dy1-dx2;
					dx2=dx,dy2=dy;
					dx=dx1-dy1+dy3,dy=dx1+dy1-dx3;
					dx3=dx,dy3=dy;
					dx=dx1-dy1+dy4,dy=dx1+dy1-dx4;
					dx4=dx,dy4=dy;
					fx++;
					fx%=4;
			}
			else
			{
				if(fx==0)
			{
				if(u[2]=='F')
				dy1++;
				else if(u[2]=='B')
				dy1--;
				else if(u[2]=='R')
				dx1++;
				else if(u[2]=='L')
				dx1--;
			}
			else if(fx==1)
			{
				if(u[2]=='F')
				dx1++;
				else if(u[2]=='B')
				dx1--;
				else if(u[2]=='R')
				dy1--;
				else if(u[2]=='L')
				dy1++;
			}
			else if(fx==2)
			{
				if(u[2]=='F')
				dy1--;
				else if(u[2]=='B')
				dy1++;
				else if(u[2]=='R')
				dx1--;
				else if(u[2]=='L')
				dx1++;
			}
			else if(fx==3)
			{
				if(u[2]=='F')
				dx1--;
				else if(u[2]=='B')
				dx1++;
				else if(u[2]=='R')
				dy1++;
				else if(u[2]=='L')
				dy1--;
			}
			}
		}
		else if(u[0]=='F'&&u[1]=='R')
		{
			if(u[2]=='P')
			{
				    int dx,dy;
					dx=dx2-dy2+dy1,dy=dx2+dy2-dx1;
					dx1=dx,dy1=dy;
					dx=dx2-dy2+dy3,dy=dx2+dy2-dx3;
					dx3=dx,dy3=dy;
					dx=dx2-dy2+dy4,dy=dx2+dy2-dx4;
					dx4=dx,dy4=dy;
					fx++;
					fx%=4;
			}
			else
			{
				if(fx==0)
			{
				if(u[2]=='F')
				dy2++;
				else if(u[2]=='B')
				dy2--;
				else if(u[2]=='R')
				dx2++;
				else if(u[2]=='L')
				dx2--;
			}
			else if(fx==1)
			{
				if(u[2]=='F')
				dx2++;
				else if(u[2]=='B')
				dx2--;
				else if(u[2]=='R')
				dy2--;
				else if(u[2]=='L')
				dy2++;
			}
			else if(fx==2)
			{
				if(u[2]=='F')
				dy2--;
				else if(u[2]=='B')
				dy2++;
				else if(u[2]=='R')
				dx2--;
				else if(u[2]=='L')
				dx2++;
			}
			else if(fx==3)
			{
				if(u[2]=='F')
				dx2--;
				else if(u[2]=='B')
				dx2++;
				else if(u[2]=='R')
				dy2++;
				else if(u[2]=='L')
				dy2--;
			}
			}
		}
		else if(u[0]=='R'&&u[1]=='L')
		{
			if(u[2]=='P')
			{
				    int dx,dy;
					dx=dx3-dy3+dy2,dy=dx3+dy3-dx2;
					dx2=dx,dy2=dy;
					dx=dx3-dy3+dy1,dy=dx3+dy3-dx1;
					dx1=dx,dy1=dy;
					dx=dx3-dy3+dy4,dy=dx3+dy3-dx4;
					dx4=dx,dy4=dy;
					fx++;
					fx%=4;
			}
			else
			{
				if(fx==0)
			{
				if(u[2]=='F')
				dy3++;
				else if(u[2]=='B')
				dy3--;
				else if(u[2]=='R')
				dx3++;
				else if(u[2]=='L')
				dx3--;
			}
			else if(fx==1)
			{
				if(u[2]=='F')
				dx3++;
				else if(u[2]=='B')
				dx3--;
				else if(u[2]=='R')
				dy3--;
				else if(u[2]=='L')
				dy3++;
			}
			else if(fx==2)
			{
				if(u[2]=='F')
				dy3--;
				else if(u[2]=='B')
				dy3++;
				else if(u[2]=='R')
				dx3--;
				else if(u[2]=='L')
				dx3++;
			}
			else if(fx==3)
			{
				if(u[2]=='F')
				dx3--;
				else if(u[2]=='B')
				dx3++;
				else if(u[2]=='R')
				dy3++;
				else if(u[2]=='L')
				dy3--;
			}
			}
		}
		else if(u[0]=='R'&&u[1]=='R')
		{
			if(u[2]=='P')
			{
				    int dx,dy;
					dx=dx4-dy4+dy2,dy=dx4+dy4-dx2;
					dx2=dx,dy2=dy;
					dx=dx4-dy4+dy3,dy=dx4+dy4-dx3;
					dx3=dx,dy3=dy;
					dx=dx4-dy4+dy1,dy=dx4+dy4-dx1;
					dx1=dx,dy1=dy;
					fx++;
					fx%=4;
			}
			else
			{
				if(fx==0)
			{
				if(u[2]=='F')
				dy4++;
				else if(u[2]=='B')
				dy4--;
				else if(u[2]=='R')
				dx4++;
				else if(u[2]=='L')
				dx4--;
			}
			else if(fx==1)
			{
				if(u[2]=='F')
				dx4++;
				else if(u[2]=='B')
				dx4--;
				else if(u[2]=='R')
				dy4--;
				else if(u[2]=='L')
				dy4++;
			}
			else if(fx==2)
			{
				if(u[2]=='F')
				dy4--;
				else if(u[2]=='B')
				dy4++;
				else if(u[2]=='R')
				dx4--;
				else if(u[2]=='L')
				dx4++;
			}
			else if(fx==3)
			{
				if(u[2]=='F')
				dx4--;
				else if(u[2]=='B')
				dx4++;
				else if(u[2]=='R')
				dy4++;
				else if(u[2]=='L')
				dy4--;
			}
			}
		}
		check();
		gx();
	}
	if(pd==1)
	cout<<-1;
	else
	cout<<(s-x+1)*(y-z+1);
	return 0;
}