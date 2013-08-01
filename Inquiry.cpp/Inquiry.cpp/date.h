#ifndef DATE_H
#define DATE_H
class Date
{
public:
	Date();
	Date(int, int, int);
	void set_day(int);
	int get_day() const;
	void set_month(int);
	int get_month() const;
	void set_year(int);
	int get_year() const;
	void set_date(int, int, int);
	void print() const;
	friend bool isValid(int, int, int);
private:
	int day,
		month, 
		year;
};
#endif