#include<iostream>
#include<cstring>
#include "question.h"
using namespace std;
Question::Question()
{
	clue = new char[strlen("Unknown clue")+1];
	strcpy(clue, "Unknown clue");
	answers_count=1;
	possibleAnswers = new char*[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		possibleAnswers[i] = new char[strlen("Unknown answer")+1];
		strcpy(possibleAnswers[i], "Unknown answer");
	}
	right_answers=1;
	answers = new int[right_answers];
	counters = new int[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		counters[i]=0;
	}
}
Question::Question(char* _clue, int _answers_count, char** _possibleAnswers)
{
	clue = new char[strlen(_clue)+1];
	strcpy(clue, _clue);
	answers_count = _answers_count;
	possibleAnswers = new char*[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		possibleAnswers[i] = new char[strlen(_possibleAnswers[i])+1];
		strcpy(possibleAnswers[i], _possibleAnswers[i]);
	}
	right_answers = 1;
	answers = new int[right_answers];
	counters = new int[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		counters[i]=0;
	}
}
Question::Question(const Question& question)
{
	clue = new char[strlen(question.clue)+1];
	strcpy(clue, question.clue);
	answers_count = question.answers_count;
	possibleAnswers = new char*[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		possibleAnswers[i] = new char[strlen(question.possibleAnswers[i])+1];
		strcpy(possibleAnswers[i], question.possibleAnswers[i]);
	}
	right_answers = question.right_answers;
	answers = new int[right_answers];
	for(int i=0; i<right_answers; i++)
	{
		answers[i] = question.answers[i];
	}
	counters = new int[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		counters[i] = question.counters[i];
	}
}
Question& Question::operator=(const Question& question)
{
	if(this!=&question)
	{
		delete [] clue;
		for(int i=0; i<answers_count; i++)
		{
			delete possibleAnswers[i];
		}
		delete [] possibleAnswers;
		delete [] answers;
		delete [] counters;
		clue = new char[strlen(question.clue)+1];
		strcpy(clue, question.clue);
		answers_count = question.answers_count;
		possibleAnswers = new char*[answers_count];
		for(int i=0; i<answers_count; i++)
		{
			possibleAnswers[i] = new char[strlen(question.possibleAnswers[i])+1];
			strcpy(possibleAnswers[i], question.possibleAnswers[i]);
		}
		right_answers = question.right_answers;
		answers = new int[right_answers];
		for(int i=0; i<right_answers; i++)
		{
			answers[i] = question.answers[i];
		}
		counters = new int[answers_count];
		for(int i=0; i<answers_count; i++)
		{
			counters[i] = question.counters[i];
		}
	}
	return *this;
}
Question::~Question()
{
	delete [] clue;
	for(int i =0; i<answers_count; i++)
	{
		delete possibleAnswers[i];
	}
	delete [] possibleAnswers;
	delete [] answers;
	delete [] counters;
}
void Question::set_clue(char* _clue)
{
	delete [] clue;
	clue = new char[strlen(_clue)+1];
	strcpy(clue, _clue);
}
char* Question::get_clue() const
{
	return clue;
}
void Question::set_answers_count(int count)
{
	answers_count = count;
}
int Question::get_answers_count() const
{
	return answers_count;
}
void Question::set_possibleAnswers(char** ans)
{
	for(int i=0; i<answers_count; i++)
	{
		delete possibleAnswers[i];
	}
	delete [] possibleAnswers;
	possibleAnswers = new char*[answers_count];
	for(int i=0; i<answers_count; i++)
	{
		possibleAnswers[i] = new char[strlen(ans[i])+1];
		strcpy(possibleAnswers[i], ans[i]);
	}
}
char** Question::get_possibleAnswers() const
{
	return possibleAnswers;
}
void Question::set_right_answers()
{
	cout<<"How many answers you choose?";
	cin>>right_answers;
}
int Question::get_right_answers() const
{
	return right_answers;
}
void Question::set_answers()
{
	delete [] answers;
	answers = new int[right_answers];
	for(int i=0; i<right_answers; i++)
	{
		cin>>answers[i];
		counters[answers[i]-1]++;
	}
}
int* Question::get_answers() const
{
	return answers;
}
int* Question::get_counters() const
{
	return counters;
}
void Question::print() const
{
	cout<<clue<<endl;
	cout<<"Answers:"<<endl;
	for(int i=0; i<answers_count; i++)
	{
		cout<<possibleAnswers[i]<<endl;
	}
}
void Question::give_answer()
{
	cout<<endl;
	this->set_right_answers();
	cout<<"Choose the answer by entering the number of the possible answer!";
	this->set_answers();
	cout<<endl;
}
void Question::see_user_answer() const
{
	cout<<"Your answer is:"<<endl;
	int j=0;
	for(int i=0; i<answers_count; i++)
	{
		while(j<right_answers)
		{
			cout<<possibleAnswers[answers[j]-1]<<endl;
			j++;
		}
		
	}
}

