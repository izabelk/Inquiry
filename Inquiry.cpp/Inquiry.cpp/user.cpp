#include<iostream>
#include<cstring>
#include "user.h"
using namespace std;
void User::set_inquiry(const Inquiry& inq)
{
	inquiry = inq;
}
void User::WhatToDo()
{
	int number_answered_questions=0;
	Question* ptrToQuestions = inquiry.get_questions();
	cout<<"With the commands below you can rule how to complete your inquiry."<<endl;
	cout<<"start - begin to complete the inquiry."<<endl;
	cout<<"answer - give answer to a question"<<endl;
	cout<<"n - go to  next question"<<endl;
	cout<<"p - go to previos question"<<endl;
	cout<<"end - finish the inqiury"<<endl;
	cout<<"exit - stop answering the questions"<<endl;
	int i=0;
	while(number_answered_questions!=inquiry.get_number_questions() || strcmp(command, "end")!=0)
	{
		do
		{
			cout<<"Command:"<<endl;
			cin>>command;
			
		} while (strcmp(command, "start")!=0 && strcmp(command, "n")!=0 && strcmp(command, "p")!=0
			&& strcmp(command, "answer")!=0 && strcmp(command, "end")!=0 && strcmp(command, "exit")!=0);
	
		if(strcmp(command, "start")==0)
		{
			ptrToQuestions[i].print();
		}
		else if(strcmp(command, "answer")==0)
		{
			ptrToQuestions[i].give_answer();
			number_answered_questions++;
			i++;
			if(i<=inquiry.get_number_questions()-1)
			{
				ptrToQuestions[i].print();
			}
			else
			{
				cout<<"You managed to complete the inquiry successfully!"<<endl<<endl;
				for(int i=0; i<inquiry.get_number_questions(); i++)
				{
					ptrToQuestions[i].see_user_answer();
				}
				return;
			}
		}
		else if(strcmp(command, "n")==0)
		{
			if(i>=inquiry.get_number_questions()-1)
			{
				cout<<"There are no more questions. Go back!"<<endl;
			}
			else
			{
				ptrToQuestions[i+1].print();
				i++;
			}
		}
		else if(strcmp(command, "p")==0)
		{
			if(i<=0)
			{
				cout<<"There are no previous questions. Go ahead!"<<endl;
			}
			else
			{
				ptrToQuestions[i-1].print();
				i--;
			}

		}
		else if(strcmp(command, "end")==0)
		{
			if(number_answered_questions==inquiry.get_number_questions())
			{
				cout<<"You managed to complete the inquiry successfully!"<<endl<<endl;
				for(int i=0; i<inquiry.get_number_questions(); i++)
				{
					ptrToQuestions[i].see_user_answer();
				}
			}
			else
			{
				cout<<"We are sorry, but you didn't manage to complete the inquiry successfully."<<endl;
				return;
			}
		}
		else if(strcmp(command, "exit")==0)
		{
			cout<<"We are sorry, but you didn't manage to complete the inquiry successfully."<<endl;
			return;
		}
	}
}
void User::analys_answers_one_question()
{
	Question* PointerToQuestions = inquiry.get_questions();
	for(int i=0; i<inquiry.get_number_questions(); i++)
	{
		int* ptrCounters = PointerToQuestions[i].get_counters();
		cout<<"Number given answers to question"<<" "<<i+1<<":"<<" ";
		for(int j=0; j<PointerToQuestions[i].get_answers_count(); j++)
		{
			cout<<ptrCounters[j]<<" ";
		}
		cout<<endl;
	}
}
Inquiry User::get_inquiry() const
{
	return inquiry;
}
void User::analys_answers_whole_inquiry(User users[], int size) // size na masiva
{	
	int** allCounters; // dvumeren masiv, v koito shte subiram otgovorite na vsichki uchastnici za vsichki vuprosi
	Question* PtrToQuestions = inquiry.get_questions();
	allCounters = new int*[inquiry.get_number_questions()];
	for(int i=0; i<inquiry.get_number_questions(); i++)
	{
		allCounters[i] = new int[PtrToQuestions[i].get_answers_count()];
	}
	for(int i=0; i<inquiry.get_number_questions(); i++)
	{
		for(int j=0; j<PtrToQuestions[i].get_answers_count(); j++)
		{
			allCounters[i][j] = 0;
		}
	}
	Question* pointer; 
	for(int k=0; k<size; k++) 
	{
		pointer = users[k].get_inquiry().get_questions();
		for(int i=0; i<inquiry.get_number_questions(); i++)
		{
			int* counts = pointer[i].get_counters();
			for(int j=0; j<PtrToQuestions[i].get_answers_count(); j++)
			{
				allCounters[i][j] += counts[j]; 
			}
		}
	}
	for(int i=0; i<inquiry.get_number_questions(); i++)
	{
		cout<<"Number given answers to question of the inquiry"<<" "<<i+1<<":"<<" ";
		for(int j=0; j<pointer[i].get_answers_count(); j++)
		{
			cout<<allCounters[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0; i<inquiry.get_number_questions(); i++)
	{
		delete allCounters[i];
	}
	delete [] allCounters;
}
void User::putUserInList(User users[], int currentSize,  User& _user) // currentSize - indexa na tekushtiq user v masiva
	// numberUsers - kolko usera shte ima v masiva za dadena anketa
{
	users[currentSize] = _user;
}


