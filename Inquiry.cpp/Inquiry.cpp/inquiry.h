#ifndef INQUIRY_H
#define INQUIRY_H
#include "date.h"
#include "question.h"
class Inquiry
{
public:
	Inquiry();
	Inquiry(char*, Date, char*, int, Question*);
	Inquiry(const Inquiry&);
	Inquiry& operator = (const Inquiry&);
	~Inquiry();
	void set_town(char*);
	char* get_town() const;
	void set_date(Date);
	Date get_date() const;
	void set_what_for(char*);
	char* get_what_for() const;
	void set_number_question(int);
	int get_number_questions() const;
	void set_questions(Question*);
	Question* get_questions() const;
	void add_question(const Question&);
	void remove_question(int);
	void change_question(int);
	void print() const;
	void give_answers();
private:
	char* town;
	Date takenOn; // data na provejdane 
	char* WhatFor; // opisanie na anketata
	int number_questions;
	int capacity;
	Question* questions;
};
#endif