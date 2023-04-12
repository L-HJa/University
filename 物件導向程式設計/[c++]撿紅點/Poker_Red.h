#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<time.h>
#include<random>
#include<windows.h>
using namespace std;

class card {
public:
	char color;
	int number;

	card(char c = NULL, int n = NULL) :color(c), number(n) {}
	void getcard(char, int );
	bool operator==(const card&);
};


class player {
public:
	list<card> cards;
	int score;

	player(list<card> vc, int s):cards(vc), score(s){}
	void operator-(const card&);
};

class pos{
public:
	int x;
	int y;

	pos(int a, int b):x(a), y(b){}
};

vector<card> check(list<card>);
int pick(vector<card>, list<card>&);
int diposal(list<card>&);

void showtitle(void);
void showcard(int, int, card);
void showboard(void);
void showend(void);

card getcard(void);
int count_score(const card, const card);

extern bool exist_card[52];
extern char cha_color[];

extern list<card> l_sea;
extern list<player> l_player;
