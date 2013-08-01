#ifndef QUESTION_H
#define QUESTION_H
class Question
{
public:
	Question();
	Question(char*, int, char**);
	Question(const Question&);
	Question& operator = (const Question&);
	~Question();
	void set_clue(char*);
	char* get_clue() const;
	void set_answers_count(int);
	int get_answers_count() const;
	void set_possibleAnswers(char**);
	char** get_possibleAnswers() const;
	void set_right_answers();
	int get_right_answers() const;
	void set_answers();
	int* get_answers() const;
	int* get_counters() const;
	void print() const;
	void give_answer();
	void see_user_answer() const;
private:
	char* clue; // uslovie na vuprosa
	int answers_count; // broi vuzmojni otgovori
	char** possibleAnswers; // samite vuzmojni otgovori
	int right_answers; // kolko otgovora se davat na daden vupros
	int* answers; // index na otgovora, koito sa ni dali 
	int* counters; // broqch na dadenite otgovori
};
#endif