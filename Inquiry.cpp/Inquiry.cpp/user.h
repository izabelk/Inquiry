#ifndef USER_H
#define USER_H
#include "date.h"
#include "question.h"
#include "inquiry.h"
#include "table.h"
class User
{
public:
	void WhatToDo(); // funkciq, kqoto ni dava pravo da si izbirame na koi vupros da otgovorim
	void set_inquiry(const Inquiry& inq);
	void analys_answers_one_question(); // analiz na edin vupros 
	void analys_answers_whole_inquiry(User users[], int); //analiz na cqlata anketa
	Inquiry get_inquiry() const ;
	void putUserInList(User users[], int,  User&); // obedinqvane na Userite v masiv
	void set_name(char*);
private:
	Inquiry inquiry;
	char command[6];
};
#endif