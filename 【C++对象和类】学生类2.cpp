#include <iostream>
#include <string>
using namespace std;
class student
{
	public:
		void open(string num,string nme,int sum1,int sum2,int sum3);
		void display();
	private:
		string name;
		string number;
		int score1,score2,score3,sum;
};
void student::open(string num,string nme,int sum1,int sum2,int sum3)
{
	number=num;
	name=nme;
	score1=sum1;
	score2=sum2;
	score3=sum3;
	sum=sum1+sum2+sum3;
}
void student::display()
{
	cout<<number<<" "<<name<<" "<<score1<<" "<<score2<<" "<<score3<<" "<<sum<<endl;
}
int main ()
{
	student people;
	string a,b;
	int c,d,e;
	cin>>a>>b>>c>>d>>e;
	people.open(a,b,c,d,e);
	people.display();
	return 0;
}