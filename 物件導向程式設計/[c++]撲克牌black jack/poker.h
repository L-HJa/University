#ifndef _POKER_H
#define _POKER_H

#include <vector>
#include "Header.h"

extern bool pokercard[52];

class player {
public:
	int list;	//i_player
	int money;
	int bets;
	int insurance;
	int point;
	bool doublebet;
	bool giveup;
	vector<int> card;
	int cardS;
	int sum;
	bool threetimepay;	//three times pay	
	player(int);
};

extern vector<player> playerlist;		//	playerlist is players informations, [0] is mine.
extern vector<int> cardtime;
class game {
public:
	int comnum;						//COM number
	player* p_banker;				//point to banker
	vector<player*> p_playlist;		//each game player list
	game() { comnum = 0; p_banker = nullptr; }
	const int MINBET = 100;
	void setplayer(int);
	void setbanker();
	void setplaylist(void);
	void addsum(int, int);
};	extern game G;
#define TotalPlayer (G.comnum + 1)
#define NowPlayer (G.p_playlist.size())

// Game Function
void Newgame(void);
void showcard(int);
void showcard(int, int);
void bet(void);
void addcard(int);
void distribution(void);
void insurance(void);
void doublebetprocess(int i_player);
void doublebet(void);
void giveip(void);
void lastaddcard(void);
void settlement(void);
void showmoney(void);
void showgrade(void);
//	extra use
void eraser(void);
#endif
