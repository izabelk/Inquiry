#include<iostream>
#include "date.h"
#include "question.h"
#include "inquiry.h"
#include "user.h"
#include "table.h"
using namespace std;
int main()
{
	Date a(5, 5, 2013);
	int br_ans=3;
	char** ans;
	ans = new char*[br_ans];
	ans[0] = new char[strlen("1.Male")+1];
	strcpy(ans[0], "1.Male");
	ans[1] = new char[strlen("2.Female")+1];
	strcpy(ans[1], "2.Female");
	ans[2] = new char[strlen("3.I don't know.")+1];
	strcpy(ans[2], "3.I don't know.");
	Question b("What's your gender?", br_ans, ans);
	int num_ques = 2;
	char** ANS1;
	ANS1 = new char*[2];
	ANS1[0] = new char[strlen("1.Yes")+1];
	strcpy(ANS1[0], "1.Yes");
	ANS1[1] = new char[strlen("2.No")+1];
	strcpy(ANS1[1], "2.No");
	char** ANS2;
	ANS2 = new char*[2];
	ANS2[0] = new char[strlen("1.Gerb")+1];
	strcpy(ANS2[0], "1.Gerb");
	ANS2[1] = new char[strlen("2.BSP")+1];
	strcpy(ANS2[1], "2.BSP");
	Question ques[2] = {Question("Are you going to vote?", 2, ANS1), Question("Who are you going to vote for?", 2, ANS2)};
	Inquiry d("Sofia", a, "Votes", num_ques, ques);
	d.add_question(b);
	//cout<<endl<<endl<<endl;
    //d.print();
	User users1[20];
	User Izi;
	Izi.set_inquiry(d);
	Izi.WhatToDo();
	//Izi.analys_answers_one_question();
	Izi.putUserInList(users1, 0, Izi);
	User Sasho;
	Sasho.set_inquiry(d);
	cout<<endl<<endl<<endl;
	Sasho.WhatToDo();
	//Sasho.analys_answers_one_question();
	Sasho.putUserInList(users1, 1, Sasho);
	cout<<endl<<endl<<endl;
	Izi.analys_answers_whole_inquiry(users1, 2);
	Date c(23, 5, 2013);
	int number_ans = 4;
	char** ANS3;
	ANS3 = new char*[number_ans];
	ANS3[0] = new char[strlen("1.Fruits")+1];
	strcpy(ANS3[0], "1.Fruits");
	ANS3[1] = new char[strlen("2.Vegetables")+1];
	strcpy(ANS3[1], "2.Vegetables");
	ANS3[2] = new char[strlen("3.Chinese food")+1];
	strcpy(ANS3[2], "3.Chinese food");
	ANS3[3] = new char[strlen("4.Fast food")+1];
	strcpy(ANS3[3], "4.Fast food");
	char** ANS4;
	ANS4 = new char*[2];
	ANS4[0] = new char[strlen("1.Yes")+1];
	strcpy(ANS4[0], "1.Yes");
	ANS4[1] = new char[strlen("2.No")+1];
	strcpy(ANS4[1], "2.No");
	Question ques2 [2] = {Question("What's your favourite food?", number_ans, ANS3), 
		Question("Have you been doing some sport recently?", 2, ANS4)};
	Inquiry health("Plovdiv", c, "Health", 2, ques2);
	User users2[20];
	User Marin;
	Marin.set_inquiry(health);
	cout<<endl<<endl<<endl;
	Marin.WhatToDo();
	Marin.putUserInList(users2, 0, Marin);
	User Katq;
	Katq.set_inquiry(health);
	cout<<endl<<endl<<endl;
	Katq.WhatToDo();
	Katq.putUserInList(users2, 1, Katq);
	Katq.analys_answers_whole_inquiry(users2, 2);
	Table x;
	x.addInquiry(d);
	x.addInquiry(health);
	//x.display();
	//cout<<endl;
	for(int i=0; i<br_ans; i++)
	{
		delete ans[i];
	}
	delete [] ans;
	for(int i=0; i<2; i++)
	{
		delete ANS1[i];
	}
	delete [] ANS1;
	for(int i=0; i<2; i++)
	{
		delete ANS2[i];
	}
	delete [] ANS2;
	for(int i = 0; i<number_ans; i++)
	{
		delete ANS3[i];
	}
	delete [] ANS3;
	for(int i = 0; i<2; i++)
	{
		delete ANS4[i];
	}
	delete [] ANS4;
	return 0;
}