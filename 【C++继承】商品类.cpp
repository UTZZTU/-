#include <iostream>
using namespace std;
class goods
{
	public:
		goods(int a,string b);
		void display();
	private:
		int ID;
		string name;
};
class foods:public goods
{
	public:
		void display();
		foods(int a,string b,int c);
	private:
		int days;
};
goods::goods(int a,string b)
{
	ID=a;
	name=b;
}
void goods::display()
{
	cout<<"goodsID="<<ID<<" "<<"goodsName="<<name;
}
foods::foods(int a,string b,int c):goods(a,b)
{
	days=c;
}
void foods::display()
{
	goods::display();
	cout<<" "<<"days="<<days;
}
int main ()
{
	int ID;
 string name;
 int days;

 cin>>ID>>name;

 class goods goods1(ID,name);
 goods1.display();
 cout<<endl;
 cin>>ID>>name>>days;
 class foods foods1(ID,name,days);
 foods1.display();
 cout<<endl;

    return 0;
}