/*  Staff.h
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
 *	Student #: 100238808
*/

#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "MyDate.h"

using namespace std;

class Staff: public Employee
{

	private:
		string title;

	public:
		/*********************************************************************************
		PROBLEM 4
		The organization has an unwritten rule that for every 10-12 students a person  
		must be employed. Rewrite your classes and its method to throw a runtime_error 
		if the number of employees doesn’t  satisfy  the  rule. The exception should be 
		clear whether it is time to hire or fire employees
		*********************************************************************************/
		Staff()
		{
			personCount++;
			staffCount++;
			
			try
			{
				if(!passesUnwrittenRule())
				{
					personCount--;
					staffCount--;
					if(staffCount > 0)
						throw runtime_error("FIRE EMPLOYEE \n");
					else
						throw runtime_error("NEED MORE STUDENTS \n");
				}
						
				cout << "SUCCESS: Staff has been created." << endl;
				
			}
			catch(runtime_error e)
			{
				cout << "ERROR: " << e.what();
			}
		}
		
		Staff(string name, string address, int phoneNumber, string emailAddress, string office, int salary, MyDate* dateHired, string title):Employee(name, address, phoneNumber, emailAddress, office, salary, dateHired)
		{
			this->title = title;
		}
		
		static int howMany();

		string toString() const
		{
			std::stringstream ss;
			
			ss << "Person's name is: " << name << endl;
			ss << "Here are the details for this person:" << endl;
			ss << " Name: " << name << endl;
			ss << " Class: Staff" << endl;
			ss <<  " Address: " << address << endl;
			ss << " Phone #: " << phoneNumber << endl;
			ss << " Email: " << emailAddress << endl;
			ss << " Office: " << office << endl;
			ss << " Salary: $" << salary << endl;
			ss << " Date Hired: " << *dateHired << endl;
			ss << " Title: " << title;
					
			std::string str = ss.str();
			
			return str;
		}
};
#endif

int Staff::howMany()
{
	return staffCount;
}