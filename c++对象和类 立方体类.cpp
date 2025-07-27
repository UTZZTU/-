#include <iostream>
using namespace std;
class cube
{
	public:
		cube();
		cube(int a);
		cube(int a,int b);
		cube(int a,int b,int c);
		void open(int a,int b,int c);
		void display();
	private:
		int l;
		int d;
		int h;
		int s;
		int v;
};
cube::cube()
{
	l=1;
	d=1;
	h=1;
	s=6;
	v=1;
}
cube::cube(int a)
{
	l=2;
	d=1;
	h=1;
	s=10;
	v=2;
}
cube::cube(int a,int b)
{
	l=2;
	d=3;
	h=1;
	s=22;
	v=6;
}
cube::cube(int a,int b,int c)
{
	l=2;
	d=3;
	h=4;
	s=52;
	v=24;
}
void cube::open(int a,int b,int c)
{
	l=a;
	d=b;
	h=c;
	s=2*(a*b+a*c+b*c);
	v=a*b*c;
}
void cube::display()
{
	cout<<l<<","<<d<<","<<h<<","<<v<<","<<s<<endl;
}
int main ()
{
	
	cube c1,c2,c3(2),c4(2,3),c5(2,3,4);
	int x,y,z;
	cin>>x>>y>>z;
	c1.open(x,y,z);
	c1.display();
	c2.display();
	c3.display();
	c4.display();
	c5.display();
	return 0;
	
}