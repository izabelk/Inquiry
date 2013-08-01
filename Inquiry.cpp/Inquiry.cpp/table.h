#ifndef TABLE_H
#define TABLE_H
#include "user.h"
#include "inquiry.h"
#include "date.h"
#include "user.h"
class Table
{
public:
	Table();
	Table(const Table&);
	Table& operator = (const Table&);
	~Table();
	Inquiry* get_inquiries() const;
	void addInquiry(const Inquiry&);
	void removeInquiry(const Inquiry&);
	void display() const;
private:
	int number_inquiries;
	int capacity;
	Inquiry* inquiries;
};
#endif