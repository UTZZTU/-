#include <iostream>
#include <string>
using namespace std;
class vehicle
{
	public:
		void display();
		vehicle(int a,string b);
	private:
		int ID;
		string name;
};
class bike:public vehicle
{
	public:
	    void display();
	    bike(int a,string b,int c);	
	private:
		int weight;
};
vehicle::vehicle(int a,string b)
{
	ID=a;
	name=b;
}
void vehicle::display()
{
	printf("vehicleID=%d ",ID);
	cout<<"vehicleName="<<name;
}
bike::bike(int a,string b,int c):vehicle(a,b)
{
	weight=c;
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