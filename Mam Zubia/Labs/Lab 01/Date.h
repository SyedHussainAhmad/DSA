#ifndef DATE_H
#define DATE_H
#include"String.h"
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
	bool isValidDay(int) const;
	bool isValidMonth(int) const;
	String getMonthStr();
public:
	Date();
	Date(int day, int month, int year);
	void addDays(int days);
	void subtractDays(int days);
	void displayDate();
};


#endif // !DATE_H


