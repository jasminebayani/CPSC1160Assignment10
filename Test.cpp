/* Test.cpp 
 * This is a test program for Inheritance, Polymorphism, Exceptions
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
*/

#include <random>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "MyDate.h"
#include "Faculty.h"
#include "Staff.h"

//Functions
void testException();
Person typeOfPerson();

//Constant variables
const int NUMRANDOMPEOPLE = 1000;


/*****************************************************************************************
PROBLEM 3
The test program's function that creates a Person, Student, Employee, Faculty and Staff and 
invoke their toString() function
*****************************************************************************************/
int main()
{
	//PROBLEM 4 & 5
	cout << "\nTesting Exception: " << endl;
	testException();

	cout << "\n****END OF PROBLEM 4 & 5****\n" << endl;
	
	cout << "INVOKING toString() functions for Person class & its derived classes: \n" << endl;

	//PROBLEM 2 & 3
	Person person1("Jasmine", "address" , 778, "jasmine@outlook.com");
	cout << "1.) "<< person1.toString();

	Student student1("Mikee", "address", 604, "mikee@gmail.com", "sophomore");
	cout << "\n2.) "<< student1.toString();
	
	Employee employee1( "Jasmine", "address", 788, "employee@gmail.com", "Office 101", 1000, new MyDate("February", 24, 2017));
	cout << "\n3.) "<< employee1.toString();

	Faculty faculty1("Anne", "address", 143, "anne@gmail.com", "Office 101", 2000, new MyDate("September", 20, 2018), "1pm-2pm", 5);
	cout << "\n4.) "<< faculty1.toString();


	Staff staff1("Mark", "address", 100, "mrpresident@gmail.com", "Office 888", 15000, new MyDate("June", 20, 1996), "President");
	cout << "\n5.) "<< staff1.toString() << endl;
	
	return 0;
}

/*****************************************************************************************
PROBLEM 5 
A test  program's function  that  creates 1000 random person and checks  the unwritten rule.
The ratio of generating student, faculty and staff are 0.91, 0.02 and 0.07 respectively.
*****************************************************************************************/
void testException()
{
	while(!(Person::howMany() == NUMRANDOMPEOPLE))
	{
		typeOfPerson();
		
		/*UNCOMMENT FOR DEBUGGING PURPOSES
		cout << "Person count: " << Person::howMany() << " " << endl;
		cout << "Student count: " << Student::howMany() << endl; 
		cout << "Faculty count: " << Faculty::howMany() << endl;
		cout << "Staff count: " << Staff::howMany() << endl;
		cout << "___________________________" << endl;
		*/
	
	}

	cout << "___________________________" << endl;
	cout << "BREAK DOWN OF OBJECTS CREATED: " << endl;
	cout << "Student count: " << Student::howMany() << endl; //<< round(0.91 * Person::howMany()) << endl;
	cout << "Faculty count: " << Faculty::howMany() << endl; //round(0.02 * Person::howMany()) << endl;
	cout << "Staff count: " << Staff::howMany() << endl; //round(0.07 * Person::howMany()) << endl;
	cout << "___________________________" << endl;
	cout << "TOTAL NUMBER OF PERSON OBJECTS: " << Person::howMany() << endl;
	//cout << personCount
 
}

/*****************************************************************************************
PROBLEM 5 
A test  program's function that returns a random Person object
*****************************************************************************************/
Person typeOfPerson()
{
	random_device rd;

    // Initialize Mersenne Twister pseudo-random number generator
    mt19937 gen(rd());

    // Generate pseudo-random numbers
    // uniformly distributed in range (1, 100)
    uniform_int_distribution<> dis(1, 3);
    
    int randomNum = dis(gen);

	Person personCreated;

	switch(randomNum)
	{ 
		case 1: cout << "Attempting to create student..\n "; 
				personCreated = Student(); 
				break;
		case 2: cout << "Attempting to create faculty..\n "; 
				personCreated = Faculty(); 
				break;
		case 3: cout << "Attempting to create staff..\n "; 
				personCreated = Staff(); 
				break;
	}
	
	return personCreated;
}