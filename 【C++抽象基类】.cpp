#include <iostream>
using namespace std;
class Shape
{public:
virtual float GetPerim()=0;
};
class Rectangle: public Shape
{
	public:
		Rectangle(int l,int r)
		{
			length=l;
			width=r;
		}
		virtual float GetPerim()
		{
			float o;
			o=2*(length+width);
			return o;
		}
	private:
		int length,width;
};
class Circle: public Shape
{
	public:
		Circle(int r)
		{
			bj=r;
		}
		virtual float GetPerim()
		{
			float o;
			o=2*3.14*bj;
			return o;
		}
	private:
		int bj;
};
int main ()
{
	Shape * sp;
sp=new Circle(10);
cout<<sp->GetPerim ()<<endl;
sp=new Rectangle(6,4);
cout<<sp->GetPerim()<<endl;
return 0;
}