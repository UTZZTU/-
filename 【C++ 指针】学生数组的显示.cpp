#include <iostream>
using namespace std;
class student
{
	public:
		void getdate(string a,string b,int c);
		void display();
	private:
		string number;
		string name;
		int score;
};
void student::getdate(string a,string b,int c)
{
	number=a;
	name=b;
	score=c;
}
void student::display()
{
	cout<<number<<" "<<name<<" "<<score;
}
int main ()
{
	int n;
	cin>>n;
	class student *t=new class student[n];
	for(int i=0;i<n;i++)
	{
		string a,b;
		int c;
		cin>>a>>b>>c;
		(t+i)->getdate(a,b,c);
	}
	for(int i=0;i<n;i++)
	{
		(t+i)->display();
		if(i!=n-1)
		cout<<endl;
	}
	return 0;
}