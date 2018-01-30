/* Student.h
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
 *	Student #: 100238808
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student: public Person
{
	private:
	string status;

	public:
		/*********************************************************************************
		PROBLEM 4
		The organization has an unwritten rule that for every 10-12 students a person  
		must be employed. Rewrite your classes and its method to throw a runtime_error 
		if the number of employees doesn’t  satisfy  the  rule. The exception should be 
		clear whether it is time to hire or fire employees
		*********************************************************************************/
		Student()
		{
			personCount++;
			studentCount++;
			
			try
			{
				if(!passesUnwrittenRule())
				{
					if(studentCount >= round(STUDENT_RATIO * personCount))
						throw runtime_error("HIRE EMPLOYEE \n");
				}
				
				cout << "SUCCESS: Student has been created." << endl;
			
			}
			catch(runtime_error e)
			{
				cout << "ERROR: " << e.what();
			}
			
		}
		Student(string status, string name):Person(name)
		{
			this->status = status;
		}
		Student(string name, string address, int phoneNumber, string emailAddress, string status):Person(name, address, phoneNumber, emailAddress)
		{
			this->status = status;
		}
		
		static int howMany();		

		/********************************************************************************
		PROBLEM 2
		*********************************************************************************/
		string toString() const
		{
			std::stringstream ss;
			
			ss <<  "Person's name is: " << name << endl; //". " << name << " is a Student"<<  endl;
			ss << "Here are the details for this person:" << endl;
			ss << " Name: " << name << endl;
			ss << " Class: Student" << endl;
			ss <<  " Address: " << address << endl;
			ss << " Phone #: " << phoneNumber << endl;
			ss << " Email: " << emailAddress << endl;
			ss << " Status: " << status << endl;
			
			std::string str = ss.str();
			
			return str;
		}
		

};
#endif

int Student::howMany()
{
	return studentCount;
}
