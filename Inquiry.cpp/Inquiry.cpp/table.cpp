#include<iostream>
using namespace std;
#include "table.h"
Table::Table() 
{
	number_inquiries = 0;
	capacity = 1;
	inquiries = NULL;
}
Table::Table(const Table& table) 
{
	number_inquiries = table.number_inquiries;
	capacity = table.capacity;
	inquiries = new Inquiry[number_inquiries];
	for(int i = 0 ; i<number_inquiries; i++)
	{
		inquiries[i] = table.inquiries[i];
	}
}
Table& Table::operator=(const Table& table)
{
	if(this!=&table)
	{
		delete [] inquiries; 
		number_inquiries = table.number_inquiries;
		capacity = table.capacity;
		inquiries = new Inquiry[number_inquiries];
		for(int i = 0 ; i<number_inquiries; i++)
		{
			inquiries[i] = table.inquiries[i];
		}
	}
	return *this;
}
Table::~Table()
{
	delete [] inquiries;
}
Inquiry* Table::get_inquiries() const
{
	return inquiries;
}
void Table::addInquiry(const Inquiry& inq)
{
	if(number_inquiries < capacity)
	{
		if(number_inquiries == 0)
		{
			inquiries = new Inquiry[1];
			inquiries[number_inquiries++] = inq;
		}
		else
		{
		inquiries[number_inquiries++] = inq;
		}
	}
	else
	{
		Inquiry* newInquiries = new Inquiry[capacity*2];
		for(int i = 0; i < number_inquiries; i++)
		{
			newInquiries[i] = inquiries[i];
		}
		delete [] inquiries;
		inquiries = newInquiries;
		inquiries[number_inquiries++] = inq;
		capacity*=2;
	}
}
void Table::removeInquiry(const Inquiry& inq) // ne raboti, ne mojah da razbera zashto
{
	int k = 0;
	Inquiry* newInquiries = new Inquiry[number_inquiries - 1];
	for(int i = 0; i<number_inquiries; i++)
	{
		if(inquiries[i].get_what_for() != inq.get_what_for())
		{
			newInquiries[k] = inquiries[i];
			k++;
		}
	}
	delete [] inquiries;
	number_inquiries--;
	inquiries = newInquiries;
}
void Table::display() const
{
	for(int i = 0; i<number_inquiries; i++)
	{
		inquiries[i].print();
	}
}