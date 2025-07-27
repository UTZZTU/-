#include <iostream>
#include <cstdio>
using namespace std;
class point
{
	public:
		point();
		void getdate(int a,int b);
		void display();
		point operator+(const point &t)const;
		point operator-(const point &t)const;
		bool operator==(const point &t)const;
		bool operator!=(const point &t)const;
	private:
		int x;
		int y;
};
point::point()
{
	x=0;
	y=0;
}
void point::getdate(int a,int b)
{
	x=a;
	y=b;
}
void point::display()
{
	printf("(%d,%d)\n",x,y);
}
point point::operator+(const point &t)const
{
	point z;
	z.x=x+t.x;
	z.y=y+t.y;
	return z;
}
point point::operator-(const point &t)const
{
	point z;
	z.x=x-t.x;
	z.y=y-t.y;
	return z;
}
bool point::operator!=(const point &t)const
{
	if(x!=t.x||y!=t.y)
	return true;
	else
	return false;
}
bool point::operator==(const point &t)const
{
	if(x==t.x&&y==t.y)
	return true;
	else
	return false;
}
istream& operator>>(istream &is,point &t)
{
	int a,b;
	is>>a>>b;
	t.getdate(a,b);
	return is;
}
ostream& operator<<(ostream &os,point &t)
{
	t.display();
	return os;
}
int main ()
{
	point x,y,z1,z2;
    cin>>x>>y;
          z1=x+y;
         z2=x-y;
        cout<<z1<<z2;
         if(x==y)   cout<<"x==y"<<endl;
         else   cout<<"x!=y"<<endl;

         if(z1!=z2)   cout<<"z1!=z2"<<endl;
         else   cout<<"z1==z2"<<endl;
         return 0;
}
