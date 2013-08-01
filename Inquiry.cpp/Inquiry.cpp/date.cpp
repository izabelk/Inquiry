#include "date.h"
#include<iostream>
using namespace std;
Date::Date()
{
	day=1;
	month=1;
	year=2000;
}
Date::Date(int d, int m, int y)
{
	if(isValid(d, m, y))
	{
		day=d;
		month=m;
		year=y;
	}
}
void Date::set_day(int d)
{
	if(isValid(d, month, year))
	{
		day=d;
	}
}
int Date::get_day() const
{
	return day;
}
void Date::set_month(int m)
{
	if(isValid(day, m, year))
	{
		month=m;
	}
}
int Date::get_month() const
{
	return month;
}
void Date::set_year(int y)
{
	if(isValid(day, month, y))
	{
		year=y;
	}
}
void Date::set_date(int d, int m, int y)
{
	if(isValid(d, m, y))
	{
		day=d;
		month=m;
		year=y;
	}
}
void Date::print() const
{
	cout<<day<<"."<<month<<"."<<year<<endl;
}
bool isValid(int d, int m, int y)
{
	int number_days=0;
	bool Valid = y>0 && m>=1 && m<=12 && d>0;
	if(Valid)
	{
		switch(m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:number_days=31; break;
		case 4:
		case 6:
		case 9:
		case 11:number_days=30; break;
		case 2: if((y%4==0 && y%100!=0) || y%400==0) number_days=29; else number_days=28;
		}
	}
	if(Valid && d<=number_days)
		return true;
	else 
		return false;
}