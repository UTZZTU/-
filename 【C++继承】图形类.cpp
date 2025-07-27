#include <iostream>
using namespace std;
class figure
{
	public:
		figure(double a,double b);
		void display();
		void getdate(double &a,double &b);
	protected:
		double weight;
		double height;
};
figure::figure(double a,double b)
{
	weight=a;
	height=b;
}
void figure::display()
{
	cout<<"The value of width is "<<weight<<", the height is "<<height;
}
void figure::getdate(double &a,double &b)
{
	a=weight;
	b=height;
}
class rectangle:public figure
{
	public:
		rectangle(double a,double b);
		void display();
		double area();
};
class triangle:public figure
{
	public:
		triangle(double a,double b);
		void display();
		double area();
};
rectangle::rectangle(double a,double b):figure(a,b)
{
}
void rectangle::display()
{
	cout<<"I am a rectangle. ";
	figure::display();
}
double rectangle::area()
{
	double a,b;
	figure::getdate(a,b);
	return a*b;
}
triangle::triangle(double a,double b):figure(a,b)
{
}
void triangle::display()
{
	cout<<"I am a triangle. ";
	figure::display();
}
double triangle::area()
{
	double a,b;
	figure::getdate(a,b);
	return a*b*1.0/2;
}
int main ()
{
	double width,height;
 cin>>width>>height;
 triangle tri(width,height);
 rectangle rect(width,height);
 tri.display();
 cout<<". The area is "<<tri.area()<<endl;
 rect.display();
 cout<<". The area is "<<rect.area()<<endl;
 return 0;
}