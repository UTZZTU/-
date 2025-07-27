#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
 
using namespace std;
struct mac{
	int x,y;
	mac(int x=0, int y=0):x(x),y(y) {}
};
mac macs[26];
stack<mac> stk;
 
int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string j;
		cin >> j;
		int k = j[0]-'A';
		cin >> macs[k].x >> macs[k].y;
	}
 
	string op;
	while(cin >> op)
	{
		int cnt = 0; int error = 0;
		for(int i=0; i<op.length(); i++)
		{
            if(isalpha(op[i]))stk.push(macs[op[i]-'A']);
            else if(op[i]==')'){
				mac m2 = stk.top(); stk.pop();
				mac m1 = stk.top(); stk.pop();
				if(m1.y!=m2.x){error=1;break;}
				mac m; m.x = m1.x; m.y = m2.y;
				cnt += m1.x*m1.y*m2.y;
				stk.push(m);
            }
		}
		if(error){printf("error\n");while(!stk.empty())stk.pop();}
		else printf("%d\n",cnt);
	}
    return 0;
}