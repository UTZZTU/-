#include"iostream"
#include"stack"
#include"string"
#include"iomanip"

using namespace std;

stack<double>num;   //存放数字
stack<char>op;   //存放操作符

bool check(char a, char b)
{
	if ((a == '*'&&b == '+') || (a == '*'&&b == '-'))return true;
	if ((a == '/'&&b == '+') || (a == '/'&&b == '-'))return true;
	return false;
}

int main()
{
	string ac_str;
	while (getline(cin,ac_str)&&ac_str!="0")
	{
		while (!num.empty()){ num.pop(); }
		ac_str.push_back('\n');
		for (int i = 0; i < ac_str.length(); i++)
		{
			if (ac_str[i] >= '0'&&ac_str[i] <= '9')   //遇到数字进行存放
			{
				int t = 0;
				while (ac_str[i] != ' '&&ac_str[i] != '\n')   //多位数的处理
				{  
					t += ac_str[i] - '0', t *= 10;
					i++;
				}
				t /= 10;
				num.push(t);
			}
			else if (ac_str[i] == '+' || ac_str[i] == '-' || ac_str[i] == '*' || ac_str[i] == '/')   //遇到操作符进行操作或存放
			{
				while (1)
				{
					if (op.empty() || (!op.empty() && check(ac_str[i], op.top())))   //存放操作符
					{ op.push(ac_str[i]); break; }
					else   //进行计算
					{
						double a, b, c;
						a = num.top(), num.pop();
						b = num.top(), num.pop();
						if (op.top() == '+'){ op.pop(); c = a + b; num.push(c); }
						else if (op.top() == '-'){ op.pop(); c = a - b; num.push(c); }
						else if (op.top() == '*'){ op.pop(); c = a * b; num.push(c); }
						else if (op.top() == '/'){ op.pop(); c = a / b; num.push(c); }
					}
				}
			}
		}
		while (!op.empty())   //处理最后的操作符栈
		{
			double a, b, c;
			b = num.top(), num.pop();
			a = num.top(), num.pop();
			if (op.top() == '+'){ op.pop(); c = a + b; num.push(c); }
			else if (op.top() == '-'){ op.pop(); c = a - b; num.push(c); }
			else if (op.top() == '*'){ op.pop(); c = a * b; num.push(c); }
			else if (op.top() == '/'){ op.pop(); c = a / b; num.push(c); }
		}
		cout <<fixed<<setprecision(2)<< num.top() << endl;
		num.pop();
	}
	return 0;
}