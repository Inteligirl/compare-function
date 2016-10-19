//Tammy Gibson
//COP2000.0M1 
//User enters two names. Program determines if the names are the same regardless of letter case. Using functions.

#include <iostream>
#include <cctype>
#include <string>
#include <windows.h>     // Needed to display colors

using namespace std;

/************************************
Prototypes
************************************/
bool sameString(string s1, string s2);
string upperCaseIt(string s);
void welcome();

/************************************
Begin main
************************************/
int main()
{
	string name1, name2;  //variables for scope of main
		
	welcome();    //call welcome function

	cout << "\nEnter the first name." << endl;	//get user first name
	cin >> name1;
		
	cout << "\nEnter the second name." << endl;	//get user second name
	cin >> name2;
	

	if (sameString(name1, name2) == true)	//call function to compare names, determine output based on bool return
		cout << "\nThe names " << name1 << " and " << name2 << " are the same." << endl << endl;
	else
		cout << "\nThe names " << name1 << " and " << name2 <<  " are not the same." << endl << endl;
		
	return 0;

}
/************************************
Functions
************************************/
void welcome()		//state purpose of program to user
{
	string stars;   //output formating
	stars.assign(45, '*');
	
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);     //for color display

	SetConsoleTextAttribute(screen, 14);    //add color to display
	cout << endl << stars << endl;
	cout << "\nWelcome to my comparison program." << endl;
	cout << endl << stars << endl;

	SetConsoleTextAttribute(screen, 9);
	cout << "\nThis program will compare two names\n";
	cout << "that you input and determine if they\n";
	cout << "are the same regardless of letter case.\n"<< endl;
	
	SetConsoleTextAttribute(screen, 7);		//return color display to white


}


bool sameString(string s1, string s2)		//compare two strings and determine if they are the same returning a boolean value
{
	s1 = upperCaseIt(s1);	//send name1 to uppercase function
	s2 = upperCaseIt(s2);	//send name2 to uppercase function
		
	if (s1 == s2)
		return true;
	else
		return false;
}

string upperCaseIt(string s)	//convert the string to upper and return value
{
	string nameConverted;
	
	for (int i = 0; i < s.length(); ++i) 
		nameConverted += toupper(s[i]);
	return nameConverted;	//return all changes back to sameString as uppercase
}
