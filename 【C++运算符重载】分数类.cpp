#include <iostream>
#include <cmath>
using namespace std;
int fun(int a,int b)
{
	int i,j,c;
	i=max(a,b);
	j=min(a,b);
	while(j!=0)
	{
		c=i%j;
		i=j;
		j=c;
	}
	return i;
}
class fraction
{
	public:
		fraction();
		fraction(int s,int x);
		void input(int s,int x);
		void output();
		fraction operator+(const fraction &t)const;
		fraction operator-(const fraction &t)const;
		fraction operator*(const fraction &t)const;
		fraction operator/(const fraction &t)const;
	private:
		int fz;
		int fm;
};
fraction::fraction()
{
	fz=0;
	fm=1;
}
fraction::fraction(int s,int x)
{
	fz=s;
	fm=x;
}
void fraction::input(int s,int x)
{
	fz=s;
	fm=x;
}
void fraction::output()
{
	if(fz==0||fm==0)
	printf("0\n");
	else if(fm==1)
	printf("%d\n",fz);
	else
	printf("%d/%d\n",fz,fm);
}
fraction fraction::operator+(const fraction &t)const
{
	int s,x,tf,gbs;
	s=t.fz;
	x=t.fm;
	tf=fun(x,fm);
	gbs=x*fm/tf;
	fraction u;
	u.fz=gbs/x*s+gbs/fm*fz;
	u.fm=gbs;
	if(u.fz==0)
	return u;
	tf=fun(abs(u.fz),u.fm);
	u.fz/=tf;
	u.fm/=tf;
	return u;
}
fraction fraction::operator-(const fraction &t)const
{
	int s,x,tf,gbs;
	s=t.fz;
	x=t.fm;
	tf=fun(x,fm);
	gbs=x*fm/tf;
	fraction u;
	u.fz=gbs/fm*fz-gbs/x*s;
	u.fm=gbs;
	if(u.fz==0)
	return u;
	tf=fun(abs(u.fz),u.fm);
	u.fz/=tf;
	u.fm/=tf;
	return u;
}
fraction fraction::operator*(const fraction &t)const
{
	int s,x,tf,gbs;
	s=t.fz;
	x=t.fm;
	fraction u;
	u.fz=s*fz;
	u.fm=fm*x;
	if(u.fz==0)
	return u;
	tf=fun(abs(u.fz),u.fm);
	u.fz/=tf;
	u.fm/=tf;
	return u;
}
fraction fraction::operator/(const fraction &t)const
{
	int s,x,tf,gbs;
	s=t.fz;
	x=t.fm;
	fraction u;
	u.fz=fz*x;
	u.fm=fm*s;
	if(u.fz==0||u.fm==0)
	return u;
	tf=fun(abs(u.fz),u.fm);
	u.fz/=tf;
	u.fm/=tf;
	return u;
}
int main ()
{
	int x,y;
	 fraction x1,x2(2,7),x3,y1,y2,z1,z2,z3,z4,z5;
	 cin>>x>>y;
   x3.input(x,y);
   cin>>x>>y;
   y1.input(x,y);
   cin>>x>>y;
   y2.input(x,y);

   z1=x3+y1;      z1.output();
   z2=x3-y1;       z2.output();
   z3=x3*y2;       z3.output();
   z4=x3/y2;       z4.output();
   z5=x1+x2;      z5.output();
 return 0;
}