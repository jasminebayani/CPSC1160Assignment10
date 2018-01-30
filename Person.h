/*
 * Person.h
 *
 *  Created on: Mar 28, 2017
 *      Author: missjasmineanne
 */

#ifndef PERSON_H_
#define PERSON_H_


#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

static int personCount = 0;
static int studentCount = 0;
static int employeeCount = 0;
static int facultyCount = 0;
static int staffCount = 0;

const double STUDENT_RATIO = 0.91;
const double FACULTY_RATIO = 0.02;
const double STAFF_RATIO = 0.07;

using namespace std;

class Person
{
	public:
		Person()
		{
		}
		Person(string name);
		Person(string name, string address, int phoneNumber, string emailAddress);
		
		static int howMany();
		
		bool passesUnwrittenRule();
		
		/********************************************************************************
		PROBLEM 2
		a constant virtual toString function in the Person class that is overriden in 
		each of its derived classes to display the class name, person’s name, 
		and other details
		*********************************************************************************/
		virtual string toString() const
		{
			std::stringstream ss;
			
			ss << "Person's name is: " << name << endl;
			ss << "Here are the details for this person:" << endl;
			ss << " Name: " << name << endl;
			ss << " Class: Person" << endl;
			ss <<  " Address: " << address << endl;
			ss << " Phone #: " << phoneNumber << endl;
			ss << " Email: " << emailAddress << endl;
			
			std::string str = ss.str();

			return str;
		}
		
	protected:
		string name;
		string address;
		int phoneNumber;
		string emailAddress;

};

Person::Person(string name)
{
	this->name = name;
}

Person::Person(string name, string address, int phoneNumber, string emailAddress)
{
	this->name = name;	
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->emailAddress = emailAddress;
}

bool Person::passesUnwrittenRule()
{
	bool pass;
	
	int maxStudent = round(STUDENT_RATIO * personCount);
	int maxFaculty = round(FACULTY_RATIO * personCount);
	int maxStaff = round(STAFF_RATIO * personCount);
	
	if(studentCount <= maxStudent && facultyCount <= maxFaculty && staffCount <= maxStaff)
		pass = true;
	else
		pass = false;

	return pass;
}

int Person::howMany()
{
	return personCount;
}

#endif /* PERSON_H_ */
