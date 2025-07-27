#include <iostream>
#include <string>
using namespace std;
class Animal
{
	public:
		virtual void cry()=0;
		Animal(string s);
	protected:
		string name;
};
Animal::Animal(string s)
{
	name=s;
}
class Cat:public Animal
{
	public:
		Cat(string s);
		virtual void cry();
};
class Dog:public Animal
{
	public:
		Dog(string s);
		virtual void cry();
};
class Mouse:public Animal
{
	public:
		Mouse(string s);
		virtual void cry();
};
Cat::Cat(string s):Animal(s)
{
	;
}
Dog::Dog(string s):Animal(s)
{
	;
}
Mouse::Mouse(string s):Animal(s)
{
	;
}
void Cat::cry()
{
	cout<<"I am a cat, my name is "<<name<<", miaomiao."<<endl;
}
void Dog::cry()
{
	cout<<"I am a dog, my name is "<<name<<", wangwang."<<endl;
}
void Mouse::cry()
{
	cout<<"I am a mouse, my name is "<<name<<", zhizhi."<<endl;
}
int main ()
{
	Animal *p;
    string name;
    cin >> name;
    Mouse m1(name);
    p = &m1;
    p->cry();

    cin >> name;
    Cat c1(name);
    p = &c1;
    p->cry();

    cin >> name;
    Dog d1(name);
    p = &d1;
    p->cry();
    return 0;
}