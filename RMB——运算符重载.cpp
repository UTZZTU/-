#include <iostream>
using namespace std;
class RMB
{
	public:
		RMB(int a,int b,int c)
		{
			y=a;
			j=b;
			f=c;
		}
		RMB operator+(const int &t)const
		{
			RMB u(0,0,0);
			u.f=f+t;
			u.j=j+u.f/10;
			u.f%=10;
			u.y=y+u.j/10;
			u.j%=10;
			return u;
		}
		void display()
		{
			cout<<y<<" "<<j<<" "<<f<<endl;
		}
	private:
		int y,j,f;
};
int main ()
{
	int yuan, jiao, fen; cin >> yuan >> jiao >> fen;
    RMB M1(yuan, jiao, fen), M2(0, 0, 0);
    int fen1; cin >> fen1;
    M2 = M1 + fen1;
    M2.display();
    return 0;
}