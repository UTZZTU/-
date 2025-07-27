#include<iostream>
using namespace std;
class bank_account
{
	public:
		void open(int acc_no,double initial_balance);
		void deposit(double amount);
		void withdraw(double amount);
		void display_balance();
	private:
		int account_num;
		double money;
};
void bank_account::open(int acc_no,double initial_balance)
{
	account_num=acc_no;
	money=initial_balance;
}
void bank_account::deposit(double amount)
{
	money+=amount;
}
void bank_account::withdraw(double amount)
{
	money-=amount;
}
void bank_account::display_balance()
{
	cout<<account_num<<"  "<<money<<endl;
}
int main ()
{
	bank_account my_account;
	my_account.open(123,0.0);
	my_account.deposit(100.0);
	my_account.withdraw(50.0);
	my_account.display_balance();
	return 0;
}