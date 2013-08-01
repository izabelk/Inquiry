#include "inquiry.h"
#include <iostream>
#include <cstring>
using namespace std;
Inquiry::Inquiry()
{
	town = new char[strlen("Unknown town")+1];
	strcpy(town, "Unknown town");
	WhatFor = new char[strlen("Unknown title")+1];
	strcpy(WhatFor, "Unknown title");
	number_questions = 0;
	capacity = 8;
	questions = NULL;
}
Inquiry::Inquiry(char* _town, Date date, char* what_for, int num, Question* ques) : takenOn(date)
{
	town = new char[strlen(_town)+1];
	strcpy(town, _town);
	WhatFor = new char[strlen(what_for)+1];
	strcpy(WhatFor, what_for);
	number_questions = num;
	questions = new Question[number_questions];
	capacity = number_questions;
	for(int i=0; i<number_questions; i++)
	{
		questions[i] = ques[i];
	}
}
Inquiry::Inquiry(const Inquiry& inquiry) : takenOn(inquiry.takenOn)
{
	town = new char[strlen(inquiry.town)+1];
	strcpy(town, inquiry.town);
	WhatFor = new char[strlen(inquiry.WhatFor)+1];
	strcpy(WhatFor, inquiry.WhatFor);
	number_questions = inquiry.number_questions;
	capacity = inquiry.capacity;
	questions = new Question[number_questions];
	for(int i=0; i<number_questions; i++)
	{
		questions[i] = inquiry.questions[i];	
	}
}
Inquiry& Inquiry::operator=(const Inquiry& inquiry)
{
	if(this!=&inquiry)
	{
		delete [] town;
		delete [] WhatFor;
		delete [] questions;
		town = new char[strlen(inquiry.town)+1];
		strcpy(town, inquiry.town);
		takenOn = inquiry.takenOn;
		WhatFor = new char[strlen(inquiry.WhatFor)+1];
		strcpy(WhatFor, inquiry.WhatFor);
		number_questions = inquiry.number_questions;
		capacity = inquiry.capacity;
		questions = new Question[number_questions];
		for(int i=0; i<number_questions; i++)
		{
			questions[i] = inquiry.questions[i];	
		}
	}
	return *this;
}
Inquiry::~Inquiry()
{
	delete [] town;
	delete [] WhatFor;
	//delete [] questions; ne gi triq, zashtoto posle gi dostupvam v druga funkciq i gurmi i mi trqbvat
}
void Inquiry::set_town(char* _town)
{
	delete [] town;
	town = new char[strlen(_town)+1];
	strcpy(town, _town);
}
char* Inquiry::get_town() const
{
	return town;
}
void Inquiry::set_date(Date date)
{
	takenOn = date;
}
Date Inquiry::get_date() const
{
	return takenOn;
}
void Inquiry::set_what_for(char* title)
{
	delete [] WhatFor;
	WhatFor = new char[strlen(title)+1];
	strcpy(WhatFor, title);
}
char* Inquiry::get_what_for() const
{
	return WhatFor;
}
void Inquiry::set_number_question(int num)
{
	number_questions = num;
}
int Inquiry::get_number_questions() const
{
	return number_questions;
}
void Inquiry::set_questions(Question* ques)
{
	delete [] questions;
	questions = new Question[number_questions];
	for(int i=0; i<number_questions; i++)
	{
		questions[i] = ques[i];
	}
}
Question* Inquiry::get_questions() const
{
	return questions;
}
void Inquiry::add_question(const Question& question)
{
	if(number_questions<capacity)
	{
		questions[number_questions++] = question;
	}
	else
	{
		Question* newQuestions = new Question[capacity*2];
		for(int i=0; i<number_questions; i++)
		{
			newQuestions[i] = questions[i];
		}
		delete [] questions;
		questions = newQuestions;
		capacity*=2;
		questions[number_questions++] = question;
	}
}
void Inquiry::remove_question(int index)
{
	int k=0;
	Question* newQuestions = new Question[number_questions-1];
	for(int i=0; i<number_questions; i++)
	{
		if(i!=index-1)
		{
			newQuestions[k] = questions[i];
			k++;
		}
	}
	delete [] questions;
	number_questions--;
	questions = newQuestions;
}
void Inquiry::change_question(int index)
{
	for(int i=0; i<number_questions; i++)
	{
		if(i==index)
		{
			char temp[30];
			cout<<endl;
			cout<<"Enter the changed clue!"<<endl;
			cin.ignore();
			cin.getline(temp, 30);
			questions[i-1].set_clue(temp);
		}
	}
}
void Inquiry::print() const
{
	cout<<"Town:"<<town<<endl;
	cout<<"Date:";
	takenOn.print();
	cout<<"Title:"<<WhatFor<<endl;
	cout<<"Number of the questions in the inquiry:"<<number_questions<<endl;
	cout<<"Questions:"<<endl;
	for(int i=0; i<number_questions; i++)
	{
		questions[i].print();
		cout<<endl;
	}

}
void Inquiry::give_answers()
{
	cout<<"Answer the questions, please!"<<endl;
	for(int i=0; i<number_questions; i++)
	{
		questions[i].give_answer();
	}
}
