#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solved()
{
    cin >> n;
    cin >> s;
    int num1 = count(s.begin(), s.end(), '(');
    int num2 = n - num1;
    if (num1 != num2)
    {
        cout << -1 << endl;
    }
    else
    {
        int tot = 0, op = 0, flag1 = 0, flag2 = 0;
        for (auto x : s)
        {
            if (x == '(')
            {
                tot++;
                op--;
                if (op < 0)
                    flag2 = 1;
            }
            else
            {
                tot--;
                op++;
                if (tot < 0)
                    flag1 = 1;
            }
        }
        if (flag1 == 0 || flag2 == 0)
        {
            cout << 1 << endl;
            for (int i = 0; i < n; ++i)
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            tot = 0;
            cout << 2 << endl;
            for (auto x : s)
            {
                if (x == '(')
                {
                    if (tot < 0)
                        cout << 1 << " ";
                    else
                        cout << 2 << " ";
                    tot++;
                }
                else
                {
                    tot--;
                    if (tot < 0)
                        cout << 1 << " ";
                    else
                        cout << 2 << " ";
                }
            }
            cout << endl;
        }
    }
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solved();
	}
	return 0;
}
