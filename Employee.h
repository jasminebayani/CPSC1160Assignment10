/*  Employee.h
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
 *	Student #: 100238808
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "MyDate.h"

using namespace std;

class Employee: public Person
{

	protected:
		string office;
		int salary;
		MyDate* dateHired;

	public:
		Employee()
		{
			employeeCount++;
		}

		Employee(string name, string address, int phoneNumber, string emailAddress, string office, int salary, MyDate* dateHired):Person(name, address, phoneNumber, emailAddress)
		{
			this->office = office;
			this->salary = salary;
			this->dateHired = dateHired;
		}

		/********************************************************************************
		PROBLEM 2
		*********************************************************************************/
		string toString() const
		{
			std::stringstream ss;

			ss << "Person's name is: " << name << endl;
			ss << "Here are the details for this person:" << endl;
			ss << " Name: " << name << endl;
			ss << " Class: Employee" << endl;
			ss <<  " Address: " << address << endl;
			ss << " Phone #: " << phoneNumber << endl;
			ss << " Email: " << emailAddress << endl;
			ss << " Office: " << office << endl;
			ss << " Salary: $" << salary << endl;
			ss << " Date Hired: " << *dateHired << endl;
			
			std::string str = ss.str();
			
			return str;
		}
};
#endif
