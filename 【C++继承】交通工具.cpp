#include <iostream>
#include <string>
using namespace std;
class vehicle
{
	public:
		vehicle(int x,string y);
		void display();
	private:
		int number;
		string name;
};
class bike:public vehicle
{
	public:
		bike(int x,string y,int z);
		void display();
	private:
		int weight;
};
vehicle::vehicle(int x,string y)
{
	number=x;
	name=y;
}
void vehicle::display()
{
	cout<<"vehicleID="<<number<<" "<<"vehicleName="<<name;
}

bike::bike(int x,string y,int z):vehicle(x,y)
{
	weight=z;
}
void bike::display()
{
	vehicle::display();
	cout<<" weight="<<weight;
}
int main ()
{
	int ID;
 string name;
 int weight;

 cin>>ID>>name;

 class vehicle vehicle1(ID,name);
 vehicle1.display();
 cout<<endl;
 cin>>ID>>name>>weight;
 class bike bike1(ID,name,weight);
 bike1.display();
 cout<<endl;

    return 0;
}