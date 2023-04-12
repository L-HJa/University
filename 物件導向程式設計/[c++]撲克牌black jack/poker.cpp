#include"Header.h"
#include"poker.h"

char	set_0[] =
{
	"q---------w \n"
	"|         | \n"
	"|         | \n"
	"|         | \n"
	"|         | \n"
	"|         | \n"
	"a---------s \n"
};
char	set_1[] =
{
	"q---------w \n"
	"| 1       | \n"
	"|         | \n"
	"|    x    | \n"
	"|         | \n"
	"|        1| \n"
	"a---------s \n"
};
char	set_2[] =
{
	"q---------w \n"
	"| 2       | \n"
	"|    x    | \n"
	"|         | \n"
	"|    x    | \n"
	"|        2| \n"
	"a---------s \n"
};
char	set_3[] =
{
	"q---------w \n"
	"| 3       | \n"
	"|    x    | \n"
	"|    x    | \n"
	"|    x    | \n"
	"|        3| \n"
	"a---------s \n"
};
char	set_4[] =
{
	"q---------w \n"
	"| 4       | \n"
	"|  x   x  | \n"
	"|         | \n"
	"|  x   x  | \n"
	"|        4| \n"
	"a---------s \n"
};
char	set_5[] =
{
	"q---------w \n"
	"| 5       | \n"
	"|  x   x  | \n"
	"|    x    | \n"
	"|  x   x  | \n"
	"|        5| \n"
	"a---------s \n"
};
char	set_6[] =
{
	"q---------w \n"
	"| 6       | \n"
	"|  x   x  | \n"
	"|  x   x  | \n"
	"|  x   x  | \n"
	"|        6| \n"
	"a---------s \n"
};
char	set_7[] =
{
	"q---------w \n"
	"| 7       | \n"
	"|  x   x  | \n"
	"|  x x x  | \n"
	"|  x   x  | \n"
	"|        7| \n"
	"a---------s \n"
};
char	set_8[] =
{
	"q---------w \n"
	"| 8       | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x   x  | \n"
	"|        8| \n"
	"a---------s \n"
};
char	set_9[] =
{
	"q---------w \n"
	"| 9       | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|        9| \n"
	"a---------s \n"
};
char	set_10[] =
{
	"q---------w \n"
	"| 10      | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|    x    | \n"
	"a---------s \n"
};
char	set_11[] =
{
	"q---------w \n"
	"| J       | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x   x  | \n"
	"a---------s \n"
};
char	set_12[] =
{
	"q---------w \n"
	"| Q       | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"|  x x x  | \n"
	"a---------s \n"
};
char	set_13[] =
{
	"q---------w \n"
	"| x     x | \n"
	"|         | \n"
	"|    K    | \n"
	"|         | \n"
	"| x     x | \n"
	"a---------s \n"
};

char* ary_CardNumber[] =
{
	set_0, set_1, set_2, set_3, set_4, set_5, set_6, set_7, set_8, set_9, set_10, set_11, set_12, set_13
};

string SS = "\342\231\240", HH = "\342\231\245", DD = "\342\231\246", CC = "\342\231\243"; 
string Q1 = "\342\225\224", W1 = "\342\225\227", A1 = "\342\225\232", S1 = "\342\225\235", Z1 = "\342\225\220", X1 = "\342\225\221";

string ary_Color[] =
{
	"\342\231\240", "\342\231\245", "\342\231\246", "\342\231\243"
};

static COORD coord;
HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void showcard(int i_player)	//cts cardtime
{
	coord.X = short(15 * (playerlist[i_player].card.size() - 1));
	coord.Y = short(9 * i_player + 3);
	SetConsoleCursorPosition(ConsoleHandle, coord);

	int color = ((&playerlist[i_player] == G.p_banker && &playerlist[i_player] != &playerlist[0] && playerlist[i_player].card.size() > 1) ? 0 : playerlist[i_player].card.back() % 4);
	int number = ((&playerlist[i_player] == G.p_banker && &playerlist[i_player] != &playerlist[0] && playerlist[i_player].card.size() > 1) ? 0 : playerlist[i_player].card.back() % 13 + 1);

	SetConsoleTextAttribute(ConsoleHandle, ((color == 1 || color == 2) ? FOREGROUND_RED : 0) | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	char* p_set = ary_CardNumber[number];
	string s_color = ary_Color[color];
	while (char cc = *p_set++)
	{
		switch (cc)
		{
		case '\n':
			coord.Y++;
			SetConsoleCursorPosition(ConsoleHandle, coord);
			break;
		case 'x':	cout << s_color;	p_set++;	break;
		case 'q':	cout << Q1;	break;
		case 'w':	cout << W1;	break;
		case 'a':	cout << A1;	break;
		case 's':	cout << S1;	break;
		case '-':	cout << Z1;	break;
		case '|':	cout << X1; break;

		default:	cout << cc;
		}
	}
	SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
//------------------------------------------------------------------------------------------
void eraser(void) {
	coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
	SetConsoleCursorPosition(ConsoleHandle, coord);
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 80; i++)
			cout << ' ';
		cout << endl;
	}
}

//	Game Round-----------------------------------------------------------------------------
game G;
bool pokercard[52] = { false };		
vector<player> playerlist;		//	playerlist[0] is mine.			//G.p_playlist is player list in each game;	playerlist is players informations, [0] is mine.
vector<int> cardtime;
//	Game Function-------------------------------------------------------------
void showgametable(int i) {
											//	無需使用 static
	coord.X = 0;	coord.Y = 0;								//	5, 7 等參數 請設定名稱 定放到 enum 中，以利將來統一修改
 		//	存成全域變數，不要每次重抓一次
	SetConsoleCursorPosition(ConsoleHandle, coord);				//	定義一個 #define  SetPosition (x, y)  讓 可讀性更高
	cout << "Round " << i + 1 << "		Banker is ";
	if (!G.p_banker->list)	cout << "You";
	else cout << "COM" << G.p_banker->list;

	for (auto& i: playerlist) {
		coord.X = 0;	coord.Y = 9*i.list+2;
	 	SetConsoleCursorPosition(ConsoleHandle, coord);
		if (i.list)		cout << "COM" << i.list;
		else cout << "You";
		
		if (&i == G.p_banker)	cout << "		Banker";
		if (!i.money)			cout << "		GAMEOVER";
	}
	
	coord.X = 0;	coord.Y = 38 - 9 * (4 - playerlist.size());
	SetConsoleCursorPosition(ConsoleHandle, coord);
	cout << "=============================================================";
}
void bet(void) {
	for (auto& i : G.p_playlist) {
		if (i == G.p_banker)	continue;
		if (i != &playerlist[0]) 	//	COM 
			i->bets = ((rand()+100) % i->money / 1000 * 100 + 200);
		else {
			eraser();
			coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
			SetConsoleCursorPosition(ConsoleHandle, coord);

			do {
				cout << "What bet do you want to add? (100 < bet < " << playerlist[0].money << "):";
				cin.clear();
				cout << flush;
				cin >> i->bets;
			} while (!(100 <= i->bets && i->bets <= i->money));
		}
		coord.X = 30;	coord.Y = 9 * i->list + 2;
		SetConsoleCursorPosition(ConsoleHandle, coord);
		cout << "Bet = " << i->bets;
	}
}
void addcard(int i_player) {	// i 玩家
	int x;		do { x = (rand() % 52); } while (pokercard[x]);
	pokercard[x] = true;
	playerlist[i_player].card.push_back(x);
	G.addsum(i_player, x % 13 + 1);
}
void distribute(void) {
	for (int i = 0; i < NowPlayer; i++) {
		addcard(G.p_playlist[i]->list);
		showcard(G.p_playlist[i]->list);
	}
}
void insurance(void) {
	for (auto& i : G.p_playlist) {
		if (i == G.p_banker)	continue;
		if (i->money - i->bets < i->bets / 2) {		//	have no more money
			if (i == &playerlist[0]) {
				eraser();
				coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
				SetConsoleCursorPosition(ConsoleHandle, coord);
				cout << "You have no more money to buy insurance.";
			}	
			continue;
		}
		if (i != &playerlist[0]) {
			int x = ((i->sum == 21) ? 0 : (rand() % 3));		// x=0 buy		(1.) if sum == 21, buy		(2.) 1/3 chance to get 10,J,Q,K	
			if (!x) i->insurance = i->bets / 2;
		}
		else {		
			coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
			SetConsoleCursorPosition(ConsoleHandle, coord);
			eraser();
			char choice;
			do {
				cout << "Do you want to buy insurance? (y/n)";
				cin >> choice;
			} while (choice != 'y' && choice != 'n');
			if (choice == 'y')	playerlist[0].insurance = playerlist[0].bets / 2;
		}
	}
	//get money
	for (auto& i : playerlist) {
		if (!i.insurance) continue;
		if ( G.p_banker->sum == 21) {
			if (G.p_banker->money > (2 * i.insurance)) {
				i.money += (2 * i.insurance);
				G.p_banker->money -= (2 * i.insurance);
			}
			else {
				i.money += (G.p_banker->money);
				G.p_banker->money = 0;
			}
		}
		else {
			i.money -= (i.insurance);
			G.p_banker->money += (i.insurance);
		}
		i.insurance = 0;
	}
}
void doublebetprocess(int i_player) {
	playerlist[i_player].bets *= 2;
	addcard(i_player);
	showcard(i_player);
	playerlist[i_player].doublebet = true;
}
void doublebet(void) {
	for (auto& i : G.p_playlist) {
		if (i == G.p_banker || i->sum != 11)		continue;	
		if (i->money < 2 * i->bets) {
			if (i == &playerlist[0]) {
				eraser();
				coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
				SetConsoleCursorPosition(ConsoleHandle, coord);
				cout << "You have no more money to buy insurance.";
			}
			continue;
		}
		if (i != &playerlist[0]) {
			int x = rand() % 3;		//	1 / 3 chance to get 10, J, Q, K
			if (!x)		doublebetprocess(i->list);
		}
		else {
			eraser();
			coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
			SetConsoleCursorPosition(ConsoleHandle, coord);
			char choice;
			do {
				cout << "Do you want to doublebet? (y/n):";
				cin >> choice;
			} while (choice != 'y' && choice != 'n');
			if (choice == 'y')		doublebetprocess(0);
		}
	}
}
void giveupprocess(int i_player) {
	playerlist[i_player].giveup = true;
	playerlist[i_player].money -= playerlist[i_player].bets / 2;
	G.p_banker->money += playerlist[i_player].bets / 2;
	playerlist[i_player].bets = 0;
}
void giveup(void) {
	for (auto& i : G.p_playlist) {
		if (i->doublebet || i == G.p_banker)	continue;
		if (i != &playerlist[0]) {
			int x = rand() % 5;
			if (!x) giveupprocess(i->list);
		}
		else {
			eraser();
			coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
			SetConsoleCursorPosition(ConsoleHandle, coord);
			char choice;
			do {
				cout << "Do you want to give up? (y/n):";
				cin >> choice;
			} while (choice != 'y' && choice != 'n');
			if(choice == 'y')	giveupprocess(i->list);
		}
	}
}
void lastaddcard(void) {
	for (auto& i : G.p_playlist) {
		if (i->doublebet || i->giveup)	continue;
		
		if (i == G.p_banker) 
			while (i->sum < 17 && i->card.size() < 5) {
				addcard(i->list);
				showcard(i->list);
			}		
		else {
			if (i != &playerlist[0]) {
				while (i->card.size() < 5 && i->sum < 21) {
					addcard(i->list);
					showcard(i->list);
					if (i->sum < 11)	continue;
					int x = rand() % 2;
					if (!x)	break;
				}
			}
			else {
				do {
					if (i->card.size() == 5 || i->sum >= 21)	break;
					eraser();
					coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
					SetConsoleCursorPosition(ConsoleHandle, coord);
					char choice;
					do {
						cout << "Do you want to add card? (y/n)";
						cin >> choice;
					} while (choice != 'y' && choice != 'n');
					if (choice == 'y') {
						addcard(i->list);
						showcard(i->list);
					}
					else	break;
				} while (i->sum < 21);
			}

		}
		
	}
}
bool test_678(int i_player) {
	for (int i = 6; i <= 8; i++) {
		bool a = false;
		for (int j : playerlist[i_player].card)		if (j == i)	a = true;
		if (!a)	return false;
	}
	return true;
}
void showmoney(void) {
	eraser();
	coord.X = 0;	coord.Y = 39 - 9 * (4 - playerlist.size());
	SetConsoleCursorPosition(ConsoleHandle, coord);
	for (auto& i : playerlist) {	
		if (!i.list)	cout << "Your  money: ";
		else			cout << "COM " << i.list << " money: ";
		cout << i.money << endl;
	}
}
void settlement(void) {
	for (auto& i : G.p_playlist) {
		if (i->card.size() == 5 || test_678(i->list))	i->threetimepay = true;
	}
	for (auto& i : G.p_playlist) {
		if (i == G.p_banker)	continue;
		if (G.p_banker->sum > 21) {
			if (i->sum < 21) {
				if (i->threetimepay) {
					if (G.p_banker->money > 3 * i->bets)	 { i->money += 3 * i->bets;				i->point += 3 * i->bets;				G.p_banker->money -= 3 * i->bets;			G.p_banker->point -= 3 * i->bets;			}
					else									 { i->money += G.p_banker->money;		i->point += G.p_banker->money;			G.p_banker->money = 0;						G.p_banker->point -= G.p_banker->money;		}
				}
				else {
					if (G.p_banker->money > i->bets)		 { i->money += i->bets;					i->point += i->bets; 					G.p_banker->money -= i->bets;				G.p_banker->point -= i->bets;				}
					else									 { i->money += G.p_banker->money;		i->point += G.p_banker->money;			G.p_banker->money = 0;						G.p_banker->point -= G.p_banker->money;		}
				}
			}	
		}
		else {
			if(i->sum > 21)									 { i->money -= i->bets;					i->point -= i->bets;					G.p_banker->money += i->bets;				G.p_banker->point += i->bets;				}
			else if (G.p_banker->threetimepay) {
				if(!i->threetimepay)						 { i->money -= i->bets;					i->point -= i->bets;					G.p_banker->money += i->bets;				G.p_banker->point += i->bets;				}
				if (i->threetimepay) {
					if (i->sum > G.p_banker->sum) {
						if (G.p_banker->money > 3 * i->bets) { i->money += 3 * i->bets;				i->point += 3 * i->bets;				G.p_banker->money -= 3 * i->bets;			G.p_banker->point -= 3 * i->bets; }
						else								 { i->money += G.p_banker->money;		i->point += G.p_banker->money;			G.p_banker->money = 0;						G.p_banker->point -= G.p_banker->money; }
					}
					else									 { i->money -= i->bets;					i->point -= i->bets;					G.p_banker->money += i->bets;				G.p_banker->point += i->bets;				}
				}
			}
			else {
				if (i->threetimepay) {
					if (G.p_banker->money > 3 * i->bets)	 { i->money += 3 * i->bets;				i->point += 3 * i->bets;				G.p_banker->money -= 3 * i->bets;			G.p_banker->point -= 3 * i->bets;		    }
					else									 { i->money += G.p_banker->money;		i->point += G.p_banker->money;			G.p_banker->money = 0;						G.p_banker->point -= G.p_banker->money;     }
				}
				else {
					if(i->sum > G.p_banker->sum) {
						if (G.p_banker->money > i->bets)	{ i->money += i->bets;					i->point += i->bets; 					G.p_banker->money -= i->bets;				G.p_banker->point -= i->bets;				}
						else								{ i->money += G.p_banker->money;		i->point += G.p_banker->money;			G.p_banker->money = 0;						G.p_banker->point -= G.p_banker->money;		}
					}
					else									{ i->money -= i->bets;					i->point -= i->bets;					G.p_banker->money += i->bets;				G.p_banker->point += i->bets;				}
				}
			}
		}
	}
	showmoney();
}
void end(void){
	while (G.p_playlist.size())	G.p_playlist.pop_back();
	for (auto& i : playerlist) {
		i.card.clear();
		i.point = 0;
		i.bets = 0;
		i.insurance = 0;
		i.sum = 0;
		i.doublebet = false;
		i.giveup = false;
		i.threetimepay = false;
		i.cardS = 0;
	}
	for (auto& i : pokercard)	i = false;
}
void showwinner(void) {
	system("cls");
	cout << "The end of game" << endl << endl;
	for (auto& i : playerlist) {
		if (!i.list)	cout << "Your  money: ";
		else			cout << "COM " << i.list << " money: ";
		cout << i.money << endl;
	}
	cout << endl << "The winner is ";
	player a = playerlist[0];
	for (auto& i : playerlist) 
		if (a.money < i.money)	a = i;
	if (!a.list)	cout << "You win.";
	else	cout << "COM" << a.list << " win." << endl << endl;
}
//	Game Program-------------------------------------------------------------
void Newgame(void) {
	cout << "Black Jack" << endl;
	int time;
	do {
		cout << "How many time do you want to play? (0 <= time <= 5):";
		cin >> time;
	} while (!(0 < time && time <= 5));
	int inp_comnum;
	do {
		cout << "How many COM do you want to play with? (1 <= COM <= 3):";
		cin >> inp_comnum;
	} while (!(1 <= inp_comnum && inp_comnum <= 3));
	G.setplayer(inp_comnum);
	for (int i = 0; i < time; i++) {
		system("cls");
		G.setplaylist();
		showgametable(i);
		bet();
		distribute();
		distribute();
		if(G.p_banker->card[0] % 13 + 1 == 1)	insurance();
		doublebet();
		giveup();
		lastaddcard();
		settlement();
		cin.ignore();
		cout << "press enter ....";
		char   cc = getchar();
		G.setbanker();
		end();
	}
	showwinner();
}
//	class player-----------------------------------------------------------------------
player::player(int i) {
	list = i;
	money = 10000;
	point = 0;
	bets = 0;
	insurance = 0;
	sum = 0;
	doublebet = false;
	giveup = false;
	threetimepay = false;
	cardS = 0;
}
//	class game--------------------------------------------------------------------------
void game::setplayer(int num) {
	comnum = num;
	for (int i = 0; i < TotalPlayer; i++) 
		playerlist.push_back(player(i));
	p_banker = &playerlist[rand() % TotalPlayer];
}
void game::setplaylist(void) {
	for (int i = 0; i < TotalPlayer; i++) {
		if ((&playerlist[i] != G.p_banker) && (playerlist[i].money))
			p_playlist.push_back(&playerlist[i]);
	}
	p_playlist.push_back(G.p_banker);
}
void game::setbanker() {
	player* x = &playerlist[0];
	for (auto& i : playerlist) {
		if (!i.money)	continue;
		if (i.point > x->point)	x = &i;
		else if (i.point == x->point)	x = (x->money < i.money ? x : &i);
	}
	G.p_banker = x;
}
void game::addsum(int i_player, int newnum) {
	if (newnum == 1)	playerlist[i_player].cardS++; 
	playerlist[i_player].sum += (newnum > 9 ? 10 : (newnum == 1 ? 11 : newnum));
	if (playerlist[i_player].sum > 21) {
		if (playerlist[i_player].cardS) {
			playerlist[i_player].cardS--;
			playerlist[i_player].sum -= 10;
		}
	}
}