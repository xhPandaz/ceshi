#include<iostream>
#include<string>
#include<iomanip>
//余额 balance
//金额 amount 
using namespace std;
class Account{
	private:
		double balance;
	public:
		Account(double bal);//构造函数确认初始余额的有效性 
		void credit(double bal);//将一笔金额加到当前余额中 
		void debit(double bal);//从此类中取钱
		double getBalance();
};
Account::Account(double bal)
{
	if(bal<0)
	{
		cout<<"\nError:Initial balance cannot be negative.\n\n";
		balance=0;
	}
	else
		balance=bal;
}
void Account::credit(double bal)
{
	
	balance=balance+bal;
	
}
void Account::debit(double bal)
{
	
	if(balance>=bal)
	{
		balance=balance-bal;
	}
	else
	{
		cout<<"Debit amount exceeded account balance.\n"<<endl;
	}
}
double Account::getBalance()
{
	return balance;
}




//StudybarCommentBegin
int main()
{
    Account account1(50.0);

    double withdrawalAmount;
//    cout<<"\nEnter withdrawal amount for account1:";
    cin>>withdrawalAmount;
    cout<<"\nattempting to subtract "<<withdrawalAmount<<" from account1 balance\n";
    
    account1.debit(withdrawalAmount);
    cout<<"account1 balance:$"<<account1.getBalance()<<endl;
    
    Account account2(-2);
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;
    account2.credit(156.4);
    cout<<"\nattempting to add "<<156.4<<" to account2\n";
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;

    return 0;
}
//StudybarCommentEnd
