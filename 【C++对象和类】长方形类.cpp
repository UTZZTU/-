#include<iostream>
using namespace std;
class rectangle
{
	public:
		rectangle();
		rectangle(double a,double b);
		void assign(double a,double b);
		void display();
	private:
		double l,d;
		double s;
		double c;
};
rectangle::rectangle()
{
	l=0.0;
	d=0.0;
	c=0.0;
	s=0.0;
}
rectangle::rectangle(double a,double b)
{
	l=max(a,b);
	d=min(a,b);
	c=2*(a+b);
	s=a*b;
}
void rectangle::assign(double a,double b)
{
	l=max(a,b);
	d=min(a,b);
	c=2*(a+b);
	s=a*b;
}
void rectangle::display()
{
	printf("%.2f,%.2f,%.2f,%.2f\n",l,d,c,s);
}
int main ()
{
	rectangle c1,c2(2.0,1.0),c3;
	double x,y;
	cin>>x>>y;
	c1.assign(x,y);
	c3.display();
	c2.display();
	c1.display();
	return 0;
}