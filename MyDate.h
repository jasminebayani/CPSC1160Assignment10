/*  MyDate.h
 *
 *  Created on: March 28, 2017
 *  Author: Jasmine Bayani
 *	Student #: 100238808
*/

#ifndef MYDATE_H
#define MYDATE_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class MyDate
{
	public:
		MyDate(string month, int day, int year)
		{
			this->month = month;
			this->day = day;
			this->year = year;
		}
		
		string getMonth() const
		{
			return month;
		}
		int getDay() const
		{
			return day;
		}
		int getYear() const
		{
			return year;
		}
		
		friend ostream& operator<<(ostream& out, const MyDate &mydate)
		{
			out << mydate.getMonth() << " " << mydate.getDay() << ", " << mydate.getYear();
			return out;
		}

	public:
		int year;
		string month;
		int day;

};
#endif
