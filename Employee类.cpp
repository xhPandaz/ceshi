#include<iostream>
#include<string>
using namespace std;
class Employee{
	private:
		string firstName;//名 
		string lastName;//姓 
		int monthlySalary;//月薪
	public:
		Employee(string ming,string xing,int ms);//构造函数 
		//名对应的设置函数和获取函数
		void  setFirstName(string ming);
		string getFirstName();
		//姓对应的设置函数和获取函数
		void setLastName(string xing);
		string getLastName();
		//月薪对应的设置函数和获取函数
		void  setMonthlySalary(int ms);
		int getMonthlySalary();
};
Employee::Employee(string ming,string xing,int ms)
{
	firstName=ming;
	lastName=xing;
	monthlySalary=ms;
}

void Employee::setFirstName(string ming)
{
	firstName=ming;
}
string Employee::getFirstName()
{
	return firstName;
}

void Employee::setLastName(string xing)
{
	lastName=xing;
}
string Employee::getLastName()
{
	return lastName;
}

void Employee::setMonthlySalary(int ms)
{
	monthlySalary=ms;
}
int Employee::getMonthlySalary()
{
	if(monthlySalary<0)
	{
		monthlySalary=0;
	}
	return monthlySalary;
}





//StudybarCommentBegin
// function main begins program execution
int main()
{
    // create two Employee objects
    Employee employee1( "Lisa", "Roberts", 4500 );
    Employee employee2( "Mark", "Stein", 4000 );
    
    // display each Employee's yearly salary
    cout << "Employees' yearly salaries: " << endl;
    
    // retrieve and display employee1's monthly salary multiplied by 12
    int monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName()
    << ": $" << monthlySalary1 * 12 << endl;
    
    // retrieve and display employee2's monthly salary multiplied by 12
    int monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName()
    << ": $" << monthlySalary2 * 12 << endl;
    
    // give each Employee a 10% raise
    employee1.setMonthlySalary( monthlySalary1 * 1.1 );
    employee2.setMonthlySalary( monthlySalary2 * 1.1 );
    
    // display each Employee's yearly salary again
    cout << "\nEmployees' yearly salaries after 10% raise: " << endl;
    
    // retrieve and display employee1's monthly salary multiplied by 12
    monthlySalary1 = employee1.getMonthlySalary();
    cout << employee1.getFirstName() << " " << employee1.getLastName()
    << ": $" << monthlySalary1 * 12 << endl;
    
    monthlySalary2 = employee2.getMonthlySalary();
    cout << employee2.getFirstName() << " " << employee2.getLastName()
    << ": $" << monthlySalary2 * 12 << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
