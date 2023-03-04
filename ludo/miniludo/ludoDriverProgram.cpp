#include "ludo.h"

int main() {
	srand(time(0));
	bool letsPlay = true;
	std::list<Square> board;
	initBoard(board);
	Player players[] = { Player(6, 3, 0, -1), Player(3, 0, -1, 0), Player(0, 3, 0, 1), Player(3, 6, 1, 0) };
	for (int i = 0; i < 4; ++i) {
		std::cout << "Player " << i + 1 << ", represented as " << char('A' + i) << ", enter your name\n";
		std::getline(std::cin, players[i].name);
		std::cout << "Hello " << players[i].name << "!\n";
	}
	while (letsPlay) {
		for (int i = 0; i < 4; ++i) players[i].reset();
		std::list<Square>::iterator posInList[4] = { board.begin(), board.begin(), board.begin(), board.begin() };
		int dice;
		int turn = 0;
		printBoard(players);
		int numWinners = 0;
		do {
			if (players[turn].currentX == 3 && players[turn].currentY == 3) {
				turn = (turn + 1) % 4;
				continue;
			}
			std::cout << players[turn].name << "'s turn. Roll the dice! (press enter)\n";
			std::cin.ignore();
			dice = 1 + rand() % 4;
			std::cout << "You rolled a " << dice << '\n';
			
		
			move(posInList[turn], players[turn], board.end(), dice, turn);
			for (int i = 1; i < 4; ++i) {
				if (checkPwnage(players[turn], players[(turn + i) % 4], posInList[turn]->safe)) {
					players[(turn + i) % 4].reset();
					posInList[(turn + i) % 4] = board.begin();
					std::cout << players[(turn+i)%4].name << " got pwned!\nBack you go!\n";
				}
			}
			if (players[turn].currentX == 3 && players[turn].currentY == 3) {
				if (numWinners == 0) {
					std::cout << players[turn].name << " is the winner!";
				}
				else if (numWinners == 1) {
					std::cout << players[turn].name << " takes second place!";
				}
				else if (numWinners == 2) {
					std::cout << players[turn].name << " squeezes in third place!";
				}
				else {
					std::cout << "Better luck next time, " << players[turn].name << '\n';
					break;
				}
				++numWinners;
				std::cout << '\n';
			}
			printBoard(players);
			turn = (turn + 1) % 4;
		} while (numWinners < 4);
		printBoard(players);		
		char ch;
		do {
			std::cout << "Play again? y/n ";
			std::cin >> ch;
		} while (ch != 'y' && ch != 'n');
		if (ch == 'n') letsPlay = false;
	} 

}





