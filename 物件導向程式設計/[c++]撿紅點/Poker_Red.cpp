#include"Poker_Red.h"

bool exist_cards[52] = { false };
char cha_color[] = { 'S', 'H', 'D', 'C' };
int i_c_color(char c) {
	if (c == 'S')	return 0;
	if (c == 'H')	return 1;
	if (c == 'D')	return 2;
	if (c == 'C')	return 3;
}

vector<card> check(list<card> it) {
	vector<card> r_lc;
	for (auto i : it) 
		for (auto j : l_sea) 
			if ((i.number + j.number == 10) || (i.number >= 10 && i.number == j.number)) {
				r_lc.push_back(i);
				break;
			}
	return r_lc;
}
int pick(vector<card> l_c, list<card>& it) {
	list<card>::iterator i_exe, i_sea;
	card c;
	int score = 0;
	for (auto i : l_c) {
		vector<list<card>::iterator> i_vic;
		for (list<card>::iterator j = l_sea.begin(); j != l_sea.end(); j++)
			if ((i.number + j->number == 10) || (i.number >= 10 && i.number == j->number))
				if (count_score(i, *j) >= score) {
					c = i;
					i_sea = j;
					score = count_score(i, *j);
				}
	}
	i_exe = find(it.begin(), it.end(), c);
	cout << c.color << c.number << endl;
	it.erase(i_exe);
	l_sea.erase(i_sea);
	l_sea.push_back(getcard());
	return score;
}
int diposal(list<card>& it) {
	card c = *(it.begin());
	for (auto i : it) 
		if (i.number <= c.number && (i.color == 'S' || i.color == 'C'))
			c = i;
	list<card>::iterator i_exe = find(it.begin(), it.end(), c);
	cout << c.color << c.number << endl;
	it.erase(i_exe);
	l_sea.push_back(c);
	return 0;
}


card getcard(void) {
	int x = 0;
	do {
		x = rand() % 52;
	} while (exist_cards[x]);
	exist_cards[x] = true;
	return card(cha_color[x / 13], x % 13 + 1);
}


bool card::operator==(const card& c) {
	return  (this->number == c.number && this->color == c.color);
}
void card::getcard(char c, int n) {
	color = c;
	number = n;
}


void player::operator-(const card& out) {
	list<card>::iterator it = find(cards.begin(), cards.end(), out);
	this->cards.erase(it);
}


int count_score(const card exe_card, const card sea_it) {
	int score = 0;

	if (exe_card.color == 'H' || exe_card.color == 'D') {
		if (exe_card.number == 1)	score += 20;
		else if (exe_card.number == 9 || exe_card.number == 10 || exe_card.number == 11 || exe_card.number == 12 || exe_card.number == 13)	score += 10;
		else	score += exe_card.number;
	}
	else if (exe_card.color == 'S' && exe_card.number == 1)	score += 10;

	if (sea_it.color == 'H' || sea_it.color == 'D') {
		if (sea_it.number == 1)	score += 20;
		else if (sea_it.number == 9 || sea_it.number == 10 || sea_it.number == 11 || sea_it.number == 12 || sea_it.number == 13)	score += 10;
		else	score += sea_it.number;
	}
	else if (sea_it.color == 'S' && sea_it.number == 1)	score += 10;

	return score;
}


//---------------------------------------------------------------------------------------
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
	NULL, set_1, set_2, set_3, set_4, set_5, set_6, set_7, set_8, set_9, set_10, set_11, set_12, set_13
};

string SS = "\342\231\240", HH = "\342\231\245", DD = "\342\231\246", CC = "\342\231\243"; // (0xe2, 0x99, 0xa0), (0xe2, 0x99, 0xa5), (0xe2, 0x99, 0xa6), (0xe2, 0x99, 0xa3);
string Q1 = "\342\225\224", W1 = "\342\225\227", A1 = "\342\225\232", S1 = "\342\225\235", Z1 = "\342\225\220", X1 = "\342\225\221";

string ary_Color[] =
{
	"\342\231\240", "\342\231\245", "\342\231\246", "\342\231\243"
};

void showcard(int x, int y, card ca)
{
	int color = i_c_color(ca.color), number = ca.number;
	static COORD coord;
	coord.X = (x >= 90 ? x - 90 : x);
	coord.Y = (x >= 90 ? y + 8 : y);
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//獲取控制台緩衝區句柄
	SetConsoleCursorPosition(ConsoleHandle, coord);//設置光標位置


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
	cout << endl;
}

pos cout_pos[][5] = { {pos(0,3), pos(0, 14), pos(0, 25), pos(0, 36), pos(0, 47)}, {pos(0, 3), pos(0, 22), pos(0, 41), pos(0, 60), pos(0, 79)} };

void showboard(void) {
	showtitle();
	int d_player = 0, d_card = 0;
	for (auto i : l_player) {
		d_card = 0;
		for (auto j : i.cards) {
			showcard(cout_pos[(--l_player.end())->cards.size() > 6][d_player].x + d_card * 15, cout_pos[(--l_player.end())->cards.size() > 6][d_player].y, j);
			d_card++;
		}
		d_player++;
	}

	d_card = 0;
	for (auto k : l_sea) {
		showcard(cout_pos[(--l_player.end())->cards.size() > 6][d_player].x + d_card * 15, cout_pos[(--l_player.end())->cards.size() > 6][d_player].y, k);
		d_card++;
	}
}

pos cout_title[][5] = { {pos(0,0), pos(0, 11), pos(0, 22), pos(0, 33), pos(0, 44)}, {pos(0, 0), pos(0, 19), pos(0, 38), pos(0, 57), pos(0, 76)} };
void showtitle(void) {
	static COORD coord;
	int d_player = 0, d_card = 0;
	int dis_p = 0;
	for (auto i : l_player) {
		coord.X = 0;
		coord.Y = cout_title[(--l_player.end())->cards.size() > 6][dis_p].y;
		HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	
		SetConsoleCursorPosition(ConsoleHandle, coord);
		dis_p++;
		cout << "---------------------------------------------------------------------------" << endl << "player" << dis_p << "		score : " << i.score;
	}

	coord.X = 0;
	coord.Y = cout_title[(--l_player.end())->cards.size() > 6][dis_p].y;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(ConsoleHandle, coord);
	cout << endl << "---------------------------------------------------------------------------" << endl << "sea cards";
}

void showend(void) {
	system("cls");
	int n_player = 0, score = 0;
	vector<int> winner;
	for (auto i : l_player) {
		n_player++;
		cout << "player" << n_player << "'s score is " << i.score << endl;
		if (i.score == score)	winner.push_back(n_player);
		else if (i.score > score) { winner.clear();		winner.push_back(n_player);		score = i.score; }
	}
	cout << endl << endl << "The winner is ";
	for (vector<int>::iterator i = winner.begin(); i != winner.end(); i++) {
		cout << "player" << *i;
		cout << ((i == (winner.end()-1)) ? " " : " & ");
	}
	cout << endl << endl;
}