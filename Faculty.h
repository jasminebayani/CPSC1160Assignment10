/*  Faculty.h
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
 *	Student #: 100238808
*/

#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "MyDate.h"

using namespace std;

class Faculty: public Employee
{
	public:
		/*********************************************************************************
		PROBLEM 4
		The organization has an unwritten rule that for every 10-12 students a person  
		must be employed. Rewrite your classes and its method to throw a runtime_error 
		if the number of employees doesn’t  satisfy  the  rule. The exception should be 
		clear whether it is time to hire or fire employees
		*********************************************************************************/
		Faculty()
		{
			personCount++;
			facultyCount++;
			
			try
			{
				if(!passesUnwrittenRule())
				{
					personCount--;
					facultyCount--;
					if(facultyCount > 0)
						throw runtime_error("FIRE EMPLOYEE \n");
					else
						throw runtime_error("NEED MORE STUDENTS \n");
				}	

					cout << "SUCCESS: Faculty has been created." << endl;

			}
			catch(runtime_error e)
			{
				cout << "ERROR: " << e.what();
			}
		}
		
		Faculty(string name, string address, int phoneNumber, string emailAddress, string office, int salary, MyDate* dateHired, string officeHour, int rank):Employee(name, address, phoneNumber, emailAddress, office, salary, dateHired)
		{
			this->officeHour = officeHour;
			this->rank = rank;
		}
		
		static int howMany();
		
		/********************************************************************************
		PROBLEM 2
		*********************************************************************************/
		string toString() const
		{
			std::stringstream ss;
	
			ss << "Person's name is: " << name << endl;
			ss << "Here are the details for this person:" << endl;
			ss << " Name: " << name << endl;
			ss << " Class: Faculty" << endl;
			ss <<  " Address: " << address << endl;
			ss << " Phone #: " << phoneNumber << endl;
			ss << " Email: " << emailAddress << endl;
			ss << " Office: " << office << endl;
			ss << " Salary: $" << salary << endl;
			ss << " Date Hired: " << *dateHired << endl;
			ss << " Office Hour: " << officeHour << endl;
			ss << " Rank: " << rank << endl;
			
			std::string str = ss.str();
			return str;
		}

	private:
		string officeHour;
		int rank;

};
#endif

int Faculty::howMany()
{
	return facultyCount;
}