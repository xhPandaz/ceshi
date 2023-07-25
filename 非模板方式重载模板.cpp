#include <iostream>
using namespace std;
template < typename T >

void  printArray( const  T *array,  int  count ) {
	for  (  int  i = 0; i < count; i++ )
		cout  << array[ i ] << " ";
	cout  <<  endl;
}

void  printArray( const  char *array,  int  count ) {
	for  (  int  i = 0; i < count && array[i] != '\0'; i++ )
		cout  << array[ i ] << " ";
	cout  <<  endl;
}
//StudybarCommentBegin

int main() {
	// set size of arrays
	const int aCount = 5;
	const int bCount = 7;
	const int cCount = 6;
	const int sCount = 8;

	// initialize arrays
	int a[ aCount ] = { 1, 2, 3, 4, 5 };
	double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char c[ cCount ] = "HELLO";  // 6th position for null
	const char *strings[ sCount ] = { "one", "two", "three", "four",
	                                  "five", "six", "seven", "eight"
	                                };

	cout << "Array a contains:\n";
	printArray( a, aCount );  // integer template function

	cout << "\nArray b contains:\n";
	printArray( b, bCount );  // float template function

	cout << "\nArray c contains:\n";
	printArray( c, cCount );  // character template function

	cout << "\nArray strings contains:\n";
	printArray( strings, sCount );  // function specific to string arrays

	return 0;

} // end main

//StudybarCommentEnd