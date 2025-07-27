#include <iostream>
#include <cmath>
using namespace std;
class hexagons
{
	public:
		hexagons(double sideValue=10)
		{
			l=sideValue;
		}
		double circumference()
		{
			double s;
			s=6*l;
			return s;
		}
		double area()
		{
			double r;
			r=1.5*sqrt(3)*l*l;
			return r;
		}
		void setSide(double sideValue)
		{
			l=sideValue;
		}
		double getSide()
		{
			return l;
		}
	private:
		double l;
};
int main ()
{
	double side;
 cin>>side;
 class hexagons hex1;
 cout<<"The side of the hxagons is "<<hex1.getSide()<<endl;
 hex1.setSide(side);
 cout<<"The circumference of the hex1 is "<<hex1.circumference()<<" and area is "<<hex1.area()<<endl;

    return 0;
}