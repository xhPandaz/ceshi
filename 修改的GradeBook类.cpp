#include<iostream>
using namespace std;
class GradeBook{
	protected:
		string m_teacherName;
		string m_courseName;
	public:
		GradeBook(string tn, string cn):m_teacherName(tn),m_courseName(cn){}
		void setInstructorName(string name) {m_courseName = name;}
		string getInstructorName() {return m_courseName;}
		void displayMessage();
		
		
		
};

void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for" << endl <<"CS101 Introduction to C++ Programming!"<<endl;
	cout << "This course is presented by: " << m_courseName;
}



//StudybarCommentBegin
int main()
{
   // create a GradeBook object; pass a course name and instructor name
   GradeBook gradeBook( 
      "CS101 Introduction to C++ Programming", "Professor Smith" );

   // display initial value of instructorName of GradeBook object
   cout << "gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n"; 

   // modify the instructorName using set function
   gradeBook.setInstructorName( "Assistant Professor Bates" );

   // display new value of instructorName
   cout << "new gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n";

   // display welcome message and instructor's name
   gradeBook.displayMessage(); 
   return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
