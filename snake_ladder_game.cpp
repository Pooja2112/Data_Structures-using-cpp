//============================================================================
// Name        : assignment3.cpp
// Author      : pooja
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void showboard()
{
	cout<<"30|29|28|27|26|\n 21|22|23|24|25|\n 20|19|18|17|16|\n 11|12|13|14|15|\n 10|9|8|7|6| \n 1|2|3|4|5|";
	cout<<"\n snakes will lower your score";
	cout<<"\n from 27 to 12"<<"\t from 21 to 9" <<"\t from 19 to 7" <<"\t from 17 to 4";
	cout<<"\n ladders will higher your score";
	cout<<"\n from 3 to 22" <<"\t from 5 to 8";
	cout<<"\t from 11 to 26" <<"\t from 20 to 29"<<endl;
}

int roll()
{
	int d;
	d=rand()%6+1;
	return d;
}
int changescore(int score)
{	int new_score;
	int s=score;
	switch(s)
	{
		case 27:new_score=12;
			break;
		case 21:new_score=9;
			break;
		case 17:new_score=4;
			break;
		case 19:new_score=7;
			break;
		case 3:new_score=22;
			break;
		case 5:new_score=8;
			break;
		case 11:new_score=26;
			break;
		case 20:new_score=29;
			break;
		default:new_score=score;
	}
	return (new_score);
}

class node
{
public:
	int data;
	node *next, *prev;
};

class game
{ public:
	node *head;
	game()
	{
		head=NULL;
	}
	void create();
	void show();
	void play();
	node *movef(int, node *);
	node *moveb(int, node *);

};

node * game::movef(int d1, node *p)
{
	for(int i=1;i<=d1;i++)
		p=p->next;
	return p;
}
node * game::moveb(int d1, node *p)
{
	for(int i=d1;i>=1;i--)
		p=p->prev;
	return p;
}

void game::create()
{
	node *temp;
		node *p;
	int i;
	for(i=1;i<=30;i++)
	{

		temp=new node;
		temp->data=i;
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;

		}
	}
}
void game::show()
{
	node *p;
	for(p=head;p!=NULL;p=p->next)
	{
		cout<<p->data;cout<<"<->";
	}
}
void game::play()
{
	int score1=1,score2=1,k,dice,new_s;
	char name1[10];
	cout<<"enter player 1 name-";
	cin>>name1;
	char name2[10];
	cout<<"enter player 2 name-";
	cin>>name2;
	node *p1=head;
	node *p2=head;
	cout<<"\n ";
	showboard();
	while(p1->data!=30 && p2->data!=30)
	{
		cout<<"\n Game starts!" <<endl;
		cout <<name1 <<", Its your turn press 1 to play";
		cin>>k;
		if(k==1)
		{
			dice=roll();
			cout<<"hey you rolled"<<endl<<"you got"<<" "<<dice;
			if(dice+score1<=30)
			{
				p1=movef(dice,p1);
				score1=p1->data ;cout<<" "<<name1 <<"\n your score is"<<  score1<<endl;
				if(p1->data==30)
					{cout<<"\n"<<name1 <<"**you are the winner**";
					break;}

				new_s=changescore(p1->data);
				cout<<"new score is"<<new_s;
				if(new_s!=score1)
				{
					if(new_s < score1)
					{
						cout <<"\n snake ate ";
						while(p1->data!=new_s)
							p1=p1->prev;
					}
					else
					{
						if(new_s>score1)
						{
							cout<< "\n you got a ladder"<<endl;
							while(p1->data!=new_s)
								p1=p1->next;
						}
					}
				}
			}

		}
		cout<<name2 <<", Its ur turn press 1 to play";
				cin>>k;
				if(k==1)
				{
					dice=roll();
					cout<<"hey you rolled"<<endl<<"you got"<<dice;
					if(dice+score2<=30)
					{
						p2=movef(dice,p2);
						score2=p2->data ;cout<<" "<<name2 <<"\t your score is"<< score2 <<endl;
						if(p2->data==30)
							{cout<<"\n "<<name2 <<"**You are the winner**";
							break;}
						new_s=changescore(p2->data);
						cout<<" new score is" <<new_s;
						if(new_s!=score2)
						{
							if(new_s < score2)
							{
								cout <<"\n snake ate ";
								while(p2->data!=new_s)
									p2=p2->prev;
							}
							else
							{
								if(new_s>score2)
								{
									cout<< "\n you got a ladder";
									while(p2->data!=new_s)
										p2=p2->next;
								}
							}
						}
					}

				}
	}
}

int main()

{	int choice;
	game p;
	while(1)
	{	cout<<"\n enter your choice";
		cout<<"\n 1.create list";
		cout<<"\n 2.display ";
		cout<<"\n 3.play game";
		cin>>choice;
		switch(choice)
		{
			case 1:
				p.create();
			break;

			case 2:
				p.show();
				break;

			case 3:
				p.play();
				break;
			default:
				cout<<"you have entered wrong choice";
		}
	}
	return 0;
}
