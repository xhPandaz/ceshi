#include<iostream>
#include<string>
#include<iomanip>
//��� balance
//��� amount 
using namespace std;
class Account{
	private:
		double balance;
	public:
		Account(double bal);//���캯��ȷ�ϳ�ʼ������Ч�� 
		void credit(double bal);//��һ�ʽ��ӵ���ǰ����� 
		void debit(double bal);//�Ӵ�����ȡǮ
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
