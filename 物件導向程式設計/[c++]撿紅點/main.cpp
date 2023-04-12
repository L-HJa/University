#include"Poker_Red.h"

int peo_round[] = { 0, 0, 12, 8, 6 };
list<player> l_player;
list<card> l_sea;


int main() {
	SetConsoleOutputCP(65001);

	int n_player, n_com;
	cout << "please input player numbers and com numbers." << endl;
	cout << "player: ";		cin >> n_player;
	cout << "com: ";		cin >> n_com;
	int t_player = n_player + n_com;

	system("cls");

	
	srand(time(NULL));
	for (int i = 0; i < t_player; i++) {
		list<card> vc;
		for (int j = 0; j < peo_round[t_player]; j++) {
			card ca = getcard();
			vc.push_back(ca);
		}
		l_player.push_back(player(vc, 0));
	}

	for (int k = 0; k < 4; k++) {
		card ca = getcard();
		l_sea.push_back(ca);
	}


	for (int round = 1; round <= peo_round[t_player]; round++) {
		system("cls");
		showboard();
		for (list<player>::iterator it = l_player.begin(); it != l_player.end(); it++) {
			cout << "Round " << round << "		player" << distance(l_player.begin(), it)+1 << endl;
			if (distance(l_player.begin(), it) < n_player) {
				char color; int num; list<card>::iterator i_exe_card; card exe_card;
				
				int flag = 0;
				do {
					cout << ((!flag) ? "Which card do you want to execute?" : "You do not have this card.\nWhich card do you want to execute?");
					cin >> color >> num;
					exe_card = card(color, num);
					i_exe_card = find(it->cards.begin(), it->cards.end(), exe_card);
					flag = 1;
				} while (i_exe_card == it->cards.end());

				vector<list<card>::iterator> i_vic;
				for (list<card>::iterator i = l_sea.begin(); i != l_sea.end(); i++) 
					if ((i->number + num == 10) || (num >= 10) && (i->number == num))
						i_vic.push_back(i);
				
				list<card>::iterator sea_it;
				if (i_vic.size()) {
					if (i_vic.size() > 1) {
						for(int j = 0; j < i_vic.size(); j++)
							cout << j+1 << ".	" << i_vic[j]->color << i_vic[j]->number << endl;
						cout << endl << "Which card do you want to choose?(please input 1 or 2 or....) ";
						cin >> num;
						sea_it = i_vic[num - 1];
					}
					else {
						sea_it = i_vic[0];
					}
					it->score += count_score(exe_card, *sea_it);
					l_sea.erase(sea_it);
					it->cards.erase(i_exe_card);
					l_sea.push_back(getcard());
				}
				else {
					l_sea.push_back(exe_card);
					it->cards.erase(i_exe_card);
				}
			}
			else {
				vector<card> vc = check(it->cards);
				cout << "Which card do you want to execute?";
				it->score += (vc.size() == 0 ? diposal(it->cards) : (pick(vc, it->cards)));
				Sleep(5000);
			}
			system("cls");
			showboard();
		}
	}

	showend();

	system("pause");
	return 0;
}